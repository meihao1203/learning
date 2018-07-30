 ///
 /// @file    stack.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-07-30 11:05:32
 ///
 
#include<iostream>
#include<stack>
#include<list>
using namespace std;
int main()
{
	stack<int,list<int> > mei;
	mei.push(1);
	mei.push(2);
	cout<<mei.size()<<endl;
	cout<<mei.top()<<endl;
	mei.pop();
	cout<<mei.top()<<endl;
	mei.pop();
	cout<<mei.top()<<endl;
	return 0;
}
