//题目46：求1+2+3+……+n，要求不能使用乘除法，for,while,if,else,switch,case等关键字及条件判断语句(A?B:C)
//思路：
//解法二：利用虚函数特性来模拟递归
#if 0
#include<iostream>
using namespace std;
class A;
static A* arr[2];
class A
{
public:
	virtual int sum(int n)
	{
		return 0;
	}
};
class B:public A
{
	virtual int sum(int n)
	{
		return n + arr[!!n]->sum(n-1);  //如果n>0，!!n = 1；如果n==0，!!n = 0;   //模仿了递归
		//虚函数实现了动态多态性
	}
};
int main()
{
	arr[0] = new A;
	arr[1] = new B;
	int n = 100;
	cout<<arr[1]->sum(n)<<endl;
	system("pause");
}
#endif
//5050