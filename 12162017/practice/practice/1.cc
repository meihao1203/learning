#include<iostream>
#include<stdlib.h>
using namespace std;
void func(const int & v1, const int & v2)
{
	cout << v1 << ' ';
	cout << v2 << ' ';
}
int main1()  //注释掉
{
	int i = 0;
	func(++i, i++);  //函数调用，局部变量入栈顺序是从右到左；函数内部定义的静态变量是不入栈的，存放在全局静态区。
	//i++ 先传值0，再+1 , ++i  = 2
	system("pause");
	return 0;
}
//2 0