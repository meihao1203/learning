 ///
 /// @file    priority_queue.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-03-20 15:06:09
 ///
 
#include<iostream>
#include<queue>
using namespace std;
int main()
{
	int arr[] = {0, 1, 3, 2, 5, 6, 9, 8, 7, 4};
	priority_queue<int> ob1;  // 优先队列，默认从大到小
	for(int i=0;i!=sizeof(arr)/sizeof(int);++i)
		ob1.push(arr[i]);
	cout<<"priority size="<<ob1.size()<<endl;
	for(int i=0;i!=sizeof(arr)/sizeof(int);++i)
	{
		cout<<ob1.top()<<"  ";
		ob1.pop();
	}
	cout<<endl;
	return 0;
}
//priority size=10
//9  8  7  6  5  4  3  2  1  0  
