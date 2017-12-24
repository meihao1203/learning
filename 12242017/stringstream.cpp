 ///
 /// @file    stringstream.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2017-12-24 10:18:00
 ///
 
#include<iostream>
#include<sstream>
#include<stdio.h>
using namespace std;
void sprint(int a,int b)
{
	char arr[1024] = {0};
	sprintf(arr,"%d,%d",a,b);
	cout<<arr<<endl;
}
string test0(int a,int b)
{
	ostringstream oss;
	//stringstream oss;   //一样的效果
	oss<<a<<","<<b;
	return oss.str();
}
void test1(string line)
{
	istringstream iss(line);
	//stringstream iss(line);
	string tmp;
	while(!iss.eof())
	{
		tmp = "";
		iss>>tmp;
		cout<<tmp<<endl;
	}

}
int main()
{
	int a = 512;
	int b = 1024;
	sprint(a,b);

	string str1;
	str1 = test0(a,b);
	cout<<str1<<endl;

	string str2 = "I have a dream!";
	test1(str2);
}
//512,1024
//512,1024
//I
//have
//a
//dream!
