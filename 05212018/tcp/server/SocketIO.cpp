 ///
 /// @file    SocketIO.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-05-20 19:29:49
 ///
 
#include"SocketIO.h"
#include<iostream>
#include<stdlib.h>
#include<errno.h>
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
			else
			{
				left -= nread;
				ptmp += nread;
			}
		}
		return count-left;  // 返回读了多少个数据
	}
	int SocketIO::writen(const char* buf,int count)
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
			else
			{
				left -= nread;
				ptmp += nread;
			}
		}
		return count-left;
	}
	int SocketIO::readPeek(char* buf,int count)
	{
		int nread = ::recv(_fd,buf,count,MSG_PEEK);
		if(-1==nread)
			return -1;
		return nread;
	}
	int SocketIO::readline(char* buf,int count)
	{
		int left = count-1;  //如果读最大字节数还没有找到回车，就用\0结尾
		char* ptmp = buf;
		int readcnt = 0;
		while(left>0)
		{
			int nread = readPeek(ptmp,left);
			if(nread<=0)
				return -1;
			else
			{
				for(int idx=0;idx!=nread;++idx)
				{
					if(ptmp[idx]=='\n'||ptmp[idx]=='\0')
					{
						if(readn(ptmp,(idx+1))!=(idx+1))
							return -1;
						left -= (idx+1);
						ptmp += (idx);
						readcnt += (idx+1);
						return readcnt;
					}
				}
			}
			if(readn(ptmp,nread)!=nread)
				return -1;
			left -= nread;
			ptmp += nread;
			readcnt += nread;
		}
		*ptmp = '\0';
		return readcnt;
	}
};
