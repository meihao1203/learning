#include"func.h"
void send_fd(int fds,int fd)
{
	struct msghdr msg;
	struct iovec iov[2];
	char buf1[6] = "hello";
	char buf2[6] = "world";
	iov[0].iov_base = buf1;
	iov[0].iov_len = strlen(buf1);
	iov[1].iov_base = buf2;
	iov[1].iov_len = strlen(buf2);
	
	struct cmsghdr *cmsg;
	int len = CMSG_LEN(sizeof(int));   //我们要传递的是一个整形的描述符
	cmsg = (struct cmsghdr*)calloc(1,len);
	cmsg->cmsg_len = len;
	cmsg->cmsg_level = SOL_SOCKET;
	cmsg->cmsg_type = SCM_RIGHTS;
	int *fdptr;
	fdptr = (int *)CMSG_DATA(cmsg);
	*fdptr = fd;

	bzero(&msg,sizeof(msg));
	msg.msg_iov = iov;
	msg.msg_iovlen = 2;
	msg.msg_control = cmsg;
	msg.msg_controllen = len;

	int ret = sendmsg(fds,&msg,0);
	if(-1==ret)
	{
		perror("sendmsg");
		return ;
	}
	return ;
}
void read_fd(int fds,int *fd)
{
	struct msghdr msg;
	bzero(&msg,sizeof(msg));
	char buf1[6] = "";
	char buf2[6] = "";
	struct iovec iov[2];
	iov[0].iov_base = buf1;
	iov[0].iov_len = strlen(buf1);
	iov[1].iov_base = buf2;
	iov[1].iov_len = strlen(buf2);

	struct cmsghdr *cmsg;
	int len = CMSG_LEN(sizeof(int));
	cmsg = (struct cmsghdr*)calloc(1,len);
	cmsg->cmsg_len = len;
	//cmsg->cmsg_level = SOL_SOCKET;
	//cmsg->cmsg_type = SCM_RIGHTS;
	
	bzero(&msg,sizeof(msg));
	msg.msg_iov = iov;
	msg.msg_iovlen = 2;
	msg.msg_control = cmsg;
	msg.msg_controllen = len;
	
	int ret = recvmsg(fds,&msg,0);
	if(-1==ret)
	{
		perror("recvmsg");
		return ;
	}
	*fd = *(int *)CMSG_DATA(cmsg);
	//printf("buf1=%s buf2=%s\n",buf1,buf2);
	return;
}
int main(int argc,char **argv)
{
	if(2!=argc)
	{
		printf("error args\n");
		return -1;
	}
	int fds[2];
	int ret = socketpair(AF_LOCAL,SOCK_STREAM,0,fds);
	if(-1==ret)
	{	
		perror("socketpair");
		return -1;
	}
	if( !fork() )
	{
		close(fds[1]);
		int fd;
		read_fd(fds[0],&fd);
		printf("child fd =%d\n",fd);
		char buf[128];
		read(fd,buf,sizeof(buf));
		printf("file content =%s\n",buf);
		fds[0];
		exit(*(int*)NULL);
	}
	else
	{
		close(fds[0]);
		int fd = open(argv[1],O_RDWR|O_CREAT,0666);
		printf("parent fd =%d\n",fd);
		send_fd(fds[1],fd);
		close(fds[1]);
		wait(NULL);
	}
	return 0;

}
