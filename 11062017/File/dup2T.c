#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
int main()
{
        int fd = open("a.txt", O_WRONLY | O_CREAT);
        if(fd == -1)
        {
                perror("open error");
                exit(-1);
        }
                printf("\n");
        close(1);
        int fd2 = dup(fd);  
        close(fd);
        printf("hello world\n");
                close(fd2);
        return 0;
}
