//求一个double类型的数的double次方
//1、0的任何次方没有意义，结果为0或1都可以
//2、如果次方是负数，完了0的负数次方最后要求导会除以0
//3、出错怎么判断？ 返回值、全局变量、异常
#include<iostream>
using namespace std;
bool powerFlag = false;  //全局错误标志位
double power(double base,double exponent);
bool equal(double num1,double num2); //判断两个double类型的数是不是相等
double unsignedPower(double base,unsigned int absExponent);  //对power函数里对输入处理过后进行次方运算
void test(double base,double exponent,double expected); 
#if 0
int main()
{
	test(4.0,2.0,16.0);
	test(0.0,-1,-1);
	test(2.0,-2,0.25);
	system("pause");
}
#endif 
double power(double base,double exponent)
{
	if(equal(base,0.0)&&exponent<0)  // 2，基数为0，次方负数 失败
	{
		powerFlag = true;  //修改标志位并返回-1
		return -1;
	}
	unsigned int absExponent;
	absExponent = exponent;
	if(exponent<0)  //特殊情况，小于0取负数
		absExponent = (unsigned int)(-exponent);
	double result = unsignedPower(base,absExponent);
	if(exponent<0)
		return 1.0/result;
	return result;
}
bool equal(double num1,double num2)
{
	if((num1-num2)<0.0000001&&(num1-num2)>-0.0000001)
		return true;
	else
	{
		return false;
	}
}
double unsignedPower(double base,unsigned int absExponent)  //偶数次方eg：(2,4)=(2,2)=(2,1)==2,递归出口返回向下执行
	//基数次方多乘一个base
{
	if(0==absExponent)  //特例，0的0次方返回1
		return 1;
	else if(1==absExponent)
		return base;
	int res = unsignedPower(base,absExponent>>1);  //左移和与操作 细节要告诉别人，让他们注意到
	res *= res;
	if(absExponent&0x1==1)  //次方为基数   
		res *= base;  
	return res;
}
void test(double base,double exponent,double expected)
{
	if(power(base,exponent)!=expected)
		cout<<"fail"<<endl;
}