 ///
 /// @file    io3.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2017-12-24 09:18:30
 ///
 
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main()
{
	ifstream ifs("file");   //要求文件事先存在
	if(!ifs.good())
	{
		perror("ifs");
		return -1;
	}
	ofstream ofs("file.bat");   //不要求文件事先存在
	if(!ofs.good())
	{
		perror("ofs");
		return -1;
	}
	string str;
	while(getline(ifs,str))		//getline()不会读入换行,只读文本字符串
	{
		ofs<<str<<endl; 
	}
	ifs.close();
	ofs.close();
	return 0;
}
