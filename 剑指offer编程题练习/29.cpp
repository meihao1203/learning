//题目29：数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
//eg：一个长度为9的数组{1,2,3,2,2,2,5,4,2}.数字2出现了5次，超过数组长度的一半，因此输出2。
//思路：快速排序思想，先划分数组，每一个划分都能确定一个值的最终位置，如果这个位置是最中间的就停止划分
//最后再遍历数组，判断这个中间值是不是出现的次数超过数组长度的一半
#include<iostream>
using namespace std;
int divide(int* arr,int left,int right);  //划分区间，类似快拍的划分
int moreThanHalf(int* arr,int length);
bool judgeMoreThenHalf(int* arr,int length,int number);  //判断得到的元素是不是真的过半
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
	int ret= moreThanHalf(arr,length);
	cout<<ret<<endl;
}
int moreThanHalf(int* arr,int length)
{
	if(NULL==arr||length<=0)
		return -1;
	int middle = length>>1;
	int left = 0,right = length - 1;
	int index = divide(arr,left,right);
	while(index!=middle&&index!=-1)
	{
		if(index>middle)
		{
			right = index - 1;
			index = divide(arr,left,right);
		}
		else
		{
			left = index + 1;
			index = divide(arr,left,right);
		}
	} //出while循环，找到排序数组中的中间值
	int result = arr[middle];
	//判断这个值到底是不是出现了过半次数
	if(!judgeMoreThenHalf(arr,length,result))
		result = 0;
	return result;
}
bool judgeMoreThenHalf(int* arr,int length,int number)
{
	if(NULL==arr)
		return false;
	int times = 0;
	for(int idx=0;idx<length;++idx)
	{
		if(arr[idx]==number)
			times++;
	}
	if(times>=length>>1)
		return true;
	return false;
}
int divide(int* arr,int left,int right)
{
	if(NULL==arr||left>right)
		return -1;
	if(left==right)
		return left;
	int dLeft = left;
	int dRight = right - 1;
	int pivot = arr[left];
	while(dLeft<dRight)
	{
		while( dLeft<dRight&&arr[dLeft]<=pivot )
			++dLeft;
		while( dLeft<dRight&&arr[dRight]>=pivot )
			--dRight;
	}
	return dLeft;
}
//0
//
//1
//
//-1
//
//2
