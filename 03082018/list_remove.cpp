 ///
 /// @file    list_remove.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-03-08 09:56:03
 ///
 
#include<iostream>
#include<list>
using namespace std;
bool removeIf(int n)
{
	return n>10;
}
int main()
{
	list<int> l1 = { 1,100,2,3,10,1,11,-1,12 };
	for(auto elem:l1)
		cout<<elem<<"  ";
	cout<<endl;
	l1.remove(1);  // 删除所有1
	for(auto elem:l1)
		cout<<elem<<"  ";
	cout<<endl;
	l1.remove_if([](int n ){return n>10;});  // lambda表达式
	//l1.remove_if(removeIf);  //和上面一样的效果，删除所有大于10的元素
	for(auto elem:l1)
		cout<<elem<<"  ";
	cout<<endl;
	return 0;
}
//1  100  2  3  10  1  11  -1  12  
//100  2  3  10  11  -1  12  
//2  3  10  -1  
