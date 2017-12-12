#include"func.h"
//一个服务器能够同时监听多个客户端
//使用select I/O多路复用
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
		printf("sfd = %d\n",sfd);
		struct sockaddr_in ser;
		bzero(&ser,sizeof(ser));
		ser.sin_family = AF_INET;
		ser.sin_port = htons(atoi(argv[2]));
		ser.sin_addr.s_addr = inet_addr(argv[1]);
		int ret;
		ret = bind(sfd,(struct sockaddr *)&ser,sizeof(struct sockaddr_in));
		if(-1==ret)
		{
				perror("bind");
				return -1;
		}
		ret = listen(sfd,10);
		if(-1==ret)
		{
				perror("listen");
				return -1;
		}
		printf("I am listening\n");
		struct sockaddr_in client;
		bzero(&client,sizeof(struct sockaddr_in));
		socklen_t addrlen = sizeof(struct sockaddr);
		int newfd = accept(sfd,(struct sockaddr*)&client,&addrlen);
		if(-1==newfd)
		{
				perror("accept");
				return -1;
		}
		printf("newfd = %d\n",newfd);
		printf("client ip = %s , port = %d\n",inet_ntoa(client.sin_addr),ntohs(client.sin_port));
		char buf[512] = "";
		ret = recv(newfd,buf,sizeof(buf),0);
		if(-1==ret)
		{
				perror("recv");
				return -1;
		}
		printf("recv str =%s\n",buf);
		ret = send(newfd,"I am server",11,0);
		if(-1==ret)
		{
				perror("send");
				return -1;
		}
		close(newfd);
		close(sfd);
		return 0;
}
