#include"func.h"
#define NUM 10
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
		socklen_t addrlen = sizeof(struct sockaddr_in);
		int ret = connect(sfd,(struct sockaddr *)&ser,addrlen);
		if(-1==ret)
		{
				perror("connect");
				return -1;
		}
		int epfd = epoll_create(1);
		if(-1==epfd)
		{	
				perror("epoll_create");
				return -1;
		}
		struct epoll_event eve,eves[2];
		eve.events = EPOLLIN;
		eve.data.fd = sfd;
		ret = epoll_ctl(epfd,EPOLL_CTL_ADD,sfd,&eve);
		if(-1==ret)
		{
				perror("epoll_ctl");
				return -1;
		}
		eve.events = EPOLLIN;
		eve.data.fd = 0;
		ret = epoll_ctl(epfd,EPOLL_CTL_ADD,0,&eve);
		if(-1==ret)
		{
				perror("epoll_ctl");
				return -1;
		}
		int i = 0;
		char buf[256];
		int n = 0;
		while(1)
		{	
				bzero(eves,sizeof(eves));
				ret = epoll_wait(epfd,eves,2,-1);
				if(ret>0)
				{
						for(i=0;i<ret;i++)
						{
								if(eves[i].events == EPOLLIN&&eves[i].data.fd == 0)
								{
										bzero(buf,sizeof(buf));
										n = read(0,buf,sizeof(buf));	
										if(0==n)  //ctrl+d关闭客户端
										{
												printf("bye\n");
												close(sfd);
												return -1;
										}
										else if(-1==n)
										{
												perror("read");
												return -1;
										}
										else if(n>0)
										{
												n = send(sfd,buf,strlen(buf)-1,0);
												if(-1==n)
												{
														perror("send");
														close(sfd);
														return -1;
												}
										}
								}
								if(eves[i].events == EPOLLIN&&eves[i].data.fd ==sfd)
								{
										bzero(buf,sizeof(buf));
										n = recv(sfd,buf,sizeof(buf),0);
										if(n>0)
										{
												printf("recv form server buf =%s\n",buf);
										}
										else if(-1==n)
										{	
												perror("recv");
												close(sfd);
												return -1;
										}
										else if(0==n)
										{
												printf("bye\n");
												close(sfd);
												return 0;
										}
								}
						}
				}
		}
		close(sfd);
		return 0;
}
