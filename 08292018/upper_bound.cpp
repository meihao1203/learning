 ///
 /// @file    upper_bound.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-08-29 09:11:11
 ///
 
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
void print(vector<int>& ve)
{
	for(auto elem:ve)
		cout<<elem<<" ";
	cout<<endl;
}
int main()
{
	//容器有序
	int arr[10] = {1,2,3,4,5,6,7,8,9,10};
	vector<int> ve1(arr,arr+10);
	print(ve1);
	auto it = upper_bound(ve1.begin(),ve1.end(),2);
	cout<<*it<<endl;
	auto it2 = lower_bound(ve1.begin(),ve1.end(),11);
	if(it2==ve1.end())
	{
		cout<<"not found!"<<endl;
	}
	//容器无序
	int arr2[10] = {2,1,4,3,6,8,5,7,9,10};
	vector<int> ve2(arr2,arr2+10);
	print(ve2);
	auto it3 = lower_bound(ve2.begin(),ve2.end(),3);
	cout<<*it3<<endl;
}
//1 2 3 4 5 6 7 8 9 10 
//3
//not found!
//2 1 4 3 6 8 5 7 9 10 
//4
