//题目29(第二种做法)：数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
//eg：一个长度为9的数组{1,2,3,2,2,2,5,4,2}.数字2出现了5次，超过数组长度的一半，因此输出2。
//思路：遍历一遍数组，遍历的时候保存两个值：一个是数组中的一个数字，一个是次数。
//当我们遍历到下一个数字的时候，如果下一个数组和我们之前保存的数字相同，则次数加1；
//如果下一个数字和我们之前保存的数字不同，则次数减1；
//如果次数为0，我们就保存下一个数字，并把次数设置为1。由于我们要找到的数字出现的次数比其他所有
//数字出现的次数之和还要多，那么要找到的数字肯定是最后一次把次数设置为1时对应的数字。
#include<iostream>
using namespace std;
int findMoreThanHalt(int* arr,int length);
bool isMoreThanHalt(int* arr,int length,int value);
void test(int* arr,int length);
int main()
{
	int arr[] = {1,1,3,3,2,2,5,4,2};
	test(arr,9);
	cout<<endl;

	int arr1[2] = {1};
	test(arr1,1);
	cout<<endl;

	int* arr3 = NULL;
	test(arr3,0);
	cout<<endl;

	int arr4[] = {1,2,2,2};
	test(arr4,4);
	cout<<endl;

}
void test(int* arr,int length)
{
	int ret = findMoreThanHalt(arr,length);
	cout<<ret<<endl;
}
int findMoreThanHalt(int* arr,int length)
{
	if(NULL==arr||length<=0)
		return -1;
	int times = 1;
	int value = arr[0];
	for(int idx = 1;idx<length;++idx)
	{
		if(times==0)
		{
			value = arr[idx];
			times = 1;
		}
		else if(arr[idx]==value)
			++times;
		else
			--times;
	}
	//检查得到的value是不是过半
	if( isMoreThanHalt(arr,length,value) )
		return value;
	else 
		return -1;
}
bool isMoreThanHalt(int* arr,int length,int value)
{
	 if(NULL==arr)
		 return false;
	 int times=0;
	 for(int idx=0;idx!=length;++idx)
	 {
		 if(arr[idx]==value)
			 ++times;
	 }
	 if(times>length>>1)
		 return true;
	 return false;
}
//-1
//
//1
//
//-1
//
//2
