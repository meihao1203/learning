//题目46：求1+2+3+……+n，要求不能使用乘除法，for,while,if,else,switch,case等关键字及条件判断语句(A?B:C)
//思路：
//解法三：利用C语言的函数指针模拟虚函数来实现递归
#if 0
#include<iostream>
using namespace std;
typedef int (*func)(int n);
static func arr[2];
int sum1(int n)
{
	return 0;
}
int sum2(int n)
{
	return n + arr[!!n](n-1);
}
int main()
{
	arr[0] = sum1;
	arr[1] = sum2;
	int n = 100;
	cout<<sum2(n)<<endl;
	system("pause");
}
#endif
//5050