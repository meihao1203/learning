//题目31：输入一个整型数组，数组里有正数也有负数。数组中一个或连续多个整数组成一个子数组。
//求所有子数组的和的最大值。要求时间复杂度为O(n)。
//eg：数组{1,-2,3,10,-4,7,2,-5}，和最大的子数组为{3,10,-4,7,2}，因此输出为该子数组的和18。
//思路：连续子数组的最大值，先假设最大值为最小的负数，定义一个为0的数sum，从数组头开始遍历相加
//如果相加大于0，下一步在去和当前最大值比较，如果大于最大值则更新最大值。小于则继续加下一个数组元素。
//如果相加后小于0，证明前面的连续子数组不可能是最大值，重新修改sum为下一个元素的值，继续遍历相加。
//最终最大值记录的就是子数组的和的最大值。
#include<iostream>
using namespace std;
int findMaxSubarray(int* arr,int length);
void test(int* arr,int length);
int main()
{
	int arr[] = {1,-2,3,10,-4,7,2,-5};
	test(arr,8);
	cout<<endl;

}
void test(int* arr,int length)
{
	int result = findMaxSubarray(arr,length);
	cout<<result<<endl;
}
int findMaxSubarray(int* arr,int length)
{
	if(NULL==arr||length<=0)
		return -1;
	int sum = 0;  //记录当前最大值
	int totalSum = 0x80000000;   //int类型4个字节，最小的数就是-128，这里存的是一个负数，计算机存放补码，对应的补码就是1000 0000 0000 0000；
	//负数的补码取反加一为对应的绝对值，128，所以这个数表示的是-128；
	for(int idx=0;idx!=length;++idx)
	{
		if(sum<=0)
			sum = arr[idx];
		else
			sum += arr[idx];
		if(sum>totalSum)
			totalSum = sum;
	}
	return totalSum;
}
