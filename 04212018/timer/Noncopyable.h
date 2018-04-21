 ///
 /// @file    Noncopyable.h
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-04-21 09:57:31
 ///
 
#ifndef __NONCOPYABLE_H__
#define __NONCOPYABLE_H__
#include<iostream>
using namespace std;
namespace meihao
{
	class Noncopyable
	{
		public:
			Noncopyable(){};
			~Noncopyable(){};
		private:
			Noncopyable(const Noncopyable&);
			Noncopyable& operator=(const Noncopyable&);
	};
};
#endif 
