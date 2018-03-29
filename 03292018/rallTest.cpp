 ///
 /// @file    test.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-03-29 16:37:39
 ///
 
#include<iostream>
#include"RALL.h"
using namespace std;
class resource
{
	public:
		resource(){cout<<"resource::resouce()"<<endl;}
		~resource(){cout<<"resource::~resource()"<<endl;}
	private:
};
class test
{
	public:
		test():_p(new resource){ cout<<"test::test()"<<endl; }
		~test(){ cout<<"test::~test()"<<endl; }
		//拷贝构造函数
		//RALL类重载了*运算符，这里new的同时
		//直接用rhs的值来初始化新开辟的空间
		test(const test& rhs):_p(new resource(*rhs._p))
		{ cout<<"test::test(const test&)"<<endl; }
//		test& operator=(const test& rhs)
//		{
//			cout<<"test::operator=(const test&)"<<endl;
//			if(this==&rhs){return *this;}
//			//delete this->_p.get();
//			//*_p = *(rhs._p);
//			_p.reset((rhs._p).get());  // 函数里面已经写了释放
//			return *this;
//		}
	private:
		test& operator=(const test& rhs);  // 赋值构造函数造成多个指针指向一块区域
		// dubble free
	private:
		RALL<resource> _p;
};
int main()
{
	test em;
	cout<<"--------------------------"<<endl;
	test em2;
	cout<<"**************************"<<endl;
	//em2 = em;  // 这里赋值了会导致em2和em释放，段错误
	//后面我在RALL类里面的析构函数做了特殊处理，指针为NULL才delete
	cout<<"准备开始释放资源:"<<endl;
	return 0;
}
//resource::resouce()
//托管资源
//test::test()
//--------------------------
//resource::resouce()
//托管资源
//test::test()
//**************************
//test::operator=(const test&)
//resource::~resource()
//准备开始释放资源:
//test::~test()
//释放资源
//test::~test()
//释放资源
