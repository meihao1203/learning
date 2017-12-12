#include<stdio.h>
int main()
{
	#ifdef meihao
	printf("define meihao\n");
	#else
	printf("not define meihao\n");
	#endif
	printf("main exit\n");
}
