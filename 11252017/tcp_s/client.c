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
	char buf[256]="";
	while(1)
	{
		bzero(buf,sizeof(buf));
		read(0,buf,sizeof(buf));
		ret = send(sfd,buf,strlen(buf)-1,0);
		if(-1==ret)
		{
			perror("send");
			return -1;
		}
		bzero(buf,sizeof(buf));
		ret = recv(sfd,buf,sizeof(buf),0);
		if(-1==ret)
		{
			perror("recv");
			return -1;
		}
		printf("recv from server:%s\n",buf);
	}
	return 0;
}

