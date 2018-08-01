#include<iostream>
using namespace std;
//快速排序
#if 0
int partition(int* arr,int left,int right);  //划分数组区间
int quickSort(int* arr,int left,int right);  
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
	quickSort(arr,0,7);
	printArr(arr,8);
	cout<<endl;

	int arr1[] = {1,2,0,-1,5,6,8,3};
	printArr(arr1,8);
	quickSort(arr1,0,7);
	printArr(arr1,8);
	cout<<endl;

	int arr2[] = {2,2,2,2};
	printArr(arr2,4);
	quickSort(arr2,0,3);
	printArr(arr2,4);
	cout<<endl;

	int arr3[] = {2,4,1};
	printArr(arr3,3);
	quickSort(arr3,0,2);
	printArr(arr3,3);
	cout<<endl;

	int arr5[] = {1,2,3,4,5,6,7,8};
	printArr(arr5,8);
	quickSort(arr5,0,7);
	printArr(arr5,8);
	cout<<endl;

	int* arr6 = NULL;
	printArr(arr6,4);
	quickSort(arr6,0,3);
	printArr(arr6,4);
	cout<<endl;
}
void swap(int& elem1,int& elem2)
{
	int tmp = elem1;
	elem1 = elem2;
	elem2 = tmp;
}
int partition(int* arr,int left,int right)
{
	if(NULL==arr||left<0||right<0||left>right)
		return -1;
	int tmp = arr[left];   //基准元素
#if 0
	while(left<right)   //循环结束条件就是 left==right 
	{
		while(left<right&&arr[right]>=tmp)
			--right;
		swap(arr[left],arr[right]);
		while(left<right&&arr[left]<=tmp)
			++left;
		swap(arr[right],arr[left]);
	}
	arr[left] = tmp;
#endif 
	//第二种实现
	while(left<right)
	{
		while(left<right&&arr[right]>=tmp)
			--right;
		if(left<right)  //相等表示已经遍历完毕
			arr[left++] = arr[right];
		while(left<right&&arr[left]<=tmp)
			++left;
		if(left<right)
			arr[right--] = arr[left];
	}
	arr[left] = tmp;
	return left;
}
int quickSort(int* arr,int left,int right)
{
	if(NULL==arr||left<0||right<0||left>right)
		return -1;
	int pos = partition(arr,left,right);
	if(-1==pos)
		return -1;
	quickSort(arr,left,pos-1);
	quickSort(arr,pos+1,right);
	return 0;
}
#endif
//6 5 3 1 8 7 2 4
//1 2 3 4 5 6 7 8
//
//1 2 0 -1 5 6 8 3
//-1 0 1 2 3 5 6 8
//
//2 2 2 2
//2 2 2 2
//
//2 4 1
//1 2 4
//
//1 2 3 4 5 6 7 8
//1 2 3 4 5 6 7 8
