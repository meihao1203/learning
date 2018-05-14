 ///
 /// @file    server.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-05-14 09:23:37
 ///
 
#include<iostream>
#include"TcpServer.h"
#include"TcpConnection.h"
using namespace std;
void onConnection(const meihao::TcpConnectionPtr& conn)
{
	cout<<conn->toString()<<"has connected!"<<endl;
	conn->send("connect success!\n");
}
void onMessage(const meihao::TcpConnectionPtr& conn)
{
	string msg = conn->receive();
	cout<<"recv:"<<msg;
	conn->send(msg);
}
void onClosed(const meihao::TcpConnectionPtr& conn)
{
	cout<<conn->toString()<<"has closed!"<<endl;
}
int main()
{
	meihao::TcpServer tcpServer(8848);
	tcpServer.tcpServerSetConnectionCallback(onConnection);
	tcpServer.tcpServerSetMessageCallback(onMessage);
	tcpServer.tcpServerSetCloseCallback(onClosed);
	tcpServer.start();
	tcpServer.stop();
}
