#include <stdio.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <assert.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>

#define SERVER_PROGNAME "mipt_httpd"
#define TCP_BUFSIZE     10000
#define TCP_CLIENTS_N   10

/*
 *
 * HTTP/1.1 400 Bad Request
Server: nginx
Date: Wed, 03 Jun 2015 21:46:09 GMT
Content-Type: text/html; charset=utf-8
Content-Length: 166
Connection: close
 *
 * */

char *http_404_file_not_found = "HTTP/1.1 404 File Not Found\nContent-Type: text/html\nContent-Length: 9\nConnection: close\n\nNot Found\n";
char *http_200_ok = "HTTP/1.1 200 OK\nContent-Type: text/html\nConnection: close\n";

void program_error(char* msg)
{
    fprintf(stderr, "Error: %s\n", msg);
    syslog(LOG_NOTICE, "Error: %s", msg);
    exit(1);
}

char file_buf[TCP_BUFSIZE];

void process_request(uint8_t* buf, ssize_t len, int fd)
{
    if(len >= 4 && !strncmp((char*) buf, "GET ", 4))
    {
        char* path = ((char*) buf) + 4;
        char* t_str = strstr(path, " HTTP/1.1");
        if(!t_str)
            return;
        *t_str = 0;
        FILE* f = fopen(path, "r");

        fprintf(stderr, "filename_req=%s\n", path);

        if(f == NULL)
        {
            fprintf(stderr, "not found\n");
            send(fd, http_404_file_not_found, strlen(http_404_file_not_found), 0);
        }
        else
        {
            fprintf(stderr, "found\n");
            int len = fread(file_buf, 1, TCP_BUFSIZE, f);
            send(fd, http_200_ok, strlen(http_200_ok), 0);
            char length[TCP_BUFSIZE];
            sprintf(length, "Content-Length: %d\n\n", len);
            fprintf(stderr, "len=%d\n", len);
            send(fd, length, strlen(length), 0);
            send(fd, file_buf, len - 1, 0);
            fclose(f);
        }
    }
}

int main(int argc, char** argv)
{
    openlog(SERVER_PROGNAME, 0, LOG_USER);

    int listen_port = 80;

    int nport = htons((u_short) listen_port);
    int server_socket, client_socket;
    if((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        program_error("Can't get socket");
        return(-1);
    }

    struct sockaddr_in server_address, client_address;

    bzero(&server_address, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = nport;

    if(bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address)) == -1)
    {
        program_error("Can't bind");
        return(-1);
    }

    if(listen(server_socket, TCP_CLIENTS_N) == -1)
    {
        program_error("Can't listen!");
        return(-1);
    }

    const int addrLen = sizeof(client_address);

    uint8_t buf[TCP_BUFSIZE];
    ssize_t len;

    unsigned i;

    syslog(LOG_NOTICE, "Started");

    for(i = 1; ; i++)
    {
        bzero(&client_address, addrLen);
        if((client_socket = accept(server_socket, (struct sockaddr *) &client_address,
                                   (socklen_t*) (&addrLen))) == -1)
        {
            program_error("Can't accept");
            return(-1);
        }

        pid_t client_pid = fork();

        if(!client_pid)
        {
            close(server_socket);

            len = recv(client_socket, &buf, TCP_BUFSIZE, 0);

            write(1, buf, len);

            process_request(buf, len, client_socket);

            syslog(LOG_NOTICE, "client id=%d dead\n", i);
            close(client_socket);
            exit(0);
        }
        else
            syslog(LOG_NOTICE, "Accepted client %s id=%d pid=%d\n", inet_ntoa(client_address.sin_addr), i, client_pid);

        close(client_socket);
        //break;
    }

    close(server_socket);

    return(0);
}
