#include<iostream>
using namespace std;
#if 0
//冒泡排序，加上改进优化
int bubbleSort(int* arr,int length);  //成功返回0，失败返回-1
void swap(int& elem1,int& elem2);
void test();
void printArr(int* arr,int length);
int main()
{
	test();
	system("pause");
}
void printArr(int* arr,int length)
{
	if(NULL==arr||length<=0)
		return ;
	for(int idx=0;idx!=length;++idx)
	{
		cout<<arr[idx]<<" ";
	}
	cout<<endl;
}
void test()
{
	int arr[] = {6,5,3,1,8,7,2,4};
	printArr(arr,8);
	bubbleSort(arr,8);
	printArr(arr,8);
	cout<<endl;

	int arr1[] = {1,2,3,4,5,6,7,8};
	printArr(arr1,8);
	bubbleSort(arr1,8);
	printArr(arr1,8);
	cout<<endl;

	int arr2[] = {2,2,2,2};
	printArr(arr2,4);
	bubbleSort(arr2,4);
	printArr(arr2,4);
	cout<<endl;

	int arr3[] = {2,2,1,2};
	printArr(arr3,4);
	bubbleSort(arr3,4);
	printArr(arr3,4);
	cout<<endl;

	int* arr4 = NULL;
	printArr(arr4,4);
	bubbleSort(arr4,4);
	printArr(arr4,4);
	cout<<endl;
}
int bubbleSort(int* arr,int length)
{
	if(NULL==arr||length<=0)
		return -1;
	int swapFlag = true;
	for(int idx=0;idx!=length&&swapFlag;++idx)
	{
		swapFlag = false;  //初始为false
		for(int iidx=0;iidx!=(length - 1 - idx);++iidx)  //每一次都会冒泡选择出一个最大的元素放在最后的位置
		{  //(length - 1 - idx)因为每次都是iidx和iidx+1相比较
			if(arr[iidx]>arr[iidx+1])   
			{
				swap(arr[iidx],arr[iidx+1]);
				swapFlag = true;  //发送元素交换，改成true
			}
		}
	}
	return 0;
}
void swap(int& elem1,int& elem2)
{
	int tmp = elem1;
	elem1 = elem2;
	elem2 = tmp;
}
#endif
//6 5 3 1 8 7 2 4
//1 2 3 4 5 6 7 8
//
//1 2 3 4 5 6 7 8
//1 2 3 4 5 6 7 8
//
//2 2 2 2
//2 2 2 2
//
//2 2 1 2
//1 2 2 2
//
