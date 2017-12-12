#include"func.h"
#define NUM 10
//epoll模型实现多路复用
int main(int argc,char **argv)
{
		if(3!=argc)
		{
				printf("error args\n");
				return -1;
		}
		int sfd = socket(AF_INET,SOCK_STREAM,0);
		if(-1==sfd)
		{	
				perror("socket");
				return -1;
		}
		struct sockaddr_in ser;
		bzero(&ser,sizeof(struct sockaddr));
		ser.sin_family = AF_INET;
		ser.sin_port = htons(atoi(argv[2]));
		ser.sin_addr.s_addr = inet_addr(argv[1]);
		int ret = bind(sfd,(struct sockaddr *)&ser,sizeof(struct sockaddr_in));
		if(-1==ret)
		{
				perror("bind");
				return -1;
		}
		ret = listen(sfd,NUM);
		if(-1==ret)
		{
				perror("listen");
				return -1;
		}
		printf("listen success\n");
		int epfd = epoll_create(1);  //创建一个句柄，参数只要不是0就OK
		if(-1==epfd)
		{
				perror("epoll_create");
				return -1;
		}
		struct epoll_event eve,eves[NUM+1];
		eve.events = EPOLLIN;
		eve.data.fd = sfd;
		ret = epoll_ctl(epfd,EPOLL_CTL_ADD,sfd,&eve);
		if(-1==ret)
		{
				perror("epoll_ctl");
				return -1;
		}
		int i = 0;
		int newfd;
		while(1)
		{
				memset(eves,0,sizeof(eves));
				ret = epoll_wait(epfd,eves,NUM+1,-1);
				if(ret>0)
				{
						if(eves[i].events == EPOLLIN&&eves[i].data.fd == sfd)
						{
								newfd = accept(sfd,NULL,NULL);
								printf("accept newfd =%d\n",newfd);
						}
				}
		}
		return 0;
}
