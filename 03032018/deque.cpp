 ///
 /// @file    deque.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-03-03 16:34:57
 ///
 
#include<iostream>
#include<deque>
using namespace std;
int main()
{
	double arr[] = {1,2,3,4,5};
	deque<double> dq(arr,arr+5);  // 用区间来初始化双端队列,队列区间是[);
	for(int i=0;i!=dq.size();++i)  // 支持随机访问,随机访问迭代器
	{
		cout<<dq[i]<<"  ";
	}
	cout<<endl;
	deque<double>::iterator it = dq.begin();  // 双向迭代器
	for(;it!=dq.end();++it)
	{
		cout<<*it<<"  ";
	}
	cout<<endl;
	deque<double>::iterator it1 = dq.end();  // [)
	for(--it1;it1!=(dq.begin()-1);--it1)
	{
		cout<<*it1<<"  ";
	}
	cout<<endl;
	for(auto& elem:dq)
	{
		cout<<elem<<"  ";
	}
	cout<<endl;
	return 0;
}
//1  2  3  4  5  
//1  2  3  4  5  
//5  4  3  2  1  
//1  2  3  4  5  
