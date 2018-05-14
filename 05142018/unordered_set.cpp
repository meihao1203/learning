 ///
 /// @file    unordered_set.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-05-14 18:35:36
 ///
 
#include<iostream>
#include<unordered_set>
using namespace std;
int main()
{
	int arr[7] = {2,2,1,3,4,5,3};
	unordered_set<int> test1(arr,arr+7);
	for(auto& elem:test1)
		cout<<elem<<" ";
	cout<<endl;
	cout<<"test unordered_multiset"<<endl;
	unordered_multiset<int> test2(arr,arr+7);
	for(auto& elem:test2)
		cout<<elem<<" ";
	cout<<endl;
	unordered_multiset<int> test3(arr,arr+7);
	cout<<"test random access"<<endl;
	cout<<*(test2.find(3))<<endl;
	cout<<*(test2.find(2))<<endl;
	cout<<"value = 2 cnt:"<<test2.count(2)<<endl;
	return 0;
}
//5 4 3 1 2 
//test unordered_multiset
//2 2 1 3 3 4 5 
//test random access
//3
//2
//value = 2 cnt:2
