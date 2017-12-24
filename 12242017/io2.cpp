 ///
 /// @file    io2.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2017-12-24 08:59:09
 ///

#include<iostream>
#include<fstream>
#include<vector>
#include<string>
using namespace std;
int main(void)
{
	ifstream ifs("file"); 
	if(!ifs.good())
	{
		perror("ifstrem");
		return -1;
	}
	vector<string> ver;
	ver.reserve(10);   //事先开辟空间
	string str;
	while(!ifs.eof())
	{
		str = "";
		ifs>>str;
		ver.push_back(str);
	}
	//c++11新标准，编译要加上-std=c++11
	for(auto &elem:ver)
	{
		cout<<elem<<endl;
	}
	while(1);
	ifs.close();
	return 0;
}
