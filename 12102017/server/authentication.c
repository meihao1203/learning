#include"func.h"
void authentication(int new_fd)
{
	char passwd[512] = {0};
	char usrname[512] = {0};
	char salt[512] = {0};
	//接收链接客户端的用户名
	int usrname_len;
	int passwd_len;
	recv_n(new_fd,(char *)&usrname_len,sizeof(int));
	recv_n(new_fd,usrname,name_len);
	//接收链接客户端的密码
	recv_n(new_fd,(char *)&passwd_len,sizeof(int));
}
