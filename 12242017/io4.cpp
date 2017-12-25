 ///
 /// @file    io4.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2017-12-24 09:30:02
 ///
 
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
int main()
{
	//ofstream out("file.bat",ios::ate);    //打开文件并定位到文件末尾;
	//验证：并不能定位到文件尾,直接打开文件，然后删除了文件原有的信息
	//ios::ate只对输入流起作用
	ofstream out("file.bat",ios::app);
	if(!out.good())
	{
		perror("out");
		return -1;
	}
	string str = "I am meihao.";
	cout<<"current file position:"<<out.tellp()<<endl;  //tellp()和tellg()一个是ifstream对象特有，一个是ofstream对象特有
	out<<str<<endl;
	cout<<"current file position:"<<out.tellp()<<endl;
	out.close();
	return 0;
}
//current file position:0
//current file position:12
//
//
//current file position:29
//current file position:42
