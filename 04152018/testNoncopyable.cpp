 //
 /// @file    testNoncopyable.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-04-15 11:38:34
 ///
 
#include<iostream>
using namespace std;
class Noncopyable
{
	protected:  // 保护成员，类外也不能调用构造函数
		Noncopyable(){  cout<<"Noncopyable()"<<endl;  }
		~Noncopyable(){  cout<<"~Noncopyable()"<<endl;  }
	private:  // 不显示定义，防止调用拷贝，下面test b=a就是对的
		//Noncopyable(const Noncopyable&){  cout<<"Noncopyable(const Noncopyable&)"<<endl;  }
		//Noncopyable& operator=(const Noncopyable&){  cout<<"Noncopyable& operator=(const Noncopyable&)"<<endl; }
};
//class test: Noncopyable  // 相当于私有继承
class test:private Noncopyable
{
	public:
		test(){  cout<<"test()"<<endl;  }
		~test(){  cout<<"~test()"<<endl;  }
};
int main()
{
	test a;
	test b = a;
	//Noncopyable b;
}
