 ///
 /// @file    factory.h
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-04-14 08:56:06
 ///
 
//作用：
//定义一个用于创建对象的接口，让子类决定实例化哪一个类。Factory Method
//使一个类的实例化延迟到其子类。
#ifndef __FACTORY_H__
#define __FACTORY_H__
#include<iostream>
using namespace std;
class product
{
	public:
		product(){  cout<<"product()"<<endl;  }
		virtual ~product(){  cout<<"~product()"<<endl;  }
};
class A
{
	public:
		A(){  cout<<"A()"<<endl;  }
		~A(){  cout<<"~A()"<<endl;  }
};
class B
{
	public:
		B(){  cout<<"B()"<<endl;  }
		~B(){  cout<<"~B()"<<endl;  }
};
class concreteproduct:public product
{
	public:
		concreteproduct(A* pa,B* pb):_pa(pa),_pb(pb)
		{
			cout<<"concreteproduct()"<<endl;  
		}
		~concreteproduct(){  cout<<"~concreteproduct()"<<endl;  }
	private:
		A* _pa;
		B* _pb;
};
class factory
{
	public:
		factory(){  cout<<"factory()"<<endl;  }
		// 抽象类
		virtual product* create() = 0;
		virtual ~factory(){  cout<<"~factory()"<<endl;  }
};
class concretefactory:public factory
{
	public:
		concretefactory(){  cout<<"concretefactory()"<<endl;  }
		product* create();
		~concretefactory(){  cout<<"~concretefactory()"<<endl;  }
};
product* concretefactory::create()
{
	cout<<"concretefactory::create()"<<endl;
	A* pa = new A();
	B* pb = new B();
	product* pro = new concreteproduct(pa,pb);
	return pro;
}
endif
