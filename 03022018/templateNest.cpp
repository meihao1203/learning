 ///
 /// @file    templateNest.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-03-02 13:51:41
 ///
 
#include<iostream>
using namespace std;
template<class T,class T1>
class outside
{
	public:
		template<class D> 
		class inside;  // 类模板前向声明
	private:
		inside<T1> _is;
		T _a;
	public:
		outside(T a,T1 is):_a(a),_is(inside<T1>(is)){}
		void disp();
		template<class D>
		class inside
		{
			public:
				inside(D b):_b(b){}
				void disp();
			private:
				D _b;
		};
};
template<class T,class T1>
void outside<T,T1>::disp()
{
	cout<<"outside::disp()"<<endl;
	cout<<_a<<endl;
	_is.disp();
}
template<class T,class T1>
template<class D>
void outside<T,T1>::inside<D>::disp()
{
	cout<<"inside::disp()"<<endl;
	cout<<_b<<endl;
}
int main()
{
	outside<int,double>::inside<double> iner(3.2);  // 定义嵌套类模板的类对象
	iner.disp();
	outside<int,double> out(3,3.33);
	out.disp();
	return 0;
}
//inside::disp()
//3.2
//outside::disp()
//3
//inside::disp()
//3.33
