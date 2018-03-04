 ///
 /// @file    insert2.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-03-04 10:06:49
 ///
 

#include<iostream>
#include<map>
#include<string>
using namespace std;
int main()
{
	pair<int,string> arr[4] = 
	{
		pair<int,string>(1,"beijing"),
		pair<int,string>(3,"shanghai"),
		pair<int,string>(2,"tinjin"),
		pair<int,string>(2,"shenzhen")
	};
	pair<int,string> x(8,"kunming");
	map<int,string> map1(arr,arr+4);
	map<int,string>::iterator it = map1.begin();
	it++; it++;  // 指针偏移
	//加快查找速度的插入
	map<int,string>::iterator p = map1.insert(it,x);
	cout<<"map插入后的返回值:"<<p->first<<","<<p->second<<endl;
	cout<<"输出map1元素:"<<endl;
	for(auto& elem:map1)
		cout<<elem.first<<","<<elem.second<<endl;
	cout<<"----------------------------------------------"<<endl;
	multimap<int,string> mmap1(arr,arr+4);
	multimap<int,string>::iterator mit = mmap1.begin();
	++mit;
	multimap<int,string>::iterator mp = mmap1.insert(mit,x);
	cout<<"multimap插入后的返回值:"<<mp->first<<","<<mp->second<<endl;
	cout<<"输出mmap1元素:"<<endl;
	for(auto& elem:mmap1)
		cout<<elem.first<<","<<elem.second<<endl;
	cout<<endl;
	return 0;
}
//map插入后的返回值:8,kunming
//输出map1元素:
//1,beijing
//2,tinjin
//3,shanghai
//8,kunming
//----------------------------------------------
//multimap插入后的返回值:8,kunming
//输出mmap1元素:
//1,beijing
//2,tinjin
//2,shenzhen
//3,shanghai
//8,kunming
//
