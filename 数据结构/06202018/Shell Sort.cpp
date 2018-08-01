#include<iostream>
using namespace std;
//直接插入排序改进版，希尔排序
#if 0
int shellSort(int* arr,int length);
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
	shellSort(arr,8);
	printArr(arr,8);
	cout<<endl;

	int arr1[] = {1,2,0,-1,5,6,7,8};
	printArr(arr1,8);
	shellSort(arr1,8);
	printArr(arr1,8);
	cout<<endl;

	int arr2[] = {2,2,2,2};
	printArr(arr2,4);
	shellSort(arr2,4);
	printArr(arr2,4);
	cout<<endl;

	int arr3[] = {2,2,1,2};
	printArr(arr3,4);
	shellSort(arr3,4);
	printArr(arr3,4);
	cout<<endl;

	int arr5[] = {1,2,3,4,5,6,7,8};
	printArr(arr5,8);
	shellSort(arr5,8);
	printArr(arr5,8);
	cout<<endl;

	int* arr6 = NULL;
	printArr(arr6,4);
	shellSort(arr6,4);
	printArr(arr6,4);
	cout<<endl;
}
void swap(int& elem1,int& elem2)
{
	int tmp = elem1;
	elem1 = elem2;
	elem2 = tmp;
}
int shellSort(int* arr,int length)
{
	if(NULL==arr||length<=0)
		return -1;
	for(int gap=length/2;gap>0;gap/=2)  //步长从length/2开始
	{
		for(int idx=gap;idx!=length;++idx)  //直接插入排序 
		{
			for(int iidx=idx-gap;iidx>=0&&arr[iidx]>arr[iidx+gap];iidx-=gap)
			{
				swap(arr[iidx],arr[iidx+gap]);  //因为直接插入排序，前面的数组都是有序的了，可以用交换代替数据移动.
			}
		}
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
