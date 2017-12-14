///
/// @file    memory.cc
/// @author  meihao1203(meihao19931203@outlook.com)
/// @date    2017-12-14 12:40:36
///

#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int a = 0;
char * p1;

int main(void)
{	
	int b;
	char s[] = "123456";
	char * p2;
	const char * p3 = "123456";
	static int c = 0;
	p1 = new char[10];
	p2 = new char[10];
	strcpy(p1, "123456");

	printf("& a = %p\n", &a);  //& a = 0x601068
	printf("&p1 = %p\n", &p1); //&p1 = 0x601070
	printf(" p1 = %p\n", p1);  // p1 = 0x12a6c20
	printf("& b = %p\n", &b);  //& b = 0x7ffc09094d0c
	printf("& s = %p\n", s);   //& s = 0x7ffc09094d20
	printf("&p2 = %p\n", &p2); //&p2 = 0x7ffc09094d10
	printf(" p2 = %p\n", p2);  // p2 = 0x12a6c40
	printf("&p3 = %p\n", &p3); //&p3 = 0x7ffc09094d18
	printf(" p3 = %p\n", p3);  // p3 = 0x400a14
	printf("& c = %p\n", &c);  //& c = 0x60107c

	printf("p3 = %s\n", p3);   //p3 = 123456
	//*p3 = '0';//文字常量区的内容无法修改
	printf("p3 = %s\n", p3);   //p3 = 123456
	return 0;
}

