//5、约瑟夫问题的顺序存储解决方法
#include<stdio.h>
#include<stdlib.h>
int joseph(int* arr,int length,int m)
{
	int len = length;
	int idx = 0;
	int mIdx = 0;
	if(NULL==arr||length<0)
		return -1;
	while(len>1)
	{
		mIdx = 0;
		for(;;++idx)
		{
			if(idx>=length)
				idx = 0;
			if(arr[idx]!=-1)
				++mIdx;
			if(mIdx == m)
			{
				--len;
				arr[idx++] = -1;
				break;
			}	
		}
	}
	for(idx=0;idx<length;++idx)
		if(arr[idx]!=-1)
			break;
	return idx;
}
void test()
{
	int arr[5] = {2,1,3,5,2};
	int idx = 0;
	int ret = joseph(arr,sizeof(arr)/sizeof(int),3);
	printf("%d \n",arr[ret]);
}
int main()
{
	test();
	system("pause");  //stdlib.h
}
//5
//请按任意键继续. . .