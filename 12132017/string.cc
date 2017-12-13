 ///
 /// @file    string.cc
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2017-12-13 17:12:47
 ///
 
#include<iostream>
#include<string>
#include<string.h>
using std::cout;
using std::endl;
using std::string;
int test01(void)
{	
	string s1 = "hello";
	string s2 = ",world";
	string s3 = s1+s2+"~meihao";
	cout<<"s3="<<s3<<endl;
	cout<<"sizeof(s3)="<<sizeof(s3)<<endl;   //32,不能用了
	cout<<"s3.size()="<<s3.size()<<endl;      //18

	string s4 = "hello,world";
	string s5 = s4.substr(0,5);
	cout<<"s5="<<s5<<endl;
	string s6 = s4.substr(s4.find("world"),5);
	cout<<"s6="<<s6<<endl;

	for(int idx=0;idx!=s4.size();idx++)
	{
		cout<<s4[idx];   //hello,world
		s4[idx] += 1;    //确实改变了s4的值
	}
	cout<<endl;
	cout<<"now s4 ="<<s4<<endl;
	
	s4 = "hello,world";
	string::iterator it = s4.begin();   //[)
	for(;it != s4.end();it++)
	{
		cout<<*it;
	}
	cout<<endl;
	return 0;
}
int main(void)
{
	char str1[] = "hello,world~meihao";     //'\0'
	cout<<"sizeof(str1)"<<sizeof(str1)<<endl;  //19
	cout<<"strlen(str1)"<<strlen(str1)<<endl;  //18
	for(int idx=0;idx<strlen(str1);idx++)
	{
		cout<<str1[idx];
	}
	cout<<endl;

	char str2[] = "hello";
	char str3[] = ",world";
	char *str4 = new char[strlen(str2)+strlen(str3)+1];
	strcpy(str4,str2);
	strcat(str4,str3);
	cout<<"str4="<<str4<<endl;   //str4=hello,world
	delete []str4;

	char str5[] = "hello,world";
	char *str6 = new char[strlen("world")+1];
	char *str7 = strstr(str5,"world");
	strcpy(str6,str7);
	cout<<"str6="<<str6<<endl;   //str6=world
	cout<<"str7="<<str7<<endl;   //str7=world
	return 0;
}
