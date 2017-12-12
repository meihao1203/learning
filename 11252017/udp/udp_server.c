#include"func.h"
int main(int argc,char **argv)
{
		if(3!=argc)
		{
				printf("error args\n");
				return -1;
		}
		int sfd = socket(AF_INET,SOCK_DGRAM,0);
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
		struct sockaddr_in client;
	    bzero(&client,sizeof(struct sockaddr));
		socklen_t addrlen = sizeof(struct sockaddr_in);
		char buf[256];
		bzero(buf,sizeof(buf));
		printf("wait recv client data...\n");
		ret = recvfrom(sfd,buf,sizeof(buf),0,(struct sockaddr *)&client,&addrlen);  //服务端要先接收数据，获取对应客户端的ip和端口;
		if(-1==ret)
		{
			perror("recvfrom");
			return -1;
		}
		printf("client ip =%s port =%d\n",inet_ntoa(client.sin_addr),ntohs(client.sin_port));
		printf("recv buf =%s\n",buf);
		bzero(buf,sizeof(buf));
		strcpy(buf,"I am server");
		ret = sendto(sfd,buf,strlen(buf),0,(struct sockaddr *)&client,addrlen);
		if(-1==ret)
		{
			perror("sendto");
			return -1;
		}
		close(sfd);
		return 0;
}
