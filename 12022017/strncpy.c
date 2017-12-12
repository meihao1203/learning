#include<stdio.h>
#include<string.h>
//char *strncpy(char *dest, const char *src, size_t n);
int main()
{
	char name[10] = {0};
	char *passwd = "123456";
	strncpy(name,passwd,3);
	printf("%s\n",name);  //123
	return 0;
}