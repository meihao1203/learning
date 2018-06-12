//题目46：求1+2+3+……+n，要求不能使用乘除法，for,while,if,else,switch,case等关键字及条件判断语句(A?B:C)
//思路：
//解法一，利用C++特性，在构造函数中++
#if 0
#include<iostream>
using namespace std;
class sum
{
public:
	sum()
	{
		++_num;
		_sum += _num;
	}
	static int getSum()
	{
		return _sum;
	}
private:
	static int _num;
	static int _sum;
};
int sum::_num = 0;
int sum::_sum = 0;
void fun1(int n)
{
	sum* arr = new sum[n];  //定义n个对象，就会调用n次构造函数
	cout<<sum::getSum()<<endl;
	delete []arr;
	arr = NULL;
}
int main()
{
	int n = 100;
	fun1(n);
	system("pause");
}
#endif
//5050