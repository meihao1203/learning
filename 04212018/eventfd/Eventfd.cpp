 ///
 /// @file    Eventfd.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-04-21 15:52:42
 ///
 
#include<iostream>
#include"Eventfd.h"
#include"sys/eventfd.h"
#include<poll.h>
#include<errno.h>
#include<unistd.h>
using namespace std;
namespace meihao
{
	int getEventfd()
	{
		int fd = eventfd(0,0);  //初始计数器的值为0
		if(-1==fd)
		{
			cout<<"eventfd fail!\n";
		}
		return fd;
	}
	Eventfd(EventfdCallback cb):_cb(cb)
								,_isStarted(false)
								_fd(getEventfd())
	{

	}
	void Eventfd::
	void Eventfd::start()
	{
		_isStarted = true;
		struct pollfd fds;
		fds.fd = _fd;
		fds.events = POLLIN;
		while(_isStarted)
		{
			int ret = poll(&fds,1,5000);
			if(0==ret)
			{
				cout<<"timeout!\n";
				continue;
			}
			else if(-1==ret)
			{
				if(ret==EINTR)
				{
					continue;
				}
				cout<<"poll error!\n";
				_exit(-1);
			}
			else if(fds.revents==POLLIN)
			{
				handleRead();  // 读走计数器的值
				if(_cb)
					_cb();
			}
		}
	}
};
