#include"func.h"
int upload_file(int sfd,char *file_name)
{
	int file_len = strlen(file_name);
	send(sfd,&file_len,sizeof(int),0);   //发送文件名长度
	send_n(sfd,file_name,file_len);      //发送文件名
	int fd = open(file_name,O_RDONLY);
	if(-1==fd)
	{
		perror("open");
		return -1;
	}
	data d;
	while(bzero(&d,sizeof(d)),(d.len=read(fd,d.buf,sizeof(d.buf)))>0)
	{
		send(sfd,&d.len,sizeof(int),0);
		send_n(sfd,d.buf,d.len);
	}
	close(fd);
	return 0;
}
