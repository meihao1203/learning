//1�������Ա���ɾ��������Сֵ��Ԫ�أ��ճ���λ�������һ��Ԫ���
#if 0 
#include<stdio.h>
#include<stdlib.h>
int delMinElement(int* arr,int length)  //�ɹ�����0��ʧ�ܷ���-1
{
	int minFlag = 0;  //c���Ա��������������ͷ
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
//�밴���������. . .