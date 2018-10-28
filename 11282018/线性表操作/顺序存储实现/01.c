//1、从线性表中删除具有最小值的元素，空出的位置由最后一个元素填补
#if 0 
#include<stdio.h>
#include<stdlib.h>
int delMinElement(int* arr,int length)  //成功返回0，失败返回-1
{
	int minFlag = 0;  //c语言变量声明必须在最开头
	int idx = 0;
	if(NULL==arr||length<0)
		return -1;
	for(idx=0;idx<length;++idx)
	{
		if(arr[idx]<arr[minFlag])
			minFlag = idx;
	}
	arr[minFlag] = arr[length-1];
	return 0;
}
void test()
{
	int arr[5] = {2,1,3,5,2};
	int idx = 0;
	delMinElement(arr,sizeof(arr)/sizeof(int));
	for(idx=0;idx<sizeof(arr)/sizeof(int);++idx)
	{
		printf("%d ",arr[idx]);
	}
	printf("\n");
}
int main()
{
	test();
	system("pause");  //stdlib.h
}
#endif
//2 2 3 5 2
//请按任意键继续. . .