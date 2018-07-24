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
	Eventfd::Eventfd(EventfdCallback cb):_cb(cb)
								,_isStarted(false)
								,_fd(getEventfd())
	{
	}
	void Eventfd::handleRead()
	{
		uint64_t tmp;
		int ret = read(_fd,&tmp,sizeof(tmp));
		if(ret!=sizeof(tmp))
		{
			cout<<"handleRead read error!\n";
		}
	}
	void Eventfd::start()
	{
		_isStarted = true;
		struct pollfd fds;
		fds.fd = _fd;
		fds.events = POLLIN;
		time_t t;
		time(&t);
		cout<<"start time "<<ctime(&t)<<endl;
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
				time_t t;
				time(&t);
				cout<<"poll trigger time "<<ctime(&t);
				handleRead();  // 读走计数器的值
				if(_cb)
					_cb();
			}
		}
	}
	void Eventfd::stop()
	{
		_isStarted = false;
	}
	void Eventfd::wakeup()
	{
		uint64_t tmp = 1;
		write(_fd,&tmp,sizeof(tmp));
	}
	Eventfd::~Eventfd()
	{

	}
};
