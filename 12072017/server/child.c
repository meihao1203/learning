#include"func.h"
void child_word(int fds)
{
	int new_fd;
	int flag = 1;
	while(1)
	{
		//printf("wait read new_fd\n");
		read_fd(fds,&new_fd);  //子进程等待接收main进程发送过来的客户端链接请求产生的newfd;
		//sendfile(new_fd);  //用newfd发送文件给客户端；
		child_handle(new_fd);
		printf("child_handle\n");
		write(fds,&flag,sizeof(int));  //文件发送完毕通过管道给main进程发送一个数据，触发epoll_wait，关闭new_fd,重置子进程状态；
	}
}
void make_child(pchild p,int num)
{
	int fds[2];
	int ret;
	pid_t pid;
	for(int i=0;i<num;i++)
	{
		ret = socketpair(AF_LOCAL,SOCK_STREAM,0,fds);
		if(-1==ret)
		{
			perror("socketpair");
			return ;
		}
		pid = fork();
		if( 0==pid )
		{
			close(fds[1]);
			child_word(fds[0]);
		}
		close(fds[0]);
		p[i].fds = fds[1];
		p[i].pid = pid;
		p[i].status = 0;//刚创建好，待命状态，非忙碌，status=0;
	}
}
