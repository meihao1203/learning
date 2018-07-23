 ///
 /// @file    factory.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-07-22 16:53:59
 ///
 
#include<iostream>
#include"factory.h"
using namespace std;
product* myFactory::create()
{
	A* a = new A();
	product* tmp = new myProduct(a);
	return tmp;
}
