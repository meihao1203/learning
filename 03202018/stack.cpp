 ///
 /// @file    stack.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-03-20 11:20:14
 ///
 
#include<iostream>
#include<vector>
#include<stack>
#include<string>
using namespace std;
int main()
{
	stack<int,vector<int> > ob1;
	cout<<ob1.size()<<endl;
	for(int i=0;i!=10;++i)
	{
		ob1.push(i);
	}
	cout<<ob1.size()<<endl;
	cout<<ob1.top()<<endl;
	ob1.pop();
	cout<<ob1.top()<<endl;
	cout<<"********"<<endl;
	stack<string,vector<string> > ob2;
	for(char i=65;i!=91;++i)
	{
		string tmp = string(1,i);
		ob2.push(tmp);
	}
	cout<<ob2.top()<<endl;
	ob2.pop();
	cout<<ob2.top()<<endl;
	return 0;
}
//0
//10
//9
//8
//********
//Z
//Y
