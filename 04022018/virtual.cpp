 ///
 /// @file    virtual.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-04-02 15:07:02
 ///
 
#include<iostream>
using namespace std;
class base
{
	public:
		virtual int func(int elem)
		{
			cout<<"base::func(int)"<<endl;
			return elem;
		}
};
class derived:public base
{
	public:
		int func(int elem)  // 不加virtual关键字也是虚函数
		{
			cout<<"derived::func(elem)"<<endl;
			return elem;
		}
};
void testFunc(base& rhs)
{
	cout<<rhs.func(5)<<endl;
}
int main()
{
	base b;
	derived d;
	testFunc(b);
	testFunc(d);
	cout<<endl;
	base& ref = d;  // 动态链编，和引用指针类型无关，只跟具体的对象有关
	cout<<ref.func(7)<<endl;
	base* pb = &d;
	cout<<pb->func(8)<<endl;
	return 0;
}
//base::func(int)
//5
//derived::func(elem)
//5
//
//derived::func(elem)
//7
//derived::func(elem)
//8
