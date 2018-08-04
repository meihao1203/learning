//题目30：输入n个整数，找出其中最小的k个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数组是1,2,3,4
//思路：前面的复杂度O(n),但是修改了数组，这里用红黑树来实现，复杂度O(n*logn)
#include<iostream>
#include<set>
#include<functional>
using namespace std;
void findLeastElements(int* arr,int length,int k);
int main()
{
	int arr[] = {4,5,1,6,2,7,3,8};
	findLeastElements(arr,8,4);
	cout<<endl;

	int arr2[] = {4,5,1};
	findLeastElements(arr2,3,2);
	cout<<endl;

	system("pause");
}
void findLeastElements(int* arr,int length,int k)
{
	if(NULL==arr||length<=0||k>length||k<=0)
	{
		cout<<"input error!"<<endl;
		return;
	}
	multiset<int,greater<int> > leastK;
	for(int idx=0;idx!=length;++idx)
	{
		if(leastK.size()<k)
		{
			leastK.insert(arr[idx]);
		}
		else 
		{
			if(*leastK.begin()>arr[idx])
			{
				leastK.erase(*leastK.begin());
				leastK.insert(arr[idx]);
			}
		}
	}
	//multiset<int,greater<int> >::iterator it = leastK.begin();
	for(auto& elem:leastK)
		cout<<elem<<" ";
	cout<<endl;
}
//4 3 2 1
//
//4 1
