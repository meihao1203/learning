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
#include<stdio.h>
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
			int nread = ::recv(_fd,ptmp,left,0);
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
	int  SocketIO::writen(const char* buf,int count)
	{
		int left = count;
		const char* ptmp = buf;
		while(left>0)
		{
			int nread = ::send(_fd,ptmp,left,0);
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
		return count-left;
	}
	int SocketIO::recvPeek(char* buf,int count)
	{
		int nread = ::recv(_fd,buf,count,MSG_PEEK);
		if(-1==nread)
		{
			perror("recvPeek");
		}
	}
	int SocketIO::readline(char* buf,int maxlen)  // 失败返回-1
	{
		int left = maxlen;
		char* ptmp = buf;
		int nread = 0;
		while(left>0)
		{
			nread = recvPeek(ptmp,left);
			if(-1==nread)
			{
				if(errno==EINTR)
					continue;
				return -1;
			}
			else if(0==nread)
				return -1;
			for(int idx=0;idx<nread;idx++)
			{
				if(ptmp[idx]=='\n')
				{
					if(readn(ptmp,nread)!=nread)
						return -1;
					left -= nread;
					return maxlen-left;
				}
			}
			// 预读取一行没有读到换行
			if(readn(ptmp,nread)!=nread)
				return -1;
			ptmp += nread;
			left -= nread;
		}
		return maxlen-left;
	}
};
