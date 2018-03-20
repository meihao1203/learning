 ///
 /// @file    queue.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-03-20 14:54:35
 ///
 
#include<iostream>
#include<queue>
using namespace std;
int main()
{
	queue<int> ob1;
	for(int i=0;i!=10;++i)
		ob1.push(i);
	cout<<"---size---"<<ob1.size()<<endl;
	for(int i=0;i!=10;++i)
	{
		cout<<ob1.front()<<"  ";
		ob1.pop();
	}
	cout<<endl;
	return 0;
}
//---size---10
//0  1  2  3  4  5  6  7  8  9  
