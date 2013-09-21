#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <fcntl.h>
#include <netdb.h>

/* Номер порта, который обслуживается сервером */
#define PORTNUM 1500

main(argc, argv)
int argc;
char *argv[];
{
  int s, ns;
  int pid;
  int nport;
  struct sockaddr_in serv_addr, clnt_addr;
  struct hostent *hp;
  char buf[80], hname[80];
  /* Преобразуем порядок следования байтов к сетевому формату */
  nport = PORTNUM;
  nport = htons((u_short)nport);

  /* Создадим сокет, использующий протокол TCP */
  if((s = socket(AF_INET, SOCK_STREAM, 0)) == -1){
    perror("Ошибка вызова socket()!\n"); exit(-1);
  }

  /* Зададим адрес коммуникационного узла */
  bzero(&serv_addr, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = INADDR_ANY;
  serv_addr.sin_port = nport;

  /* Свяжем сокет с этим адресом */
  if(bind(s, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1){
    perror("Ошибка вызова bind()!\n"); exit(-1);
  }

  /* Выведем сообщение с указанием адреса сервера */
  fprintf(stderr, "Сервер готов: %s\n", inet_ntoa(serv_addr.sin_addr));

  /* Сервер готов принимать запросы на установление соединения.
     Максимальное число запросов, ожидающих обработки - 5.
     Как правило, этого числа достаточно, чтобы успеть выполнить
     accept(2) и породить дочерний процесс */
  if(listen(s, 5) == -1){
    perror("Ошибка вызова listen()!\n"); exit(-1);
  }

  /* Бесконечный цикл получения запросов и их обработки */
  while(1){
    int addrlen;

    bzero(&clnt_addr, sizeof(clnt_addr));
    addrlen = sizeof(clnt_addr);

    /* Примем запрос. Новый сокет ns становится коммуникационным
       узлом созданного виртуального канала */
    if((ns = accept(s, (struct sockaddr *)&clnt_addr, &addrlen)) == -1){
      perror("Ошибка вызова accept()!\n"); exit(-1);
    }
    /* Выведем информацию о клиенте */
    fprintf(stderr, "Клиент = %s\n", inet_ntoa(clnt_addr.sin_addr));
    /* Создадим процесс для работы с клиентом */
    if((pid = fork()) == -1){
      perror("Ошибка вызова fork()!\n"); exit(-1);
    }
    if(pid == 0){
      int nbytes;
      int fout;
      /* Дочерний процесс: этот сокет нам не нужен.
         Он по-прежнему используется для получения запросов. */
      close(s);
      /*  Получим сообщение от клиента и передадим его обратно */
      while((nbytes = recv(ns, buf, sizeof(buf), 0)) != 0){
        send(ns, buf, sizeof(buf), 0);
      }
      close(ns);
      exit(0);
    }
    /* Родительский процесс: этот сокет нам не нужен.
       Он используется дочерним процессом для обмена данными. */
    close(ns);
  }
}