#include<iostream>
using namespace std;
//ºÚµ•—°‘Ò≈≈–Ú
#if 0
int simpleSelectionSort(int* arr,int length);
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
	simpleSelectionSort(arr,8);
	printArr(arr,8);
	cout<<endl;

	int arr1[] = {1,2,3,4,5,6,7,8};
	printArr(arr1,8);
	simpleSelectionSort(arr1,8);
	printArr(arr1,8);
	cout<<endl;

	int arr2[] = {2,2,2,2};
	printArr(arr2,4);
	simpleSelectionSort(arr2,4);
	printArr(arr2,4);
	cout<<endl;

	int arr3[] = {2,2,1,2};
	printArr(arr3,4);
	simpleSelectionSort(arr3,4);
	printArr(arr3,4);
	cout<<endl;

	int* arr4 = NULL;
	printArr(arr4,4);
	simpleSelectionSort(arr4,4);
	printArr(arr4,4);
	cout<<endl;
}
void swap(int& elem1,int& elem2)
{
	int tmp = elem1;
	elem1 = elem2;
	elem2 = tmp;
}
int simpleSelectionSort(int* arr,int length)
{
	if(NULL==arr||length<=0)
		return -1;
	int minPos = 0;
	for(int idx=0;idx!=length;++idx)
	{
		minPos = idx;
		for(int iidx=idx+1;iidx<length;++iidx)
		{
			if(arr[iidx]<arr[minPos])
			{
				minPos = iidx;
			}
		}
		if(idx!=minPos)  
		{
			swap(arr[idx],arr[minPos]);
		}
	}
	return 0;
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
