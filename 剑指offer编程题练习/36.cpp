//题目36：在数组中的两个数字如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。
//输入一个数组，求出这个数组的逆序对的总数
//eg：{7,5,6,4}中，一共存在5个逆序对，分别是(7,6),(7,5),(7,4),(6,4),(5,4)。
//思路：最佳实践复杂度O(nlogn)，归并排序；
//假设数组{7,5,6,4}->开始划分->{7,5},{6,4}->{7}{5}{6}{4}->开始合并(7,5一个逆序)(6,4在一个逆序)
//->{5,7}{4,6}(这里合并的过程中，7>6,说明有两个逆序，5>4一个逆序)->{4,5,6,7};最后统计5个逆序
//空间复杂度O(n),因为最后要用一个一样的数组来存放排序好的数组
#include<iostream>
#include<string.h>
using namespace std;
int inversePairs(int* arr,int length);
int inversePairsMerge(int* arr,int* sortArr,int start,int end);
void test(int* arr,int length);
int main()
{
	int arr[] = {7,5,1,6,4};
	test(arr,5);
	cout<<endl;

}
void test(int* arr,int length)
{
	int ret = inversePairs(arr,length);
	cout<<ret<<endl;
}
int inversePairs(int* arr,int length)
{
	if(NULL==arr||length<=0)
		return -1;
	int* sortArr = new int[length];  //用来存放最后合并的有序的数组
	memset(sortArr,0,length*sizeof(int));
	/*for(int idx=0;idx!=length;++idx)
	sortArr[idx] = arr[idx];*/
	//开始划分(归并排序)
	int count =	inversePairsMerge(arr,sortArr,0,length-1);
	for(int idx=0;idx!=length;++idx)
		cout<<sortArr[idx]<<" ";
	cout<<endl;
	delete []sortArr;
	return count;
}
int inversePairsMerge(int* arr,int* sortArr,int start,int end)
{
	if(NULL==arr||NULL==sortArr||start<0||end<0||start==end)
		return 0;  //0个逆序对
	int middle = (end-start)/2;
	int leftCount = inversePairsMerge(arr,sortArr,start,start + middle);  //划分后的左半边数组的逆序对
	int rightCount = inversePairsMerge(arr,sortArr,start + middle + 1,end);  ////划分后的右半边数组的逆序对
	//划分到最后单个元素后开始向下合并
	int leftIndex = start + middle;  //左半边最后一个元素下标
	int rightIndex = end;  //右半边最后一个元素下标
	int inversePairsCount = 0;  //统计逆序
	int sortArrIndex = end;  //初始化sortArr开始存放元素位置的下标
	while(leftIndex>=start&&rightIndex>=start + middle + 1)
	{
		if(arr[leftIndex]>arr[rightIndex])
		{
			inversePairsCount += rightIndex - (start + middle + 1) + 1;
			sortArr[sortArrIndex--] = arr[leftIndex--];
		}
		else
		{
			sortArr[sortArrIndex--] = arr[rightIndex--];
		}
	}
	//把排序完剩下部分的元素全部拷贝到sortArr数组
	//如果左半边剩下
	for(;leftIndex>=start;)
		sortArr[sortArrIndex--] = arr[leftIndex--];
	//右半边剩下
	for(;rightIndex>=start + middle + 1;)
		sortArr[sortArrIndex--] = arr[rightIndex--];
	//合并过程中会产生有序的子数组，要同步修改原数组，不然最后往下合并过程中又用最初的无序数组来做为合并过程中的交换对照
	for(int idx=0;idx<=end;++idx)
		arr[idx] = sortArr[idx];
	return leftCount + rightCount + inversePairsCount;
}
//1 4 5 6 7
//7
/*
int leftCount = inversePairsMerge(arr,sortArr,start,start + middle);  //划分后的左半边数组的逆序对
int rightCount = inversePairsMerge(arr,sortArr,start + middle + 1,end);  ////划分后的右半边数组的逆序对
这两步操作可以交换arr和sortArr，前提是sortArr最开始要用原数组初始化，这样最后就不用
for(int idx=0;idx<=end;++idx)
arr[idx] = sortArr[idx];
修改原数组了
真正的归并排序中不用这样，直接原数组比较交换就好了
不过这个题好像也是可以这样做的。
如果题目要求不能修改原数组，那就只能这样做了。用一个辅助数组来存放排序好的数组。
*/
