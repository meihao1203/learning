//题目47：不用加减乘除做加法。写一个函数，求两个整数之和，要求在函数体内不得使用+、1、*、%、/四则运算符
//思路：分三步，第一步各位相加不计算进位，第二步计算进位，第三步就是前两步结果相加。
//可以用循环来实现，循环出口就是进位为0；
//eg：5+17 == 101 + 10001，要相加不计算进位只能用异或^ ( 0,0=0; 0,1=1; 1,0=1; 1,1=0 ) 10100
//计算进位，可以一起计算，1,1 = 10；只能先&再左移一位，
//出口就是进位为0，表示所有进位都加完了
#include<iostream>
using namespace std;
int add(int num1,int num2);
void test(int num1,int num2);
int main()
{
	test(5,17);
	cout<<endl;

	test(1,2);
	cout<<endl;

	test(-1,-2);
	cout<<endl;

	test(-1,2);
	cout<<endl;

}
void test(int num1,int num2)
{
	int ret = add(num1,num2);
	cout<<ret<<endl;
}
int add(int num1,int num2)
{
	int carry = 0;
	int sum = 0;
	do
	{
		sum = num1 ^ num2;  //先加，不进位
		carry = (num1 & num2) << 1;  //计算进位
		num1 = sum;
		num2 = carry;  //修改两个值，进行第三步
	}while(num2!=0);  //进位不为0
	return sum;
}
//22
//
//3
//
//-3
//
//1

/*
相关问题：不能使用新的变量，交换两个变量的值。比如有两个变量a、b,要交换它们的值
第一种方法：基于加减法
	a = a + b;
	b = a - b;
	a = a - b;
第二种方法：基于异或运算
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
*/
#if 0
int main()
{
	int a = 3;
	int b = 4;
#if 0
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
#endif
	a = a + b;
	b = a - b;
	a = a - b;
	cout<<"a = "<<a
		<<" b = "<<b<<endl;
	system("pause");
}
//a = 4 b = 3
#endif
