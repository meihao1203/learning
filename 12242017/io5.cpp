 ///
 /// @file    io5.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2017-12-24 09:59:09
 ///
 
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
int main(void)
{
	fstream io("test");   //要求文件事先存在,因为fstream对象可以读,也可以写
	if(!io.good())
	{
		perror("io");
		return -1;
	}
	cout<<"io.tellp()="<<io.tellp()<<endl;
	for(int i=0;i!=10;++i)
	{
		cout<<"i = "<<i<<endl;
		io<<i<<endl;
	}
	cout<<"io.tellp()="<<io.tellp()<<endl;
	io.seekp(0,ios::beg);
	cout<<"after seekp,io.tellp()="<<io.tellp()<<endl;
	int num;
	for(int i=0;i!=10;++i)
	{
		io>>num;
		cout<<num<<"	";
	}
	cout<<endl;
	io.close();
	return 0;
}
//io.tellp()=0
//i = 0
//i = 1
//i = 2
//i = 3
//i = 4
//i = 5
//i = 6
//i = 7
//i = 8
//i = 9
//io.tellp()=20
//after seekp,io.tellp()=0
//0	1	2	3	4	5	6	7	8	9	
