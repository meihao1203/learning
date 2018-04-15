 ///
 /// @file    Noncopyable.h
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-04-15 15:06:59
 ///
 
#ifndef __NONCOPYABLE_H__
#define __NONCOPYABLE_H__
#include<iostream>
using namespace std;
namespace meihao
{
	class Noncopyable
	{
		protected:  // 构造函数为保护成员，类是抽象类
			Noncopyable(){  cout<<"Noncopyable()"<<endl;  }
			~Noncopyable(){  cout<<"~Noncopyable()"<<endl;  }
		private:  // 禁止派生类调用拷贝构造函数和赋值构造函数
			Noncopyable(const Noncopyable&);
			Noncopyable& operator=(const Noncopyable&);
	};
};
#endif
