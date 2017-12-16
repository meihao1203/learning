#include<iostream>
#include<stdlib.h>
using namespace std;
int main5(void)
{
	const char *p1 = "hello";
	char * const p2 = "world";
	p1++;
	//p1[2] = 'w';
	p2[2] = 'l';
	//p2++;
	system("pause");
	return 0;
}