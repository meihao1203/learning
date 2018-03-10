 ///
 /// @file    replace_if.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-03-09 10:36:54
 ///
 
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>  // 使用less<>类模板要用到的头文件
using namespace std;
int main()
{
	vector<int> ve = {1,2,3,4,5,6};
	for(auto& elem:ve)
		cout<<elem<<"  ";
	cout<<endl;
	std::less<int> it;  // 创建less<int>类函数对象;  这个是重载了()操作符的类对象
	// 二元断言
	replace_if(ve.begin(),ve.end(),bind2nd(it,3),7);  // 将ve中大于3的元素全部替换成7
	replace_if(ve.begin(),ve.end(),bind1st(it,3),7);  // 将ve中小于3的元素全部替换成7
	for(auto& elem:ve)
		cout<<elem<<"  ";
	cout<<endl;
	return 0;
}
//bind1st
//1  2  3  4  5  6  
//1  2  3  7  7  7 

//bind2nd
//1  2  3  4  5  6  
//7  7  3  4  5  6  

//全打开
//1  2  3  4  5  6  
//7  7  3  7  7  7
