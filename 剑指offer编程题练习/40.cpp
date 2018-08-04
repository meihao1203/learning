//题目40：一个整形数组里除了两个数字之外，其他的数字都出现了两次。找出这两个只出现了一次的数字。
//时间复杂度O(n)，空间复杂度O(1);
//eg：{2,4,3,6,3,2,5,5}->4,3
//思路：首先想到的是一个数组里面只有一个数字出现一次，其他的两两出现，这个时候可以用异或^在O(n)时间复杂度求出这个数，
//这里有两个不相同，也可以异或来做。最终的结果就是两个数的异或结果，从右到左找出第一个1，然后在把数组进行分组。
//二进制数这一位为1的和不为1的，这两个不同的数就被单独分开，再采用异或就能找出。
//进一步优化，这一位为1的数执行异或操作，为0的数执行异或操作，就能分别得到两个数，省去了数组分组
#include<iostream>
using namespace std;
int findAppearOnceNumber(int* arr,int length,int& num1,int& num2);
int findFirstOneBit(int num);  //从右到左找到第一个bit为1的位
bool isBitOne(int num,int bitNumber);  //判断数的二进制表示中某一位是不是1
void test(int* arr,int length);
int main()
{
	int arr[] = {2,4,3,6,3,2,5,5};  //正常输入
	test(arr,8);
	cout<<endl;

	int arr2[] = {1,2};
	test(arr2,2);
	cout<<endl;

	int* arr3 = NULL;
	test(arr3,0);
	cout<<endl;
}
void test(int* arr,int length)
{
	int num1,num2;
	findAppearOnceNumber(arr,length,num1,num2);
	cout<<num1<<" "<<num2<<endl;
}
int findAppearOnceNumber(int* arr,int length,int& num1,int& num2)
{
	if(NULL==arr||length<=0)
	{
		num1 = -1;
		num2 = -1;
		return -1;
	}
	num1 = 0,num2 = 0;  //传的是引用，先初始化
	int result = 0;
	for(int idx=0;idx!=length;++idx)
		result ^= arr[idx];
	int firstBitOne = findFirstOneBit(result);
	for(int idx=0;idx!=length;++idx)
	{  
		if(isBitOne(arr[idx],firstBitOne))   //if else 等同把数组分成两部分了，一部分是某一指定位为1的数，一部分是某一指定位为0的数。
		{//找到的对应位为1
			num1 ^= arr[idx];
		}
		else 
		{
			num2 ^= arr[idx];
		}
	}
	return 0;
}
int findFirstOneBit(int num)
{
	int cnt = 0;
	while( (num&1)==0 && cnt!=(8*sizeof(int)) )  //找到从右到左的第一个1
	{
		num = num>>1;
		++cnt;
	}
	return cnt;
}
bool isBitOne(int num,int bitNumber)
{
	if(bitNumber<0)
		return false;
	num = num>>bitNumber;
	return num&1;
}
//6 4
//
//1 2
//
//-1 -1
