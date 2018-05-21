 ///
 /// @file    EpollPoller.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-05-21 11:34:30
 ///
 
#include"EpollPoller.h"
#include<iostream>
#include<errno.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/epoll.h>
#include<string.h>
using namespace std;
#define handle_error(msg)\
	do{ perror(msg); exit(EXIT_FAILURE);}while(0);
namespace meihao
{
	int eventsize = 1024;  //epoll_wait存放描述符的vector,必须事先开辟空间，不让放不了，底层实现都是直接放，不会push_back
	int createfd()
	{
		int efd = ::epoll_create(1);
		if(-1==efd)
		{
			handle_error("epoll_create");
		}
		return efd;
	}
	int addEpollfd(int efd,int newfd)
	{
		struct epoll_event event;
		bzero(&event,sizeof(event));
		event.events = EPOLLIN;
		event.data.fd = newfd;
		int ret = ::epoll_ctl(efd,EPOLL_CTL_ADD,newfd,&event);
		if(-1==ret)
		{
			handle_error("::epoll_ctl");
		}
		return 0;
	}
	int delEpollfd(int efd,int delfd)
	{
		struct epoll_event event;
		bzero(&event,sizeof(event));
		event.events = EPOLLIN;
		event.data.fd = delfd;
		int ret = ::epoll_ctl(efd,EPOLL_CTL_DEL,delfd,&event);
		if(-1==ret)
		{
			handle_error("::epoll_ctl del");
		}
		return 0;
	}
	EpollPoller::EpollPoller(int listenfd):_listenfd(listenfd)
										 ,_epollfd(createfd())
										 ,_isLoop(false)
										 ,_eventList(eventsize)
	{
		addEpollfd(_epollfd,_listenfd);
	}
	void EpollPoller::waitEpollfd()
	{
		int ret;
		do
		{
			ret = ::epoll_wait( _epollfd,&(*_eventList.begin()),_eventList.size(),5000 );
		}while(-1==ret&&errno==EINTR);
		if(-1==ret)
		{
			handle_error("::epoll_wait");
		}
		else if(0==ret)
			cout<<"epoll timeout"<<endl;
		else 
		{
			if(ret==_eventList.size())
			{
				_eventList.resize(ret*2);
			}
			for(int idx=0;idx!=ret;++idx)
			{
				if( _eventList[idx].data.fd == _listenfd&&_eventList[idx].events==EPOLLIN )
				{//有新的链接
					handleConnection();
				}
				else
				{//已有链接描述符可读
					handleMessage(_eventList[idx].data.fd);
				}
			}
		}
	}
	void EpollPoller::loop()
	{
		if(!_isLoop)
		{
			_isLoop = true;
			while(_isLoop)
			{
				waitEpollfd();
			}
		}
	}
	void EpollPoller::unloop()
	{
		if(_isLoop)
		{
			_isLoop = false;
		}
	}
	void EpollPoller::handleConnection()
	{
		int newfd = ::accept(_listenfd,NULL,NULL);
		if(-1==newfd)
		{
			handle_error("::accept");
		}
		TcpConnectionPtr conn(new TcpConnection(newfd));
		conn->setConnectionCallback(_onConnection);
		conn->setMessageCallback(_onMessage);
		conn->setCloseCallback(_onClose);
		_connMap.insert(::make_pair(newfd,conn));
		conn->handleConnectionCallback();
		addEpollfd(_epollfd,newfd);
	}
	bool isConnected(int fd)
	{
		int ret;
		char buf[1024];
		do
		{
			ret = ::recv(fd,buf,sizeof(buf),MSG_PEEK);
		}while(-1==ret&&errno==EINTR);
		return 0==ret;  //等于0断开，不等于0没断开
	}
	void EpollPoller::handleMessage(int fd)
	{
		bool flag = isConnected(fd);
		auto it = _connMap.find(fd);
		if(it!=_connMap.end())
		{
			if(!flag)
			{
				it->second->handleMessageCallback();
			}
			else
			{
				it->second->handleCloseCallback();
				delEpollfd(_epollfd,fd);
				_connMap.erase(fd);
			}
		}
		else
		{
			cout<<"no this fd"<<endl;
		}
	}
	void EpollPoller::setConnectionCallback(TcpConnectionCallback cb)
	{
		_onConnection = cb;
	}
	void EpollPoller::setMessageCallback(TcpConnectionCallback cb) 
	{
		_onMessage = cb;
	}
	void EpollPoller::setCloseCallback(TcpConnectionCallback cb) 
	{
		_onClose = cb;
	}
};
