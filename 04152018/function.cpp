 ///
 /// @file    function.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-04-15 10:31:05
 ///
 
// bind 返回一个新的可调用实体
// function 对象实现函数回调
#include<iostream>
#include<functional>
using namespace std;
using std::function;
//using std::placeholders;  // namespace ‘std::placeholders’ not allowed in using-declaration 
using namespace std::placeholders;
int func(int x,int y)
{
	return x+y;
}
class A
{
	public:
		int func(int x,int y)
		{
			return x+y;
		}
};
int main()
{
	// function<int(int,int)> test1  = bind(func,10,placeholders::_1);
	// 只有一个占位符，意思传参只要传一个，所以形参不能是两个，和原函数没关系
	function<int(int)> test1  = bind(func,10,placeholders::_1);
	cout<<test1(20)<<endl;

	A a;
	function<int(int)> test2 = bind(&A::func,&a,30,_1);  // 前面声明，就不用写placeholders
	cout<<test2(40)<<endl;

	function<int(int,int)> test3 = func;
	cout<<test3(10,20)<<endl;

	//function<int(const A&,int,int)> test4 = &A::func;  // conversion from ‘int (A::*)(int, int)’ to non-scalar type ‘std::function<int(const A&, int, int)>’ requested  
	function<int(A&,int,int)> test4 = &A::func;  // 今天脑子犯抽,const成员对象只能调用const修饰的成员函数
	cout<<test4(a,10,20)<<endl;
	return 0;
}
//30
//70
//30
//30
