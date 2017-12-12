#ifndef __THREAD_MSG_H__
#define __THREAD_MSG_H__
#include"func.h"
typedef struct
{
	int len;
	char buf[1024];
}data,*pdata;


void send_n(int new_fd,char *buf,int len);
void recv_n(int new_fd,char *buf,int len);



#endif