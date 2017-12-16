#include<iostream>
#include<stdlib.h>
int main3(void)
{
	char * s1 = "Hello world";  //const char *
	char s2[] = "Hello world";
	//s1[2] = 'E';      //1  
	s2[2] = 'E';      //2
	//*(s1 + 2) = 'E';  //3
	*(s2 + 2) = 'E';  //4
	system("pause");
	return 0;
}