 ///
 /// @file    io1.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2017-12-24 08:48:09
 ///
 
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main(void)
{
	ifstream ifs("file");  //文件必须存在
	if(!ifs.good())
	{
		perror("ifstrem");
		return -1;
	}
	string str;
	while(!ifs.eof())
	{
		str = "";   //清空str
		ifs>>str;
		cout<<str<<endl;
	}
	ifs.close();
	return 0;
}
//hello,world
//meihao
//12242017
//
