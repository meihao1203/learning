///
/// @file    Epoll.cpp
/// @author  meihao1203(meihao19931203@outlook.com)
/// @date    2018-05-13 15:17:52
///

#include"Epoll.h"
#include<iostream>
#include<errno.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/epoll.h>
using namespace std;
#define handle_error(msg)\
	do{\
		perror(msg);\
		exit(EXIT_FAILURE);\
	}while(0);
namespace meihao
{
	int createEpollfd()
	{
		int efd = ::epoll_create(1);  //参数不为0即可
		if(-1==efd)
		{
			handle_error("epoll_create");
		}
		return efd;
	}
	void addEpollfd(int efd,int fd)
	{
		struct epoll_event event;
		event.events = EPOLLIN;
		event.data.fd = fd;
		int ret = epoll_ctl(efd,EPOLL_CTL_ADD,fd,&event);
		if(-1==ret)
		{
			handle_error("epoll_ctl");
		}
	}
	void delEpollfd(int efd,int fd)
	{
		struct epoll_event event;
		event.events = EPOLLIN;
		event.data.fd = fd;
		int ret = epoll_ctl(efd,EPOLL_CTL_DEL,fd,&event);
		if(-1==ret)
		{
			handle_error("epoll_ctl_del");
		}
	}
	Epoll::Epoll(int sfd):_efd(createEpollfd())
						  ,_sfd(sfd)
									,_isLooping(false)
												  ,_events(1024)  // 容器提前开辟空间
	{
		addEpollfd(_efd,_sfd);
	}
	void Epoll::loop()  // 开启监听客户端连接请求
	{
		_isLooping = true;
		while(_isLooping)
		{
			waitEpollfd();
		}
	}
	void Epoll::unloop() //关闭epoll监听
	{
		if(_isLooping)
			_isLooping = false;
	}
	void Epoll::waitEpollfd()
	{
		int ret;
		do
		{
			ret = ::epoll_wait(_efd,&(*_events.begin()),_events.size(),5000);
			// 事件满足的fd会放到vector里面
		}while(-1==ret&&errno==EINTR);  // 被中断打断
		if(-1==ret)
		{
			handle_error("epoll_wait");
		}
		else if(0==ret)  // 5S后超时返回
		{
			cout<<"Epoll wait timeout!"<<endl;
		}
		for(int idx=0;idx!=ret;++idx)
		{
			if(_events[idx].data.fd ==_sfd &&_events[idx].events == EPOLLIN)
			{//处理新连接
				handleConnection();
			}
			else if(_events[idx].events == EPOLLIN)  
			{//处理已经连接上的客户端的输入请求
				handleMessage(_events[idx].data.fd);
			}
		}
	}
	void Epoll::handleConnection()
	{
		int connfd = ::accept(_sfd,NULL,NULL);
		addEpollfd(_efd,connfd);  
		//处理新的TCP链接
		TcpConnectionPtr con(new TcpConnection(connfd));
		cout<<"TcpConnectionPtr"<<con<<endl;
		//设置TcpConnectionPtr的回调函数
		con->setConnectionCallback(_onConnectionCb);
		con->setMessageCallback(_onMessageCb);
		con->setCloseCallback(_onCloseCb);
		_mapConnections.insert(::make_pair(connfd,con));  // map中插入新连接的请求
		con->handleConnectionCallback();
	}
	void Epoll::handleMessage(int connfd)
	{
		auto it = _mapConnections.find(connfd);  //找到map中存放的对应描述符的关键字
		if(it!=_mapConnections.end())  //如果描述符确实存在
		{
			bool flag = isConnected(connfd);
			if(flag)
			{//链接没有断开
				it->second->handleMessageCallback();  // tcp连接处理消息，调用的是TcpConnection类里的函数
			}
			else
			{//断开
				delEpollfd(_efd,connfd);
				it->second->handleCloseCallback();  //打印显示断开信息
				_mapConnections.erase(it);  //map中删除对应的pair
			}
		}
	}
	bool Epoll::isConnected(int connfd)
	{
		int ret;
		char buf[512];
		do
		{
			ret = recv(connfd,buf,sizeof(buf),MSG_PEEK);  // 从内核缓冲区预读取
		}while(-1==ret&&errno==EINTR);
		return ret>0;  //>0表示有数据可读,链接没有断开
	}
	void Epoll::epollSetConnectionCallback(TcpConnectionCallback cb)
	{
		_onConnectionCb = cb;
	}
	void Epoll::epollSetMessageCallback(TcpConnectionCallback cb)
	{
		_onMessageCb = cb;
	}
	void Epoll::epollSetCloseCallback(TcpConnectionCallback cb)
	{
		_onCloseCb = cb;
	}
};
