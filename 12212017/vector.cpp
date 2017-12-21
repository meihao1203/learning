 ///
 /// @file    vector.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2017-12-21 15:50:05
 ///
 
#include<iostream>
#include<vector>
using namespace std;
void printNUM(vector<int> &ver)
{
	cout<<"vector.size:"<<ver.size()<<endl;
	cout<<"vector.capacity:"<<ver.capacity()<<endl;
}
//size()返回的是容器中push_back()的元素个数
//capacity()返回的是容器的空间(最多放多少个元素)
int main(void)
{
	vector<int> ver;
	//预先开辟空间
	ver.reserve(10);
	printNUM(ver);
	ver.push_back(1);
	printNUM(ver);   //vector当size和capacity一样大的时候，capacity会翻倍扩充
	ver.push_back(2);
	printNUM(ver);
	ver.push_back(3);
	printNUM(ver);
	ver.push_back(4);
	printNUM(ver);
	ver.push_back(5);
	printNUM(ver);
	ver.push_back(6);
	printNUM(ver);
	ver.push_back(7);
	printNUM(ver);
	ver.push_back(8);
	printNUM(ver);
	ver.push_back(9);
	printNUM(ver);
	for(int i=0;i!=ver.size();++i)
	{
		cout<<ver[i]<<"  ";
	}
	cout<<endl;
	vector<int>::iterator it;    //迭代器
	for(it=ver.begin();it!=ver.end();++it)
	{
		cout<<*it<<"  ";
	}
	cout<<endl;
}
//vector.size:0
//vector.capacity:0
//vector.size:1
//vector.capacity:1
//vector.size:2
//vector.capacity:2
//vector.size:3
//vector.capacity:4
//vector.size:4
//vector.capacity:4
//vector.size:5
//vector.capacity:8
//vector.size:6
//vector.capacity:8
//vector.size:7
//vector.capacity:8
//vector.size:8
//vector.capacity:8
//vector.size:9
//vector.capacity:16
//1  2  3  4  5  6  7  8  9  
//1  2  3  4  5  6  7  8  9  

//vector.size:0
//vector.capacity:10
//vector.size:1
//vector.capacity:10
//vector.size:2
//vector.capacity:10
//vector.size:3
//vector.capacity:10
//vector.size:4
//vector.capacity:10
//vector.size:5
//vector.capacity:10
//vector.size:6
//vector.capacity:10
//vector.size:7
//vector.capacity:10
//vector.size:8
//vector.capacity:10
//vector.size:9
//vector.capacity:10
//1  2  3  4  5  6  7  8  9  
//1  2  3  4  5  6  7  8  9  
