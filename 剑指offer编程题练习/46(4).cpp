//题目46：求1+2+3+……+n，要求不能使用乘除法，for,while,if,else,switch,case等关键字及条件判断语句(A?B:C)
//思路：
//解法四：利用模板和模板特化来实现递归
#include<iostream>
using namespace std;
template<int num>  //缺点，模板非类型参数表达式必须是int类型，代表一个常量
struct sum
{
	static const int Sum = num + sum<num-1>::Sum; //必须是静态的，还要是常量，这样sum<num-1>::Sum才能调用
};
template<>  //模板特化，递归出口
struct sum<1>
{
	static const int Sum = 1;  //我记得c++11新特性这里面是可以赋初值的
	//只有静态常量类型才能在类里面赋值
};
int main()
{
	int n = 100;
	sum<100> b;
	cout<<b.Sum<<endl; 
}
//5050

template<int num>
struct sum
{
	//enum Sum {N = num + sum<num-1>::Sum::N};
	enum Sum {N = num + sum<num-1>::N};  //简便写法
};
template<>
struct sum<1>
{
	enum Sum{ N=1 };   //枚举是一种类型，enum
};
int main()
{
	int n = 100;
	cout<<sum<100>::N<<endl;
	system("pause");
}
#endif
//5050

