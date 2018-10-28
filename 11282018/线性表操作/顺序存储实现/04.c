//从线性表中删除所有值重复的元素
#if 0
#include<stdio.h>
#include<stdlib.h>
int delRepeat(int* arr,int length)
{
	int idx1 = 0,idx2 = 0;
	int tmp = 0;
	bool flag = false;
	if(NULL==arr||length<0)
		return -1; 
	for(idx1 = 0;idx1<length;++idx1)
	{
		tmp = arr[idx1];	
		flag = false;
		for(idx2 = idx1+1;idx2<length;++idx2)
		{
			if(tmp == -1)
				break;
			if(tmp==arr[idx2])  
			{
				flag = true;
				arr[idx2] = -1;  //删除
			}	
		}
		if(flag)
			arr[idx1] = -1;
	}
	return 0;
}
void test()
{
	int arr[5] = {2,1,3,5,2};
	int idx = 0;
	delRepeat(arr,sizeof(arr)/sizeof(int));
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
//1 3 5
//请按任意键继续. . .