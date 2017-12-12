#include"func.h"
int main()
{
	int fd = open("1.txt",O_RDWR);
	char buf1[6] = {'h','e','l','l','o'};
	char buf2[5] = "world";
	struct iovec iov[2];
	iov[0].iov_base = buf1;
	iov[0].iov_len = strlen(buf1);
	//iov[0].iov_len = 5;
	iov[1].iov_base = buf2;
	iov[1].iov_len = strlen(buf2);
	//iov[1].iov_len = 5;
	int ret = writev(fd,iov,2);
	if(-1==ret)
	{
		perror("writev");
		return -1;
	}
	return 0;
}