 ///
 /// @file    test.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-04-14 09:14:51
 ///
 
#include<iostream>
#include"factory.h"
using namespace std;
int main()
{ // 工厂模式主要用来创建复杂对象
  // 一个产品对应一个工厂类
	factory* fac = new concretefactory();
	product* pro = fac->create();
	delete fac;
	delete pro;
	return 0;
}
//factory()
//concretefactory()
//concretefactory::create()
//A()
//B()
//product()
//concreteproduct()
//~concretefactory()
//~factory()
//~concreteproduct()
//~product()
