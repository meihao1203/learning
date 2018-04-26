 ///
 /// @file    test.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-04-26 15:07:47
 ///
 
#include"InetAddress.h"
#include"Socket.h"
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include<iostream>
#include<string.h>
#include<unistd.h>
using namespace std;
int main()
{
	meihao::InetAddress InetAddr(8888);  // 这个类主要是封装socket编程中bind要用到的信息
	//只传端口号，使用默认的本机地址
	//使用本地地址，ip=0.0.0.0
	//meihao::InetAddress InetAddr("192.168.254.136",8888);
	meihao::Socket socket;
	socket.ready(InetAddr);  // 开启服务器端
	meihao::InetAddress localMsg = meihao::Socket::getLocalAddress(socket.fd());
	//struct sockaddr_in* msg = const_cast<struct sockaddr_in*> (localMsg.getInetAddressPtr());  // 这个可以去掉const属性，但是就可以改变这个值了，不安全
	const struct sockaddr_in* msg =  (localMsg.getInetAddressPtr());
	cout<<"ip:"<<inet_ntoa((msg->sin_addr))<<" port:"<<msg->sin_port<<endl;
	cout<<"listen!"<<endl;
	int newfd = socket.accept();
	meihao::InetAddress peerMsg = meihao::Socket::getLocalAddress(newfd);
	struct sockaddr_in* peermsg = const_cast<struct sockaddr_in*> (peerMsg.getInetAddressPtr());
	cout<<"client ip:"<<inet_ntoa((peermsg->sin_addr))<<" port:"<<peermsg->sin_port<<endl;
	char buf[512] = "hello,world";
	write(newfd,buf,sizeof(buf));
	memset(buf,0,sizeof(buf));
	read(newfd,buf,sizeof(buf));
	cout<<"recv:"<<buf<<endl;
	socket.shutdownWrite();
	cout<<"bye!"<<endl;
	return 0;
}
/*  客户端也是用默认地址，采用的是默认的环回测试地址  */
//ip:0.0.0.0 port:8888
//listen!
//client ip:127.0.0.1 port:8888
//recv:I am client!
//bye!

/*  客户端使用指定ip地址  */
//ip:0.0.0.0 port:8888
//listen!
//client ip:192.168.254.136 port:8888
//recv:I am client!
//bye!


/*  换回测试地址是127.0.0.1~127.255.255.254  */  
//这之间任意一个地址，如果服务器端是默认本地地址，都能连上服务端
//ip:0.0.0.0 port:8888
//listen!
//client ip:127.1.1.1 port:8888
//recv:I am client!
//bye!
