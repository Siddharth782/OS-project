#include "types.h"
#include "stat.h"
#include "user.h"
#include "param.h"

int main()
{
    int pid = fork();
    struct uproc *up = malloc(sizeof(struct uproc));
    char *pstate = " ";

    if (pid == 0)
    {
        for (int i = 0; i < NPROC; i++)
        {
            if (getprocinfo(i, up) == -1)
            {
                continue;
            }

            // process id
            printf(1, "The process id is %d\n", up->pid);

            // parent process id
            printf(1, "The parent process id is %d\n", up->ppid);

            // size of process
            printf(1, "The process size is %d bytes\n", up->size);

            // process state
            switch (up->state)
            {
            case 0:
                pstate = "UNUSED";
                break;
            case 1:
                pstate = "EMBRYO";
                break;
            case 2:
                pstate = "SLEEPING";
                break;
            case 3:
                pstate = "RUNNABLE";
                break;
            case 4:
                pstate = "RUNNING";
                break;
            case 5:
                pstate = "ZOMBIE";
                break;
            }
            printf(1, "The process state is %s\n", pstate);

            // if the process is killed
            if (up->killed)
            {
                printf(1, "The process is killed\n");
            }
            else
            {
                printf(1, "The process is not killed\n");
            }

            // if the process is waiting on a channel

            if (up->channel == -1)
            {
                printf(1, "The process is not waiting on a channel\n");
            }
            else
            {
                printf(1, "The process is waiting on a channel\n");
            }

            printf(1, "\n");
        }
    }

    wait();
    exit();
}