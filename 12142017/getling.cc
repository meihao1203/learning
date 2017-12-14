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
#if 0
	char *p = (char*)malloc(sizeof(char)*100);
	cin.getline(p,10);   //10个字符大小还要算上'\0';
	cout<<"p="<<p<<endl;
	return 0;
#endif 
	string s;
	while(getline(cin,s))
		cout<<"s="<<s<<endl;
}
