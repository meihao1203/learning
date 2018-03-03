 ///
 /// @file    list.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-03-03 16:51:09
 ///
 
#include<iostream>
#include<list>
using namespace std;
int main()
{
	list<double> li(3,1.1);  // 初始化list,三个元素,每个元素的值为1.1
	// list 没有重载[]运算符，不支持随机迭代器访问
	list<double>::iterator it = li.begin();  // 不能直接初始化为NULL
	for(;it!=li.end();++it)
	{
		cout<<*it<<"  ";
	}
	cout<<endl;
	list<double> li2(5,2.2);
	li.swap(li2);  // 内部实现并没有交换，只是简单的交换了指针
	list<double>::iterator it2 = li.begin();
	for(;it2!=li.end();++it2)
	{
		cout<<*it2<<"  ";
	}
	cout<<endl;
	list<double>::iterator it3 = li2.begin();
	for(;it3!=li2.end();++it3)
	{
		cout<<*it3<<"  ";
	}
	cout<<endl;
	for(auto& elem:li)
	{
		cout<<elem<<"  ";
	}
	cout<<endl;
	return 0;
}
//1.1  1.1  1.1  
//2.2  2.2  2.2  2.2  2.2  
//1.1  1.1  1.1  
//2.2  2.2  2.2  2.2  2.2  
