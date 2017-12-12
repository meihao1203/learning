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
		struct epoll_event eve,eves[NUM+2]; //NUM+sfd+0
		eve.events = EPOLLIN; //注册sfd
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
		int newfd;
		char buf[256] = "";
		int n = 0;
		while(1)
		{
				memset(eves,0,sizeof(eves));
				ret = epoll_wait(epfd,eves,NUM+2,-1);
				if(ret>0)
				{
						for(i=0;i<ret;i++)
						{
							if(eves[i].events == EPOLLIN&&eves[i].data.fd == sfd)
							{
								newfd = accept(sfd,NULL,NULL);
							    printf("accept newfd =%d\n",newfd);
								eve.events = EPOLLIN;
								eve.data.fd = newfd;
								epoll_ctl(epfd,EPOLL_CTL_ADD,newfd,&eve);
							}
							if(eves[i].events == EPOLLIN&&eves[i].data.fd == 0)
							{
								memset(buf,0,sizeof(buf));
								n = read(0,buf,sizeof(buf));		
								if(n>0)
								{
									n = send(newfd,buf,strlen(buf)-1,0);
									if(-1==n)
									{
										perror("send");
										return -1;
									}
								}
								else if(0==n)  //服务端关闭连接的客户端，ctrl+d,read就会读到0
								{
									printf("bye\n");
									eve.events = EPOLLIN;
									eve.data.fd = newfd;
									epoll_ctl(epfd,EPOLL_CTL_DEL,newfd,&eve);
									close(newfd);
								}
								else if(-1==n)
								{
									perror("read");
									return -1;
								}
							}
							if(eves[i].events == EPOLLIN&&eves[i].data.fd == newfd)
							{
								memset(buf,0,sizeof(buf));
								n = recv(newfd,buf,sizeof(buf),0);
								if(n>0)
								{
									printf("recv client buf =%s\n",buf);
								}
								else if(-1==n)
								{
									perror("recv");
									return -1;
								}
								else if(0==n)  //对端关闭，读到0(对端ctrl+d,read就会读到0)
								{	
									printf("bye/n");
									eve.events = EPOLLIN;
									eve.data.fd = newfd;
									epoll_ctl(epfd,EPOLL_CTL_DEL,newfd,&eve);
									close(newfd);
								}
							}
						}
				}
		}
		close(newfd);
		return 0;
}
