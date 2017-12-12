#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<stdio.h>
int main(int argc,char **argv)
{
	if(2!=argc)
	{
		printf("error args\n");
		return -1;
	}
	struct in_addr addr;
	int ret = inet_aton(argv[1],&addr);
	if(0==ret)
	{
		perror("inet_aton");
		return -1;
	}
	printf("net addr %x\n",addr.s_addr);
	printf("host addr %s\n",inet_ntoa(addr));
	printf("net addr %x\n",inet_addr(argv[1]));
	return 0;
}
