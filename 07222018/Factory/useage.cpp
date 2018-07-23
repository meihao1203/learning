 ///
 /// @file    useage.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-07-22 16:56:55
 ///
 
#include<iostream>
#include"factory.h"
using namespace std;
int main()
{
	factory* fac = new myFactory();
	product* pro = fac->create();
	pro->display();
	delete pro;
	delete fac;
	return 0;
}
//factory()
//myFactory()
//A()
//product()
//myProduct()
//this is myProduct display
//~myProduct()
//~product()
//~myFactory()
//~factory()
