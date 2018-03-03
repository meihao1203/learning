///
/// @file    map3.cpp
/// @author  meihao1203(meihao19931203@outlook.com)
/// @date    2018-03-03 21:38:28
///

#include<iostream>
#include<map>
#include<string>
using namespace std;
int main()
{
	pair<int,string> arr[4] = 
	{
		pair<int,string> (1,"北京"),
		pair<int,string> (2,"深圳"),
		pair<int,string> (3,"广州"),
		pair<int,string> (2,"天津"),
	};
	//multimap里面允许有相同关键字的pair元素
	multimap<int,string> map1(arr,arr+4);
	for(auto& elem:map1)
		cout<<elem.first<<"  "<<elem.second<<endl;
	cout<<endl;
	//map1[5] = "昆明";  // multimap不支持随机访问
	pair<int,string> p1(5,"昆明");
	map1.insert(p1);
	for(auto& elem:map1)
		cout<<elem.first<<"  "<<elem.second<<endl;
	cout<<endl;
	return 0;
}
//1  北京
//2  深圳
//2  天津
//3  广州
//
//1  北京
//2  深圳
//2  天津
//3  广州
//5  昆明
//
