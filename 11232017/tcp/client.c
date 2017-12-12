#include"func.h"
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
	ret = connect(sfd,(struct sockaddr*)&ser,sizeof(struct sockaddr_in)); 
	if(-1==ret)
	{
		perror("connect");
		return -1;
	}
	printf("I am connected\n");
	char buf[512] = "";
	ret = send(sfd,"I am client",11,0);
	if(-1==ret)
	{
		perror("send");
		return -1;
	}
	ret = recv(sfd,buf,sizeof(buf),0);
	if(-1==ret)
	{
		perror("recv");
		return -1;
	}
	printf("recv str =%s\n",buf);
	close(sfd);
	return 0;
}
