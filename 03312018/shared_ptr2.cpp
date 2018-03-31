 ///
 /// @file    shared_ptr2.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-03-31 10:48:41
 ///
 
#include<iostream>
#include<memory>
using namespace std;
class child;  
class father
{
	public:
		father(){ cout<<"father()"<<endl; }
		~father(){ cout<<"~father()"<<endl; }
		// child* _child;
		shared_ptr<child> _child;
};
class child
{
	public:
		child(){ cout<<"child()"<<endl; }
		~child(){ cout<<"~child()"<<endl; }
		//father* _father;
		shared_ptr<father> _father;
};
int main()
{
	shared_ptr<father> sp1(new father);  // sp1什么的是一个指针了
	shared_ptr<child> sp2(new child);
	cout<<"sp1.use_count="<<sp1.use_count()<<endl;
	cout<<"sp2.use_count="<<sp2.use_count()<<endl;
	sp1->_child = sp2;  // 循环引用
	sp2->_father = sp1;
	cout<<"sp1.use_count="<<sp1.use_count()<<endl;
	cout<<"sp2.use_count="<<sp2.use_count()<<endl;
	// 循环引用，内存泄露
	return 0;
}
//father()
//child()
//sp1.use_count=1
//sp2.use_count=1
//sp1.use_count=2
//sp2.use_count=2
