//题目30：输入n个整数，找出其中最小的k个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数组是1,2,3,4
//思路：利用快速排序思想，找个第k个位置的元素后，k前面的元素都比k小，输出就行;
//这种解法会改变数组,复杂度O(n)
#if 0
#include<iostream>
using namespace std;
void findLeastElements(int* arr,int length,int k);
int divide(int* arr,int left,int right);
void test(int* arr,int length,int k);
int main()
{
	int arr[] = {4,5,1,6,2,7,3,8};
	test(arr,8,4);
	cout<<endl;

	int arr2[] = {1,2,3,4};
	test(arr2,4,2);
	cout<<endl;

	int* arr3 = NULL;
	test(arr3,0,0);
	cout<<endl;

	int arr4[] = {1,2,3,4};
	test(arr2,4,3);
	cout<<endl;
	system("pause");
}
void test(int* arr,int length,int k)
{
	findLeastElements(arr,length,k);
}
void findLeastElements(int* arr,int length,int k)
{
	if(NULL==arr||length<=0||k>length||k<=0)
	{
		cout<<"input error!"<<endl;
		return;
	}
	int index = divide(arr,0,length-1);
	if(index!=k-1&&index!=-1)
	{
		if(index<k-1)
		{
			divide(arr,index+1,length-1);
		}
		else 
		{
			divide(arr,0,index-1);
		}
	}
	for(int idx=0;idx!=k;++idx)
	{
		cout<<arr[idx]<<" ";
	}
	cout<<endl;
}
int divide(int* arr,int left,int right)
{
	if(NULL==arr||left>=right||left<0||right<0)
		return -1;
	int pivot = arr[left];
	while(left!=right)
	{
		while(left<right&&arr[left]<=pivot)
			++left;
		arr[right] = arr[left];
		while(left<right&&arr[right]>=pivot)
			--right;
		arr[left] = arr[right];
	}
	return left;
}
#endif
//4 3 1 2
//
//1 2
//
//input error!
//
//1 2 3

