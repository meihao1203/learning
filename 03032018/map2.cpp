///
/// @file    map2.cpp
/// @author  meihao1203(meihao19931203@outlook.com)
/// @date    2018-03-03 21:38:28
///

#include<iostream>
#include<map>
using namespace std;
int main()
{
	pair<const int,string> arr[4] = 
	{
		pair<int,string> (1,"北京"),
		pair<int,string> (2,"深圳"),
		pair<int,string> (3,"广州"),
		pair<int,string> (2,"天津"),
	};
//	pair<int,string> arr[4] = 
//	{
//		(1,"北京"),
//		(2,"深圳"),
//		(3,"广州"),
//		(2,"天津"),
//	};
	map<int,string> map1(arr,arr+4);
	for(auto& elem:map1)
		cout<<elem.first<<"  "<<elem.second<<endl;
	cout<<endl;
	map1[5] = "昆明";  // map可以自动扩容
	for(auto& elem:map1)
		cout<<elem.first<<"  "<<elem.second<<endl;
	cout<<endl;
	cout<<"2:"<<map1[2]<<endl;
	return 0;
}
//1  北京
//2  深圳
//3  广州
//
//1  北京
//2  深圳
//3  广州
//5  昆明
//
//2:深圳
