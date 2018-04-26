 ///
 /// @file    strlen.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-04-26 08:50:20
 ///
 
#include<iostream>
#include<string>
#include<string.h>
using namespace std;
int main()
{
	string s1 = "hello";
	cout<<strlen(s1.c_str())<<endl;  // 5
	char* s2 = new char[strlen(s1.c_str())+2];
	strcpy(s2,s1.c_str());
	s2[strlen(s1.c_str())+1] = '1';
	cout<<s2<<endl;  // 前面没有+1，hello后面加一个异常符号
	cout<<s2[strlen(s1.c_str())+1]<<endl;  // 1
	return 0;
}
//5
//hello
//1
