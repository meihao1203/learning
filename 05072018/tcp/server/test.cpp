 ///
 /// @file    test.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-05-04 16:00:43
 ///
 
#include"InetAddress.h"
#include"Socket.h"
#include"SocketIO.h"
#include<iostream>
#include<strings.h>
#include<string.h>
using namespace std;
int main()
{
	meihao::InetAddress inetAddr(8888);
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
	char buf[512] = "I am server!\n";
	sockio.writen(buf,strlen(buf));
	bzero(buf,sizeof(buf));
	sockio.readline(buf,sizeof(buf));
	cout<<buf;  //读一行自带回车
	//最后结果及时对端输入
#if 1
	while(true)
	{

	}
#endif
	return 0;
}

