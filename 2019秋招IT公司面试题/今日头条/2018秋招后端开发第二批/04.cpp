//二分查找搜索一个递增的数组，当有多个元素值与目标元素相等时，
//当有多个元素值与目标元素相等时，返回最后一个元素下标
//没有返回-1
#include<iostream>
#include<vector>
using namespace std;
int BinarySearchMax(const std::vector<int>& data, int target)
{
	//int left = 0;
	//int right = data.size() - 1;
	//while(left<right)
	//{
	//	int mid = (left+right)>>1;
	//	if(data[mid]==target&&mid+1<right&&data[mid+1]!=target)
	//		return mid;
	//	else if(data[mid]<=target)
	//	{
	//		left = mid + 1;
	//	}  
	//	else // data[mid]>target
	//	{
	//		right = mid - 1;
	//	}
	//}
	//if(data[right]==target)
	//	return right;
	//return -1;
	int left = 0;
	int right = data.size() - 1;
	while(left<=right)
	{
		int mid = (left+right)>>1;
		/*if(data[mid]==target&&mid+1<right&&data[mid+1]!=target)
			return mid;*/
		if(data[mid]<=target)
		{
			left = mid + 1;
		}  
		else // data[mid]>target
		{
			right = mid - 1;
		}
	}
	if(data[right]==target)
		return right;
	return -1;
}
int main()
{
	int arr[10] = {1,2,3,3,4,5,5,6,7,8};
	vector<int> data(arr,arr+10);
	int ret = BinarySearchMax(data,3);
	cout<<ret<<endl;
	ret = BinarySearchMax(data,9);
	cout<<ret<<endl;
	ret = BinarySearchMax(data,4);
	cout<<ret<<endl;
	ret = BinarySearchMax(data,5);
	cout<<ret<<endl;
	system("pause");
}