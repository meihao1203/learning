//2�������Ա���ɾ����ֵ�ڸ���ֵs��t֮�������Ԫ��
#include<stdio.h>
#include<stdlib.h>
int delRangeElement(int* arr,int length,int s,int t)
{//ɾ��һ��Ԫ�أ��ٶ������������Ԫ�ص�ֵΪ-1��
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
//2 1 5 2
//�밴���������. . .
