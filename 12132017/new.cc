 ///
 /// @file    new.cc
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2017-12-13 15:06:50
 ///
 //malloc是库函数，它只负责开辟空间
 //该空间的内容是不确定的并不会初始化
 //free进行释放
 //
 //new是一个表达式，它负责开辟空间，并且
 //能够初始化该空间的内容的
 //delete 进行释放
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using std::cout;
using std::endl;
int main(void)
{
	int *p = (int*)malloc(sizeof(int));
	cout<<"p="<<p<<endl;	//p=0x18adc20
	cout<<"*p="<<*p<<endl;	//*p=0
	*p = 12;
	cout<<"*p="<<*p<<endl;  //*p=12
	free(p);

	int *p1 = new int[10]();
	for(int i=0;i!=10;i++)
	{
		cout<<p1[i]<<" ";
	}
	cout<<endl;
	delete []p1;

	int *p2 = new int[10];
	for(int i=0;i!=10;i++)
	{
		cout<<p2[i]<<" ";
	}
	cout<<endl;   //全部都是0
	delete []p2;

	return 0;
}

