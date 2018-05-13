///
/// @file    test.cpp
/// @author  meihao1203(meihao19931203@outlook.com)
/// @date    2018-05-04 16:00:43
///

#include"InetAddress.h"
#include"Epoll.h"
#include"Socket.h"
#include"SocketIO.h"
#include"TcpConnection.h"
#include<iostream>
#include<strings.h>
#include<string.h>
using namespace std;
void test0()
{
	meihao::InetAddress inetAddr(8848);
	meihao::Socket socket;
	socket.ready(inetAddr);  // 开启服务器端口
	int newfd = socket.accept();
	meihao::SocketIO sockio(newfd);
#if 0  // 测试readn和writen正确
	char buf[512] = "I am server!";
	sockio.writen(buf,sizeof(buf));
	bzero(buf,sizeof(buf));
	sockio.readn(buf,sizeof(buf));
	cout<<buf<<endl;
#endif 
#if 0
	char buf[512] = "I am server!\n";
	sockio.writen(buf,strlen(buf));
	bzero(buf,sizeof(buf));
	sockio.readline(buf,sizeof(buf));
	cout<<buf;  //读一行自带回车
	//最后结果及时对端输入
#endif 
	meihao::InetAddress test = meihao::Socket::getPeerAddress(newfd);
	cout<<test.ip()<<"  "<<test.port()<<endl;
#if 1
	while(true)
	{

	}
#endif
}
#if 1 // 测试TCPConnection类
	void onConnection(const meihao::TcpConnectionPtr& connect)
	{
		cout<<connect->toString()<<"has connected!"<<endl;
		connect->send("I am server\n");
	}
	void onMessage(const meihao::TcpConnectionPtr& connect)
	{
		string msg = connect->receive();
		cout<<msg<<endl;
		connect->send(msg);
	}
	void onClose(const meihao::TcpConnectionPtr& connect)
	{
		cout<<connect->toString()<<"has closed"<<endl;
	}
#endif 
void test1()
{
#if 1
	meihao::InetAddress inet("192.168.254.136",8848);
	meihao::Socket socket;
	socket.ready(inet);
	int newfd = socket.accept();
	//meihao::TcpConnection tcp(newfd);
	meihao::TcpConnection* tcp = new meihao::TcpConnection(newfd);
	meihao::TcpConnectionPtr ptr(tcp);
	ptr->setConnectionCallback(onConnection);
	ptr->setMessageCallback(onMessage);
	ptr->setCloseCallback(onClose);
	//	ptr->handleConnectionCallback();
	//	ptr->handleMessageCallback();
	//	ptr->handleCloseCallback();
	ptr->shutdown();
#endif
}

int main()
{
	meihao::InetAddress inet("192.168.254.136",8848);
	meihao::Socket socket;
	socket.ready(inet);  //开启服务器端口
	meihao::Epoll epoll(socket.fd());
	epoll.epollSetConnectionCallback(onConnection);
	epoll.epollSetMessageCallback(onMessage);
	epoll.epollSetCloseCallback(onClose);
	epoll.loop();
}

