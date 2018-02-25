 ///
 /// @file    test1.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-02-13 15:12:10
 ///
 
#include<iostream>
using namespace std;
int x = 100;
namespace // 匿名的命名空间相当于全局的
{
	int x = 200;
}
int main()
{
	//cout<<x<<endl;   //二义性，不知道到底是哪一个
	//全局的和匿名空间里的x都可以这样访问
	cout<<::x<<endl;   //100,表示的是全局的100
	return 0;
}
//100
