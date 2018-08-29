 ///
 /// @file    equal_range.cpp
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
	auto pair = equal_range(ve1.begin(),ve1.end(),5); //返回一个pair<vector<int>::iterator,vector<int>::iterator>,第一个指向第一个不小于5的元素，第二个指向第一个大于5的元素
	for(auto it = pair.first;it<=pair.second;++it)
		cout<<*it<<" ";
	cout<<endl;
	auto pair2 = equal_range(ve1.begin(),ve1.end(),11);
	if(pair2.first==ve1.end() && pair2.second==ve1.end())
		cout<<"not found"<<endl;
	//容器无序
	int arr2[10] = {2,1,4,3,6,8,5,7,9,10};
	vector<int> ve2(arr2,arr2+10);
	print(ve2);
	auto pair3 = equal_range(ve2.begin(),ve2.end(),5);
	for(auto it = pair3.first;it<=pair3.second;++it)
		cout<<*it<<" ";
	cout<<endl;
}
//1 2 3 4 5 6 7 8 9 10 
//5 6 
//not found
//2 1 4 3 6 8 5 7 9 10 
//6 
