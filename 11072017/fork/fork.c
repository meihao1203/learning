#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
        pid_t pid;
        int i=3;
        pid=fork();
        if(pid==0)
        {
                i++;
                printf("I am child,my pid=%d,my ppid=%d\n",getpid(),getppid());
                exit(0);
        }
        else
        {
                printf("i=%d\n",i);
                printf("child pid=%d\n",pid);
                exit(0);
        }
        return 0;
}