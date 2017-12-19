///
/// @file    test.cpp
/// @author  meihao1203(meihao19931203@outlook.com)
/// @date    2017-12-19 16:35:03
///

#include<iostream>
using namespace std;
struct abc
{
	int a;
	char b;
	float c;
	double d;
	short e;
	char * f;   //64位操作系统，指针8字节
	//double * g;
}mh;
int main()
{
	cout<<sizeof(char*)<<endl;
	cout<<sizeof(mh)<<endl;
}

