 ///
 /// @file    sizeofArr_strlenArr.cc
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-07-13 10:08:56
 ///
 
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	char buf[] = "hello,world!";
	char* buf2 = "meihao";
	int a[3] = {1,2,3};
	int* a2 = (int*)malloc(4*sizeof(int));
	printf("%d %d\n",sizeof(buf),strlen(buf));
	printf("%d %d\n",sizeof(buf2),strlen(buf2));
	printf("%d %d\n",sizeof(a),sizeof(a)/sizeof(int));
	printf("%d %d\n",sizeof(a2),sizeof(a2)/sizeof(int));  //sizeof(a2)=8
}
//13 12
//8 6
//12 3
//8 2
