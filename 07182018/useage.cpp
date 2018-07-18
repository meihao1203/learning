 ///
 /// @file    useage.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-07-18 20:03:38
 ///
 
#include<iostream>
#include"Singleton.h"
using namespace std;
using namespace meihao;
int main()
{
	Singleton* ptr1 = Singleton::getInstance();
	Singleton* ptr2 = Singleton::getInstance();
	Singleton* ptr3 = Singleton::getInstance();
	cout<<"pstr1="<<ptr1<<endl;
	cout<<"pstr2="<<ptr2<<endl;
	cout<<"pstr3="<<ptr3<<endl;
	return 0;
}
//getInstance()
//init()
//Singleton()
//getInstance()
//getInstance()
//pstr1=0x1694030
//pstr2=0x1694030
//pstr3=0x1694030
//destroy()
//~Singleton()
