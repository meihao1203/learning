 ///
 /// @file    not1.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-03-27 11:25:11
 ///
 

//函数适配器
//否定器，not1() 用于逆转一元断言
//not2() 用于逆转二元断言
#include<iostream>
#include<algorithm>
#include<functional>
using namespace std;
template<typename Container>
void print(Container& v)
{
	for(auto& elem:v)
		cout<<elem<<"  ";
	cout<<endl;
}
int main()
{
	int arr[] = {1,2,3,4,5,6,7};
	vector<int> v1(arr,arr+sizeof(arr)/sizeof(int));
	print(v1);
	less<vector<int>::value_type> it;
	vector<int> tmp(v1);
	replace_if(tmp.begin(),tmp.end(),bind1st(it,3),7);  // it为小于3，最终就是大于3的数据改成7
	print(tmp);
	tmp.clear();
	tmp = v1;
	replace_if(tmp.begin(),tmp.end(),not1(bind1st(it,3)),7);  // 否定器,小于3的改成7
	print(tmp);
	tmp.clear();
	tmp = v1;
	replace_if(tmp.begin(),tmp.end(),bind1st(not2(it),3),7);  // it被否定成大于3，所以最终就是小于3的数据被换成7
	print(tmp);
}
//1  2  3  4  5  6  7  
//1  2  3  7  7  7  7  
//7  7  7  4  5  6  7  
//7  7  7  4  5  6  7
