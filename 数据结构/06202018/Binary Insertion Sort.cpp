#include<iostream>
using namespace std;
//直接插入排序改进，二分插入排序
//对左边已经排好序的序列使用二分查找，找到右边序列待插入元素要插入的位置，然后在整体移动
#if 1
void test();
void printArr(int* arr,int length);
int binaryInsertionSort(int* arr,int length);
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
	binaryInsertionSort(arr,8);
	printArr(arr,8);
	cout<<endl;

	int arr1[] = {1,2,0,-1,5,6,7,8};
	printArr(arr1,8);
	binaryInsertionSort(arr1,8);
	printArr(arr1,8);
	cout<<endl;

	int arr2[] = {2,2,2,2};
	printArr(arr2,4);
	binaryInsertionSort(arr2,4);
	printArr(arr2,4);
	cout<<endl;

	int arr3[] = {2,2,1,2};
	printArr(arr3,4);
	binaryInsertionSort(arr3,4);
	printArr(arr3,4);
	cout<<endl;

	int arr5[] = {1,2,3,4,5,6,7,8};
	printArr(arr5,8);
	binaryInsertionSort(arr5,8);
	printArr(arr5,8);
	cout<<endl;

	int* arr6 = NULL;
	printArr(arr6,4);
	binaryInsertionSort(arr6,4);
	printArr(arr6,4);
	cout<<endl;
}
int binaryInsertionSort(int* arr,int length)
{
	if(NULL==arr||length<=0)
		return -1;
	for(int idx=1;idx!=length;++idx)
	{
		int tmp = arr[idx];
		int left = 0;
		int right = idx-1;
		int middle;
		while(left<=right)
		{
			middle = (left+right)/2;
			if(arr[middle]<=tmp)  //稳定排序
				left = middle + 1;
			else if(arr[middle]>tmp)
				right = middle - 1;
		}
		for(int iidx=idx-1;iidx>=left;--iidx)
		{
			arr[iidx+1] = arr[iidx];
		}
		arr[left] = tmp;
	}
	return 0;
}
#endif
//6 5 3 1 8 7 2 4
//1 2 3 4 5 6 7 8
//
//1 2 0 -1 5 6 7 8
//-1 0 1 2 5 6 7 8
//
//2 2 2 2
//2 2 2 2
//
//2 2 1 2
//1 2 2 2
//
//1 2 3 4 5 6 7 8
//1 2 3 4 5 6 7 8
//
