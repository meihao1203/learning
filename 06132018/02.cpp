//题目48：不能对继承的类。用C++设计一个不能被继承的类
//思路：
//思路一：构造函数和析构函数私有，提供静态接口创建堆上的对象
//思路二，利用虚继承，这样派生类在创建对象的时候首先根据虚函数表先创建虚基类对象，但是虚基类构造函数私有不能创建。
//这种方法要有三个类

//思路二
#if 0
#include<iostream>
using namespace std;
class A
{
	friend class B;  //这个可以用模板来表示，模板参数做为友元类，VS可以通过编译，但是GCC不行
private:
	A(){ cout<<"A()"<<endl; }
	~A(){ cout<<"~A()"<<endl; }
};
class B:virtual public A
{
public:   
	B(){ cout<<"B()"<<endl; }
	~B(){ cout<<"~B()"<<endl; }
	A a;  //类B里面随意创建类A的对象，可以是栈对象也可以是堆对象
}; //类B是类A的友元类，可以在类B中随意调用类A的构造函数创建对象
class C:public B
{
public:
	// C(){ cout<<"C()"<<endl; }   //类C不是类A的友元函数，并且类B是虚拟继承的类A，派生类创建构造函数不是先调用父类的构造函数
	//而是先从虚基类开始调构造函数  
	// ~C(){ cout<<"~C()"<<endl; }
};
int main()
{
	B b;
	system("pause");
}
#endif
//A()
//A()
//B()