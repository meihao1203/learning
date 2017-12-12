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
		struct sockaddr_in client;
		bzero(&client,sizeof(struct sockaddr));
		client.sin_family = AF_INET;
		client.sin_port = htons(atoi(argv[2]));
		client.sin_addr.s_addr = inet_addr(argv[1]);
		socklen_t addrlen = sizeof(client);
		char buf[256] = "I am client";
		int ret = sendto(sfd,buf,strlen(buf),0,(struct sockaddr *)&client,addrlen);
		if(-1==ret)
		{
			perror("sendto");
			return -1;
		}
		bzero(buf,sizeof(buf));
		struct sockaddr_in server;
		bzero(&server,sizeof(struct sockaddr));
		socklen_t addrlen2 = sizeof(struct sockaddr_in);
		//ret  = recvfrom(sfd,buf,sizeof(buf),0,(struct sockaddr *)&server,&addrlen2);
		ret  = recvfrom(sfd,buf,sizeof(buf),0,NULL,NULL);
		//printf("server ip =%s port =%d\n",inet_ntoa(server.sin_addr),ntohs(server.sin_port));
		printf("recv buf =%s\n",buf);
		close(sfd);
		return 0;
}
