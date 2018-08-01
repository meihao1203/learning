#include<iostream>
using namespace std;
//直接插入排序
#if 1
int straightInsertionSort(int* arr,int length);
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
	straightInsertionSort(arr,8);
	printArr(arr,8);
	cout<<endl;

	int arr1[] = {1,2,0,-1,5,6,7,8};
	printArr(arr1,8);
	straightInsertionSort(arr1,8);
	printArr(arr1,8);
	cout<<endl;

	int arr2[] = {2,2,2,2};
	printArr(arr2,4);
	straightInsertionSort(arr2,4);
	printArr(arr2,4);
	cout<<endl;

	int arr3[] = {2,2,1,2};
	printArr(arr3,4);
	straightInsertionSort(arr3,4);
	printArr(arr3,4);
	cout<<endl;

	int arr5[] = {1,2,3,4,5,6,7,8};
	printArr(arr5,8);
	straightInsertionSort(arr5,8);
	printArr(arr5,8);
	cout<<endl;

	int* arr6 = NULL;
	printArr(arr6,4);
	straightInsertionSort(arr6,4);
	printArr(arr6,4);
	cout<<endl;
}
void swap(int& elem1,int& elem2)
{
	int tmp = elem1;
	elem1 = elem2;
	elem2 = tmp;
}
int straightInsertionSort(int* arr,int length)
{
	if(NULL==arr||length<=0)
		return -1;
	for(int idx=1;idx!=length;++idx)
	{
		//把后面的第idx个元素插入到前面的有序数组0~idx-1中
		int tmp = arr[idx];
		int behindIdx = idx - 1;
		while(behindIdx>=0&&arr[behindIdx]>tmp)  	
		{
			arr[behindIdx+1] = arr[behindIdx];
			--behindIdx;
		}
		arr[++behindIdx] = tmp;
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
