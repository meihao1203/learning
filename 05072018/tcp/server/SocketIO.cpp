 ///
 /// @file    SocketIO.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-05-07 10:42:08
 ///
 
#include"SocketIO.h"
#include<iostream>
#include<sys/types.h>
#include<sys/socket.h>
#include<errno.h>
#include<stdlib.h>
using namespace std;
namespace meihao
{
	SocketIO::SocketIO(int fd):_fd(fd)
	{

	}
	int SocketIO::readn(char* buf,int count)
	{
		int left = count;
		char* ptmp = buf;
		while(left>0)
		{
			int nread = recv(_fd,ptmp,left,0);
			if(-1==nread)
			{
				if(errno==EINTR)
					continue;
				exit(EXIT_FAILURE);
			}
			else if(0==nread)
				break;
			left -= nread;
			ptmp += nread;
		}
		return count-left;  // 返回发送的数据个数
	}
	int 
};
