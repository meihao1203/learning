//ì³²¨ÄÇÆõÊıÁĞ
#include<iostream>
using namespace std;
int fibonacci(unsigned int n);
int main()
{
	int res = fibonacci(3);
	cout<<res<<endl;
}
int fibonacci(unsigned int n)
{
	if(n<0||0==n)
		return 0;
	else if(1==n)
	{
		return 1;
	}
	int fibonacciOne = 0,fibonacciTwo = 1;
	int res = 0;
	for(int idx=2;idx<=n;++idx)
	{
		res = fibonacciOne + fibonacciTwo;
		fibonacciOne = fibonacciTwo;
		fibonacciTwo = res;
	}
	return res;
}
