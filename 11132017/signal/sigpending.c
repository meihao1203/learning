#include<signal.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
        sigset_t set;
        sigemptyset(&set);
        sigaddset(&set,SIGINT);
        int ret ;
        ret=sigprocmask(SIG_BLOCK,&set,NULL);
        if(-1==ret)
        {
                perror("sigprocmask");
                return -1;
        }
        sleep(5);
        sigemptyset(&set);        
        ret =sigpending(&set);    
		ret = sigismember(&set,SIGINT);
		if(1==ret)
		{
			printf("SIGINT is in the set\n");
		}
		if(0==ret)
		{
			printf("SIGINT is not in the set\n");
		}
        return 0;
}