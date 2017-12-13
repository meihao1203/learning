 ///
 /// @file    extern.cc
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2017-12-13 15:25:22
 ///
 
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
//using std::cout;
//using std::endl;
#ifdef meihao
extern "c"
{
int add(int a,int b)
{
	printf("add(a,b)\n");
	return a+b;
}
}
#endif
int add(int a,int b)
{
	//cout<<"add(a,b)"<<endl;
	return a+b;
}
int main(void)
{
	int a = 3;
	int b = 4;
	printf("a+b=%d\n",add(a,b));
	return 0;
}
