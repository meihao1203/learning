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
		struct sockaddr_in client;
		bzero(&client,sizeof(struct sockaddr_in));
		socklen_t addrlen = sizeof(struct sockaddr_in);
		fd_set rdset;
		fd_set tmpset;
		FD_ZERO(&tmpset);
		FD_SET(sfd,&tmpset);
		int newfd[NUM]={0};
		int i = 0;
		int j;
		char buf[256];  //用来接数据
		while(1)
		{
			FD_ZERO(&rdset);
			memcpy(&rdset,&tmpset,sizeof(fd_set));
			ret = select(NUM+4,&rdset,NULL,NULL,NULL);
			if(ret>0)
			{
				if(FD_ISSET(sfd,&rdset))
				{
					newfd[i] = accept(sfd,(struct sockaddr *)&client,&addrlen);
					if(-1==newfd[i])
					{
						perror("accept");
						return -1;
					}
					printf("client ip = %s port = %d\n",inet_ntoa(client.sin_addr),ntohs(client.sin_port));
					FD_SET(newfd[i],&tmpset);
					i++;
				}
				j=0;
				while(newfd[j]!=0)
				{
					if(FD_ISSET(newfd[j],&rdset))
					{
						bzero(buf,sizeof(buf));
						ret = recv(newfd[j],buf,sizeof(buf),0);
						if(0==ret)
						{
							printf("close client ip = %s port = %d\n",inet_ntoa(client.sin_addr),ntohs(client.sin_port));
							close(newfd[j]);
							FD_CLR(newfd[j],&tmpset);
						}
						else if(-1==ret)
						{
							printf("recv error\n");
							return -1;
						}
						else if(ret>0)
						{
							printf("newfd %d recv buf =%s\n",newfd[j],buf);
							send(newfd[j],buf,sizeof(buf),0);
						}
					}
					j++;
				}
			}
		}
		return 0;

}