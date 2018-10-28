//将两个有序线性表合并为一个
#if 0
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXSIZE 512
static int mergeArr[MAXSIZE];
int mergeOrderList(int* arr1,int length1,int* arr2,int length2)
{
	int idx1 = 0,idx2 = 0,idx3 = 0;
	memset(mergeArr,-1,sizeof(mergeArr));  //数组mergeArr全部置-1
	if(NULL==arr1||NULL==arr2||length1<0||length2<0)
		return -1;
	while(idx1<length1&&idx2<length2)
	{
		if(arr1[idx1]>arr2[idx2])
			mergeArr[idx3++] = arr2[idx2++];
		else
			mergeArr[idx3++] = arr1[idx1++];
	}
	while(idx1<length1)
		mergeArr[idx3++] = arr1[idx1++];
	while(idx2<length2)
		mergeArr[idx3++] = arr2[idx2++];
	return 0;
}
void test()
{
	int arr1[5] = {1,2,5,7,8};
	int arr2[4] = {1,3,4,6};
	int idx = 0;
	mergeOrderList(arr1,sizeof(arr1)/sizeof(int),arr2,sizeof(arr2)/sizeof(int));
	for(idx=0;idx<MAXSIZE;++idx)
	{
		if(-1==mergeArr[idx])
			break;
		printf("%d ",mergeArr[idx]);
	}
	printf("\n");
}
int main()
{
	test();
	system("pause");  //stdlib.h
}
#endif
//1 1 2 3 4 5 6 7 8
//请按任意键继续. . .