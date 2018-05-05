 ///
 /// @file    test.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-05-04 16:00:43
 ///
 
#include"InetAddress.h"
#include"Socket.h"
#include"SocketIO.h"
#include"TcpConnection.h"
#include<iostream>
using namespace std;
int main()
{
	meihao::InetAddress inetAddr(8888);
	meihao::Socket socket;
	socket.ready(inetAddr);  // 开启服务器端口

	int newfd = socket.accept();
	meihao::TcpConnection tcpCon(newfd);
	tcpCon.send("I am server!\n");
	string msg = tcpCon.receive();
	cout<<msg<<endl;
	//tcpCon.shutdown();  // 这里看了返回值，确实成功关闭了连接到服务器的客户端
	//Socket提供两种构造函数，第二种就是直接给定一个描述符，
	//TcpConnection类里面就用了第二个构造函数，所以调用shutdown的时候关闭的是传递进去的描述符
	//虽然看上去有点不合逻辑，算了，就这么用吧
#if 1
// 带回来测试shutdown
	while(true)
	{
		string msg = tcpCon.receive();
		cout<<msg<<endl;
		tcpCon.send(msg);
	}
#endif
	return 0;
}
//this is client!
//mei

/* 这是不要shutdown的正常模式 */
//this is client!
//mei
//hao
//hello
//world
