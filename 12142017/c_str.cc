 ///
 /// @file    c_str.c
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2017-12-14 08:58:54
 ///
 
#include<iostream>
#include<string>
#include<string.h>
using namespace std;
int main(void)
{
	string s;
	getline(cin,s);
	cout<<"s="<<s<<endl;
	char *p = new char[100]();
	strcpy(p,s.c_str());
	cout<<"p="<<p<<endl;

	string s1 = "hello";
	string s2 = "world";
	if(s1==s2)
	{
		cout<<"s1=s2"<<endl;
	}
	return 0;
}
