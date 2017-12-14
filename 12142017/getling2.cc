 ///
 /// @file    getling.c
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2017-12-14 08:22:38
 ///
 
#include<iostream>
#include<string>
#include<stdlib.h>
using std::cout;
using std::endl;
using std::string;
using std::cin;
int main(void)
{
	char *p = (char*)malloc(5*sizeof(char));
	cout<<"cin.good()="<<cin.good()<<endl;
	cin.getline(p,10);   //超出数组大小,输入流会异常
	cout<<"cin.good()="<<cin.good()<<endl;   //异常，cin.good()=0
	string s;
	getline(cin,s);
	cout<<"s="<<s<<endl;
	return 0;
}
