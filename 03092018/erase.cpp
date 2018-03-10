 ///
 /// @file    erase.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-03-09 11:42:54
 ///
 
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	vector<int> ve;
	ve.reserve(10);
	cout<<"ve's capacity:"<<ve.capacity()<<"  ve's size:"<<ve.size()<<endl;
	for(int i=1;i!=11;++i)
		ve.push_back(i);
	for(auto& elem:ve)
		cout<<elem<<"  ";
	cout<<endl;
	cout<<"ve's capacity:"<<ve.capacity()<<"  ve's size:"<<ve.size()<<endl;
	ve[3] = ve[5] = ve[9] = 99;
	for(auto& elem:ve)
		cout<<elem<<"  ";
	cout<<endl;
	//remove(ve.begin(),ve.end(),99);
	//用指针指向的值是要删除的99的时候，再定义一个指针在容器后面寻找第一个不为99的元素，并替换当前的99，然后两个指针都向前+1
	//最终会导致最后一个元素删除不了
	ve.erase(remove(ve.begin(),ve.end(),99),ve.end());
	//erase-remove 是惯用方法，不会导致迭代器失效
	for(auto& elem:ve)
		cout<<elem<<"  ";
	cout<<endl;
	cout<<"ve's capacity:"<<ve.capacity()<<"  ve's size:"<<ve.size()<<endl;
	return 0;
}
//remove
//ve's capacity:10  ve's size:0
//1  2  3  4  5  6  7  8  9  10  
//ve's capacity:10  ve's size:10
//1  2  3  99  5  99  7  8  9  99  
//1  2  3  5  7  8  9  8  9  99  
//ve's capacity:10  ve's size:10

//erase-remove
//ve's capacity:10  ve's size:0
//1  2  3  4  5  6  7  8  9  10  
//ve's capacity:10  ve's size:10
//1  2  3  99  5  99  7  8  9  99  
//1  2  3  5  7  8  9  
//ve's capacity:10  ve's size:7
