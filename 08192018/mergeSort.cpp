//归并排序，一般的空间复杂度都是O(n)，现在要O(1)
#include<iostream>
using namespace std;
void swap(int& a,int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
	return ;
}
void reverse(int* arr,int len)  //len个元素的数组逆序
{
	if(NULL==arr)
		return ;
	int first = 0,end = len-1;
	while(first<end)
	{
		swap(arr[first++],arr[end--]);
	}
	return ;
}
void printArr(int* arr,int len)
{
	if(NULL==arr)
		return ;
	for(int idx=0;idx!=len;++idx)
	{
		cout<<arr[idx]<<" ";
	}
	cout<<endl;
	return;
}
void moveLeft(int* arr,int len,int cnt) //arr数组，长度len，左移cnt个元素
{
	if(NULL==arr||len<=0)
		return ;
	reverse(arr,cnt);     // 1 2 3 4 5 ,左移3个位置，arr，5,3
	reverse(arr+cnt,len-cnt);
	reverse(arr,len);
}
void mergeArr(int* arr,int first,int mid,int end)
{
	if(NULL==arr||first>end||mid>end)
		return ;
	int second = mid + 1;
	while(first<=mid&&second<=end)
	{
		int secondLow = 0;
		while(first<=mid&&arr[first]<=arr[second])
			++first;
		while(second<=end&&arr[second]<=arr[first])
		{
			++second;
			++secondLow;
		}
		moveLeft(arr+first,second-first,second - first - secondLow);
		first += secondLow;
	}
	return ;
}
void mergeSort(int* arr,int first,int end)
{
	if(NULL==arr)
		return;
	if(first<end)
	{
		int mid = (first + end)/2;
		mergeSort(arr,first,mid);
		mergeSort(arr,mid+1,end);
		//归并
		mergeArr(arr,first,mid,end);
	}
}
int main(int argc,char** argv)
{
	int arr[] = {6,4,3,1,7,8,2,9,5,0};
	mergeSort(arr,0,9);
	printArr(arr,10);
	system("pause");
}
//0 1 2 3 4 5 6 7 8 9
//请按任意键继续. . .