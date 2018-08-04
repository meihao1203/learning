//面试题44：从扑克牌中随机抽5张牌，判断是不是一个顺子，即这5张牌是不是连续的。
//2~10为数字本身，A为1，J为11，Q为12，K为13，而大、小王可以看成任意数字。
//思路：大小王可以随意代替其他数值，假设为0.先对5张牌排序，然后统计0的个数。
//在对排序进行遍历，计算两两数据之间的差值是否大于1，如果大于1就统计这个差值。最后判断这个差值是否
//等于0的数量，如果等于说明可以用0来代替对应的数值使得5张牌的排序连续，否则5张牌不是连续的。
//在遍历的过程中如果两张牌相等，直接返回失败。
//时间复杂度O(n*logn)
#if 0
#include<iostream>
#include<algorithm>
using namespace std;
bool isSequence(int* arr,int length);
int compare(const void* left,const void* right);
void printArr(int* arr,int length);
void test(int* arr,int length);
int main()
{
	int arr[] = {0,3,1,4,5};
	test(arr,5);
	cout<<endl;

	int arr1[] = {0,1,2,3,4};
	test(arr1,5);
	cout<<endl;

	int arr2[] = {0,1,1,3,4};
	test(arr2,5);
	cout<<endl;

	int arr3[] = {0,2,0,4,6};  //{0,0,2,4,6}
	test(arr3,5);
	cout<<endl;
	system("pause");
}
void test(int* arr,int length)
{
	printArr(arr,length);
	cout<<isSequence(arr,length)<<endl;
	printArr(arr,length);
}
void printArr(int* arr,int length)
{
	if(NULL==arr||length<=0)
		return ;
	for(int idx=0;idx!=length;++idx)
		cout<<arr[idx]<<" ";
	cout<<endl;
}
bool isSequence(int* arr,int length)
{
	if(NULL==arr||length!=5)
		return false;
	//sort(arr,arr+length);  //C++自带的大小比较
	qsort(arr,length,sizeof(int),compare);
	int zeroNum = 0;
	for(int idx=0;idx!=length;++idx)
	{
		if(arr[idx]==0)
		{
			++zeroNum;
			continue;
		}
		break;
	}
	//开始计算差值
	int diff = 0;
	for(int idx=zeroNum;idx!=length;++idx)
	{
		if(arr[idx]==arr[idx+1])  //相邻两个数一样，肯定就不是连续的了
			return false;  
		diff += arr[idx+1] - arr[idx] - 1;  //相邻两个数差1。
	}
	if(diff = zeroNum||
		0==diff)
		return true;
	return false;
}
int compare(const void* left,const void* right)
{
	return *(int*)left - *(int*)right;
}
#endif
//0 3 1 4 5
//1
//0 1 3 4 5
//
//0 1 2 3 4
//1
//0 1 2 3 4
//
//0 1 1 3 4
//0
//0 1 1 3 4
//
//0 2 0 4 6
//1
//0 0 2 4 6
