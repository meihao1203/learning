 ///
 /// @file    set3.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-03-03 21:14:17
 ///
 
#include<iostream>
#include<set>
using namespace std;
int main()
{
	int arr[9] = {1,5,2,78,9,3,5,12,34};
	multiset<int> se(arr,arr+9);;
	cout<<"set.size="<<se.size()<<endl;  // set不允许重复
	for(auto& elem:se)
		cout<<elem<<"  ";
	cout<<endl;
	set<int,greater<int> >se2(arr,arr+9);;
	for(auto& elem:se2)
		cout<<elem<<"  ";
	cout<<endl;
	set<int,less<int> >se3(arr,arr+9);
	for(auto& elem:se3)
		cout<<elem<<"  ";
	cout<<endl;
	return 0;
}
//set.size=9
//1  2  3  5  5  9  12  34  78  
//78  34  12  9  5  3  2  1  
//1  2  3  5  9  12  34  78  
