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
		close(sfd);
		return 0;
}
