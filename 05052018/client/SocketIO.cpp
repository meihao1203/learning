 ///
 /// @file    SocketIO.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-05-04 19:17:11
 ///
 
#include"SocketIO.h"
#include<stdio.h>
#include<unistd.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<iostream>
using namespace std;
namespace meihao
{
	SocketIO::SocketIO(int fd):_fd(fd)
	{
	}
	size_t SocketIO::readn(char* buf,size_t count)
	{
		int nleft = count;
		char* btmp = buf;
		int tmp = 0;
		while(nleft>0)
		{
			tmp = read(_fd,btmp,nleft);
			cout<<tmp<<endl;
			if(-1==tmp)
			{
				if(errno==EINTR)
					continue;
				_exit(-1);
			}
			else if(0==tmp)
			{
				break;
			}
			btmp += tmp;
			nleft -= tmp;
		}
		return  count-nleft;  // 一共真正赌了多少个字符
	}
	size_t SocketIO::writen(const char* buf,size_t count)
	{
		int nleft = count;
		const char* btmp = buf;
		int tmp = 0;
		while(nleft>0)
		{
			tmp = write(_fd,btmp,nleft);
			if(-1==tmp)
			{
				if(errno==EINTR)
					continue;
			//	_exit(-1);  //不能直接退出，不然程序就完了
				return -1;
			}
			else if(0==tmp)
			{
				break;
			}
			btmp += tmp;
			nleft -= tmp;
		}
		return count-nleft;  // 返回值非0，表示出错
	}
	size_t SocketIO::readLine(char* buf,size_t count)
	{
		int nleft = count-1;  // 最后有一个换行
		int total = 0;
		char* ptmp = buf;
		int  nread = 0;
		while(nleft>0)
		{
			nread = recvPeek(ptmp,nleft);
			if(nread<=0)
				_exit(-1);
			for(int idx=0;idx<nread;++idx)
			{
				//读到换行表示读完一行
				if(ptmp[idx]=='\n')
				{
					if(readn(ptmp,idx)!=idx)  // 这是后才真正的把内核缓冲区的一行数据读走,idx处是\n，所以要读idx+1
					{
						return -1;
					}
					ptmp += (idx+1);  // \n 后面一个\0，表示结束
					total += (idx+1);
					*ptmp = '\0';  // 标记一行读完，最后一个数为\0,这里不要也可以把
					return total;
				}
			}
			//recvPeek一次没有读到\n
			if(readn(ptmp,nread)!=nread)  // 也把数据先读出nread个，完了再接着读
				return -1;
			ptmp += nread;
			total += nread;
			nleft -= nread;  // count个还剩多少个
		}
		*ptmp = '\0';
		return count-1;  // 到这里才返回表示count个都没读到一个换行
	}
	size_t SocketIO::recvPeek(char* buf,size_t count)  // 预读取字符串，内核缓冲区到应用缓冲区
	{
		int nread = 0;
		do
		{
			nread = recv(_fd,buf,count,MSG_PEEK);  // MSG_PEEK,表示预读取，只从内核缓冲区中拷贝一份，但是不取走数据
		}while(-1==nread&&errno==EINTR);
		return nread;
	}
};
