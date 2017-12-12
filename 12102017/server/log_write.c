#include"func.h"
void log_write(int log_fd,char *log_buf)
{
	time_t t;
	time(&t);
	char *str = ctime(&t);
	char div[100] = "----------------------------------------------------------\n";
	//semop(semid,&sp,1);
	write(log_fd,str,strlen(str));
	write(log_fd,log_buf,strlen(log_buf));
	write(log_fd,div,strlen(div));
	//semop(semid,&sv,1);
}
