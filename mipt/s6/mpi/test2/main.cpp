#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// maximum time
// segfault if >
#define TMAX 80

// number of tasks
#define TASKS 30

// time to get data from worker to master
// filled in later
int recv_time = 0;

// time to get data from master to worker
// filled in later
int send_time = 0;

// tasks states

// state diagram:
// WAITING -> SENDING -> RUNNING -> WAITING_RECEIVE -> RECEIVING -> DONE
enum state_ {WAITING, SENDING, RUNNING, WAITING_RECEIVE, RECEIVING, DONE, STATE_N};

// names of states
const char* state_names[STATE_N] = {".", "S", "R", "x", "X", "."};

// states of tasks on current time
int states[TASKS];

// time of last state change for each task
int last_state_change_time[TASKS];

// length (time of execution) of each task
int task_len[TASKS];

// structure containing one cell of the schedule table
struct table_cell
{
    // which state?
    int state;
    // (for master) with whom communicating
    int peer;
};

// resulting schedule table
table_cell arr[TASKS + 1][TMAX];


// print tasks length
void print_info()
{
    printf("Tasks length: ");
    for(int i = 0; i < TASKS; i++)
        printf("%d ", task_len[i]);

    printf("\nsend_time=%d recv_time=%d\n", send_time, recv_time);
}

// count tasks with specific state
int count(int state)
{
    int res = 0;
    for(int i = 0; i < TASKS; i++)
        if(states[i] == state)
            res++;
    return(res);
}

int main(int argc, char** argv)
{
    if(argc < 3)
    {
        printf("Usage: %s send_time recv_time\n", argv[0]);
        exit(-1);
    }

    // filling send & recv time
    send_time = atoi(argv[1]);
    recv_time = atoi(argv[2]);

    /// number of done tasks for time
    int done_tasks = 0;

    // time in system
    int time = 0;

    // filling in tasks length {30, 10, 10, ..., 10}
    task_len[0] = 30;
    for(int i = 1; i < TASKS; i++)
        task_len[i] = 10;

    // print settings
    print_info();

    // initializing tasks
    for(int i = 0; i < TASKS; i++)
    {
        states[i] = WAITING;
        last_state_change_time[i] = 0;
    }

    // initializing answer
    bzero(arr, sizeof(arr));

    // when does the master gets free from ongoing send/receive operation?
    int zero_free_time = 0;

    while(done_tasks < TASKS)
    {
        // time step [time]
     
        // done tasks for this time
        int done_tasks_t = 0;

        for(int i = 0; i < TASKS; i++)
        {
            // WAITING->SENDING if master is free
            if(states[i] == WAITING && zero_free_time <= time)
            {
                states[i] = SENDING;
                last_state_change_time[i] = time;
                zero_free_time = time + send_time;
                printf("TIME %d task %d is now SENDING transmission stops at %d\n", time, i, zero_free_time);
            }

            // SENDING->RUNNING if send is complete
            if(states[i] == SENDING)
            {
                if(time - last_state_change_time[i] >= send_time)
                {
                    last_state_change_time[i] = time;
                    states[i] = RUNNING;
                    printf("TIME %d task %d is now RUNNING finishing at %d\n", time, i, time + task_len[i]);
                }
                else
                {
                    arr[0][time].state = SENDING;
                    arr[0][time].peer = i;
                }
            }

            // RUNNING->WAITING_RECEIVE if task is complete
            if(states[i] == RUNNING)
            {
                if(time - last_state_change_time[i] >= task_len[i])
                {
                    last_state_change_time[i] = time;
                    states[i] = WAITING_RECEIVE;
                    printf("TIME %d task %d is WAITING_RECEIVE\n", time, i);
                }
            }

            // WAITING_RECEIVE->RECEIVING if master is free AND if
            // receive time is zero
            // or we have sent all tasks
            // so NOT starting to receive tasks until we sent all of them
            if(states[i] == WAITING_RECEIVE && zero_free_time <= time && (recv_time == 0 || count(WAITING) == 0))
            {
                states[i] = RECEIVING;
                last_state_change_time[i] = time;
                zero_free_time = time + recv_time;
                printf("TIME %d task %d is now RECEIVING transmission stops at %d\n", time, i, zero_free_time);
            }

            // RECEIVING->DONE if recv is complete
            if(states[i] == RECEIVING)
            {
                if(time - last_state_change_time[i] >= recv_time)
                {
                    last_state_change_time[i] = time;
                    states[i] = DONE;
                    printf("TIME %d task %d is DONE\n", time, i);
                }
                else
                {
                    arr[0][time].state = RECEIVING;
                    arr[0][time].peer = i;
                }
            }

            // incrementing done tasks counter
            if(states[i] == DONE)
                done_tasks_t++;

            arr[i + 1][time].state = states[i];
            arr[i + 1][time].peer = -1;
        }
   
        done_tasks = done_tasks_t;
        time++;
    }

    // printing the schedule
    for(int j = 0; j < TMAX; j++)
    {
        table_cell c = arr[0][j];
        printf("%s", state_names[c.state]);
    }
    printf("\n");

    for(int i = 1; i <= TASKS; i++)
    {
        for(int j = 0; j < TMAX; j++)
        {
            table_cell c = arr[i][j];
            printf("%s", state_names[c.state]);
        }
        printf("\n");
    }

    // calculating T1, Tp, Sp, Ep
    int T1 = 0;
    int Tp = time - 1;

    for(int i = 0; i < TASKS; i++)
        T1 += task_len[i];

    double Sp = 1. * T1 / Tp;
    double Ep = Sp / TASKS;

    printf("T1 = %d, Tp = %d, Sp = %lf, Ep=%lf\n", T1, Tp, Sp, Ep);
}
