#include"func.h"
int main(int argc,char **argv)
{	
	if(2!=argc)
	{
		printf("error argcs\n");
		return -1;
	}
	char ip[32];
	char port[32];
	file_read_arg(argv[1],ip,port);  //从配置文件中读取服务器ip地址和端口
	int sfd = socket(AF_INET,SOCK_STREAM,0);
	if(-1==sfd)
	{
		perror("socket");
		return -1;
	}
	struct sockaddr_in ser;
	bzero(&ser,sizeof(ser));
	ser.sin_port = htons(atoi(port));
	ser.sin_addr.s_addr = inet_addr(ip);
	ser.sin_family = AF_INET;
	int ret = bind(sfd,(struct sockaddr*)&ser,sizeof(ser));
	if(-1==ret)
	{
		perror("bind");
		return -1;
	}
	int num = 5;
	ret = listen(sfd,num);
	if(-1==ret)
	{
		perror("listen");
		return -1;
	}
	//注册描述符，sfd和创建好的子进程对应的父进程端的管道
	int epfd  = epoll_create(1);
	if(-1==epfd)
	{
		perror("epoll_create");
		return -1;
	}
	struct epoll_event eve,eves[num+1];  //num个连接到子进程的管道和一个sfd
	bzero(&eve,sizeof(eve));
	eve.events = EPOLLIN;
	eve.data.fd = sfd;
	ret = epoll_ctl(epfd,EPOLL_CTL_ADD,sfd,&eve);
	if(-1==ret)
	{
		perror("epoll_ctl");
		return -1;
	}
	//创建子进程
	pchild p = (pchild)calloc(num,sizeof(child));
	make_child(p,num);
	for(int i=0;i<num;i++)
	{
		bzero(&eve,sizeof(eve));
		eve.events = EPOLLIN;
		eve.data.fd = p[i].fds;
		epoll_ctl(epfd,EPOLL_CTL_ADD,p[i].fds,&eve);
	}
	int new_fd;
	int flag;
	int j = 0;
	int i;
	while(1)
	{
		memset(eves,0,(num+1)*sizeof(eve));
		ret = epoll_wait(epfd,eves,num+1,-1);
		if(ret>0)
		{
			for(i=0;i<ret;i++)
			{
				if(eves[i].data.fd == sfd)
				{
					new_fd = accept(sfd,NULL,NULL);
					for(j=0;j<num;j++)
					{
						if(p[j].status == 0)
						{
							break;
						}
					}
					send_fd(p[j].fds,new_fd);
					p[j].status = 1;
					close(new_fd);  //new_fd已经发送给空闲子进程，main进程不在需要new_fd
				}
				for(j=0;j<num;j++)
				{
					if(eves[i].data.fd == p[j].fds)
					{
						read(p[j].fds,&flag,sizeof(int));
						p[j].status = 0;
					}
				}
			}
		}
	}
	return 0;
}