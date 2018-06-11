//题目38：数字在排序数组中出现的次数，统计一个数字在排序数组中出现的次数。
//例如输入排序数组{1,2,3,3,3,3,4,5}和数字3，由于3在这个数组中出现了4次，因此输出4。
//思路：由于数组是排序的，可以使用二分查找，先找第一个k出现的位置，然后再找第二个k出现的位置。
#include<iostream>
using namespace std;
int getFirstK(int* arr,int start,int end,int elem);
int getLastK(int* arr,int start,int end,int elem);
int appearTimes(int* arr,int length,int elem);
void test(int* arr,int length,int elem);
void test0();  //正常输入
void test1();  //指定输入没有
void test2();  //一个元素数组
void test3();  //空指针
int main()
{
	test0();
	test1();
	test2();
	test3();
	system("pause");
}
void test(int* arr,int length,int elem)
{
	int cnt = appearTimes(arr,length,elem);
	cout<<elem<<" appear "<<cnt<<" times."<<endl;
}
void test0()
{
	int arr[] = {1,2,3,3,3,3,4,5};
	for(int idx=0;idx!=8;++idx)
		cout<<arr[idx]<<" ";
	cout<<endl;
	test(arr,8,3);
}
void test1()
{
	int arr[] = {1,2,3,3,3,3,4,5};
	for(int idx=0;idx!=8;++idx)
		cout<<arr[idx]<<" ";
	cout<<endl;
	test(arr,8,6);
}
void test2()
{
	int arr[] = {1};
	for(int idx=0;idx!=1;++idx)
		cout<<arr[idx]<<" ";
	cout<<endl;
	test(arr,1,1);
}
void test3()
{
	int* arr = NULL;
	test(arr,0,0);
}
int appearTimes(int* arr,int length,int elem)
{
	if(NULL==arr||length<=0)
		return -1;  //错误输入返回-1
	int middle = (length-1)>>1;
	int start = 0;
	int end = length - 1;
	int firstK = getFirstK(arr,start,middle,elem);
	int lastK = getLastK(arr,middle+1,end,elem);
	if(firstK!=-1&&lastK!=-1)  //出现多次
		return lastK - firstK + 1;
	else if(firstK!=-1||lastK!=-1)  //出现一次
		return 1;
	else   //出现0次
		return 0;
}
int getFirstK(int* arr,int start,int end,int elem)
{
	if(NULL==arr||start>end||start<0||end<0)
		return -1;
	int middleIndex = ((end - start)>>1) + start;
	int tmpStart = start;
	int tmpEnd = end;
	if(arr[middleIndex]==elem)
	{
		if((middleIndex>start&&arr[middleIndex-1]!=elem)||
			middleIndex==start)
			return middleIndex;
		else
			tmpEnd = middleIndex - 1;
	}
	else if(arr[middleIndex]>elem) //在前半部分
	{
		tmpEnd = middleIndex - 1;
	}
	else
	{
		tmpStart = middleIndex + 1;
	}
	return getFirstK(arr,tmpStart,tmpEnd,elem);
}
int getLastK(int* arr,int start,int end,int elem)
{
	if(NULL==arr||start>end||start<0||end<0)
		return -1;
	int middleIndex = ((end - start)>>1) + start;
	int tmpStart = start;
	int tmpEnd = end;
	if(arr[middleIndex]==elem)
	{
		if((middleIndex<end&&arr[middleIndex+1]!=elem)||
			middleIndex==end)
			return middleIndex;
		else
		{
			tmpEnd = middleIndex + 1;
		}
	}
	else if(arr[middleIndex]>elem)
	{
		tmpEnd = middleIndex - 1;
	}
	else
	{
		tmpStart = middleIndex + 1;
	}
	return getLastK(arr,tmpStart,tmpEnd,elem);
}
//1 2 3 3 3 3 4 5
//3 appear 4 times.
//1 2 3 3 3 3 4 5
//6 appear 0 times.
//1
//1 appear 1 times.
//0 appear -1 times.
