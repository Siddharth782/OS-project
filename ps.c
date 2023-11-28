#include "types.h"
#include "stat.h"
#include "user.h"

int main()
{
    int pid = fork();
    if (pid == 0)
    {
        getprocinfo();
    }
    exit();
}