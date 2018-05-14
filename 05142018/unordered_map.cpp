 ///
 /// @file    unordered_map.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-05-14 17:06:24
 ///
 
#include<iostream>
#include<unordered_map>
#include<string>
#include<iterator>
using namespace std;
int main()
{
	pair<int,string> arr[5]={
		pair<int,string>(1,"北京"),
		pair<int,string>(2,"上海"),
		pair<int,string>(2,"昆明"),
		pair<int,string>(4,"重庆"),
		pair<int,string>(3,"天津")
	};
	unordered_map<int ,string> test1(arr,arr+5);
	unordered_map<int ,string>::iterator it = test1.begin();
	for(;it!=test1.end();++it)
	{
		cout<<it->first<<" "<<it->second<<endl;
	}
	//无序map,不能使用less<>和greater<>来排序了
	cout<<"test unordered_multimap:"<<endl;
	unordered_multimap<int ,string> test2(arr,arr+5);
	for(auto& elem:test2)
	{
		cout<<elem.first<<" "<<elem.second<<endl;
	}
	cout<<"test random access:"<<endl;
	cout<<test1[1]<<endl;  // unordered_multimap不支持随机访问
	unordered_multimap<int,string>::iterator umit = test2.find(2);
	cout<<umit->first<<" "<<umit->second<<endl;
}
//3 天津
//4 重庆
//2 上海
//1 北京
//test unordered_multimap:
//3 天津
//1 北京
//2 昆明
//2 上海
//4 重庆
//test random access:
//北京
//2 昆明
