#if 0
#include<iostream>
using namespace std;
int binarySearch(int* a,int length,int key);
void printArr(int* arr,int length);
void test0()
{
	int a[] = {1,16,24,35,47,59,62,73,88,99};
	printArr(a,10);
	int ret = binarySearch(a,10,62);
	if(-1!=ret)
		cout<<"find idx="<<ret<<" value="<<a[ret]<<endl;
}
int main()
{
	test0();
	system("pause");
}
void printArr(int* arr,int length)
{
	if(nullptr==arr||length<=0)
		return ;
	for(int idx=0;idx!=length;++idx)
	{
		cout<<arr[idx]<<" ";
	}
	cout<<endl;
}
int binarySearch(int* a,int length,int key)
{
	if(nullptr==a||length<=0)
		return -1;
	int left = 0;
	int right = length - 1;
	while(left<=right)
	{
		//int min = (right-left)/2 + left;
		int min = left + (right-left)*((key-a[left])/(a[right]-a[left]));  //差值查找
		if(a[min]>key)
			right = min - 1;
		else if(a[min]<key)
			left = min + 1;
		else
			return min;
	}
	return -1;  //没找到
}
#endif
//1 16 24 35 47 59 62 73 88 99
//find idx=6 value=62
//请按任意键继续. . .