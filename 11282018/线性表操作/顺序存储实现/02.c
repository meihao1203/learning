//2、从线性表中删除其值在给定值s与t之间的所有元素
#if 0
#include<stdio.h>
#include<stdlib.h>
int delRangeElement(int* arr,int length,int s,int t)
{//删除一个元素，假定就是设置这个元素的值为-1。
	int idx = 0;
	if(NULL==arr||length<0||s>=t)
		return -1;
	for(idx=0;idx<length;++idx)
	{
		if(arr[idx]>s&&arr[idx]<t)
			arr[idx] = -1;
		else
			continue;
	}
	return 0;
}
void test()
{
	int arr[5] = {2,1,3,5,2};
	int idx = 0;
	delRangeElement(arr,sizeof(arr)/sizeof(int),2,4);
	for(idx=0;idx<sizeof(arr)/sizeof(int);++idx)
	{
		if(-1!=arr[idx])
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
//2 1 5 2
//请按任意键继续. . .