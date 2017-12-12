#include"func.h"
int is_file_exist(char *filename)
{
	char *pwd = getcwd(NULL,0);
	DIR *dir = opendir(pwd);
	if(NULL==dir)
	{
		perror("opendir");
		return -1;  //means fail
	}
	struct dirent *q = NULL;
	while((q=readdir(dir))!=NULL)
	{
		if(strcmp(q->d_name,filename)==0)
		{
			return 0;
		}
	}
	return -1;
}
int recv_file(int socket_fd)
{
	char file_name[256] = {0};
	int file_len;
	recv_n(socket_fd,(char*)&file_len,sizeof(int));
	recv_n(socket_fd,file_name,file_len);
	int fd = open(file_name,O_CREAT|O_WRONLY,0666);
	if(-1==fd)
	{
		perror("open");
		printf("file \"%s\" recv fail!\n",file_name);
		return -1;
	}
	data d;
	while(1)
	{
		bzero(&d,sizeof(d));
		recv_n(socket_fd,(char *)&d.len,sizeof(int));
		if(0==d.len)  //接收到对面发送的0就表示对端文件发送完毕了
		{
			break;
		}
		recv_n(socket_fd,d.buf,d.len);
		write(fd,d.buf,d.len);
	}
	printf("file \"%s\" recv success!\n",file_name);
	close(fd);
	return 0;
}
int send_file(int scoket_fd,char *file_name)
{
	int file_len = strlen(file_name);
	send(scoket_fd,&file_len,sizeof(int),0);   //发送文件名长度
	send_n(scoket_fd,file_name,file_len);      //发送文件名
	int fd = open(file_name,O_RDONLY);
	if(-1==fd)
	{
		perror("open");
		printf("send %s fail!\n",file_name);
		return -1;
	}
	data d;
	while(bzero(&d,sizeof(d)),(d.len=read(fd,d.buf,sizeof(d.buf)))>0)
	{
		send_n(scoket_fd,(char*)&d.len,sizeof(int));
		send_n(scoket_fd,d.buf,d.len);
	}
	int endflag = 0;
	send_n(scoket_fd,(char *)&d.len,sizeof(int));  //文件发送完了就发送一个0，对面读到就知道 这边文件已经发送结束
	printf("send %s success!\n",file_name);
	close(fd);
	return 0;
}