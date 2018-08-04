#include<iostream>
using namespace std;
//题目14：调整数组顺序使奇数位于偶数前面
//不单单只是实现功能，可以考虑扩展性和可重用性
//解耦
int partitionArrOddEven(int* arr,int length);
int partitionArr(int* arr,int length);
bool judge(int pos);  //判断是不是奇数
void test(int* arr,int length);
#if 0
int main()
{
	int arr[] = {1,5,3,4,2};
	int arr1[2] = {2,1};
	test(arr,5);
	test(arr1,2);
	test(arr1,0);
	test(NULL,2);  //待会看传值的时候是不是NULL
	system("pause");
}
#endif
int partitionArrOddEven(int* arr,int length)
{
	if(NULL==arr||length<=0)
		return -1;
	int* pHead = arr;
	int* pTail = arr + length - 1;
	while(pHead<pTail)
	{
		while(pHead<pTail && judge(*pHead))  //前面指针指向的是奇数，满足要求，++
			pHead++;
		while(pHead<pTail && !judge(*pTail))  //后面指针指向的是偶数，满足要求，--
			pTail--;
		if(pHead<pTail)
		{
			int tmp = *pHead;
			*pHead = *pTail;
			*pTail = tmp;
		}
	}
	return 0;
}
bool judge(int pos)
{
	return (pos&1) == 1;
}
int partitionArr(int* arr,int length)
{
	int ret = partitionArrOddEven(arr,length);
	return ret;
}
void test(int* arr,int length)
{
	int ret = partitionArr(arr,length);
	if(-1==ret)
		return ;
	for(int idx=0;idx!=length;++idx)
		cout<<arr[idx]<<"\t";
	cout<<endl;
}