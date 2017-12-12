#include"thread_msg.h"
int main(int argc,char **argv)
{
	if(5!=argc)
	{
		printf("error argcs\n");
		return -1;
	}
	factory f;
	factory_init(&f,atoi(argv[3]),atoi(argv[4]),thread_func);
	factory_start(&f);

	int sfd = socket(AF_INET,SOCK_STREAM,0);

	struct sockaddr_in ser;
	bzero(&ser,sizeof(ser));
	ser.sin_port = htons(atoi(argv[2]));
	ser.sin_addr.s_addr = inet_addr(argv[1]);
	ser.sin_family = AF_INET;
	int ret = bind(sfd,(struct sockaddr*)&ser,sizeof(ser));
	if(-1==ret)
	{
		perror("bind");
		return -1;
	}

	ret = listen(sfd,atoi(argv[4]));
	if(-1==ret)
	{
		perror("listen");
		return -1;
	}
	int new_fd;
	while(1)
	{
		new_fd = accept(sfd,NULL,NULL);
		if(-1==new_fd)
		{
			printf("accept error\n");
			return -1;
		}
		que_insert(&f.que_t,new_fd);
		pthread_cond_signal(&f.cond);
	}
	return 0;
}