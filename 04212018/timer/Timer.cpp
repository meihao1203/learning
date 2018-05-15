 ///
 /// @file    Timer.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-04-21 11:04:35
 ///
 
#include<iostream>
#include"Timer.h"
#include<sys/timerfd.h>
#include<stdio.h>
#include<string.h>
#include<poll.h>
#include<errno.h>
#include<unistd.h>
#include<stdint.h>  // 里面定义了uint64_t
using namespace std;
namespace meihao
{
	int getTimerfd()
	{
		int fd = timerfd_create(CLOCK_REALTIME,0);
		if(-1==fd)
		{
			cout<<"timerfd_create failture!"<<endl;
		}
		return fd;
	}
	void setTimerfd(int _fd,int initialSec,int intervalSec)
	{
		struct itimerspec new_value;
		memset(&new_value,0,sizeof(new_value));
		new_value.it_interval.tv_sec = intervalSec;
		new_value.it_value.tv_sec = initialSec;
		int ret = timerfd_settime(_fd,0,&new_value,NULL);
		if(-1==ret)
		{
			cout<<"timerfd_settime fail!"<<endl;
		}
	}
	Timer::Timer(TimerCallback cb,int initialSec,int intervalSec):_cb(cb)
																  ,_isStarted(false)
																  ,_initialSec(initialSec)
																  ,_intervalSec(intervalSec)
																  ,_fd(getTimerfd())
	{}
	void Timer::start()
	{
		//设置、开启计时器
		setTimerfd(_fd,_initialSec,_intervalSec);
		struct pollfd fds;
		fds.fd = _fd;  //要监听的描述符
		fds.events = POLLIN;  //要监听的事件，可读
		_isStarted = true;
		time_t t;
		time(&t);
		cout<<"计时器开启：\n"<<ctime(&t)<<endl;  //打印当前系统时间，自带换行
		while(_isStarted)
		{
			int ret = poll(&fds,1,5000);  //5s后时间没发生就返回
			if(0==ret)
			{
				cout<<"timeout!"<<endl;
				continue;
			}
			else if(-1==ret)
			{
				if(ret==EINTR)  //请求的事件之前产生一个信号，调用可以重新发起
					// #define EINTR 4   /* Interrupted system call */
					continue;
				cout<<"poll error!"<<endl;
				_exit(-1);
			}
			else if(fds.revents == POLLIN)
			{
				uint64_t tmp;
				time_t t;
				time(&t);
				cout<<ctime(&t);
				int ret = read(_fd,&tmp,sizeof(uint64_t));
				if(ret!=sizeof(tmp))
				{
					cout<<"read timerfd error"<<endl;
					_exit(-1);
				}
				if(_cb)  // 回调函数存在
				{
					_cb();
				}
			}
		}
	}
	void Timer::stop()
	{
		if(_isStarted)
		{
			setTimerfd(_fd,0,0);
			_isStarted = false;
		}
	}
	Timer::~Timer()
	{

	}
};
