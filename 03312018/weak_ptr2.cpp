 ///
 /// @file    weak_ptr2.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-03-31 17:11:26
 ///
 
#include<iostream>
#include<memory>
using namespace std;
class X
{
	public:
		X(){ cout<<"X()"<<endl; }
		~X(){ cout<<"~X()"<<endl; }
		void fun(){ cout<<"X::fun()"<<endl; }
};
int main()
{
	weak_ptr<X> wp;
	{
		cout<<"wp use count="<<wp.use_count()<<endl;  // weak_ptr没有get成员
		cout<<endl;
		shared_ptr<X> sp(new X);
		cout<<"addr ap="<<sp.get()<<"  sp use count="<<sp.use_count()<<endl;
		cout<<endl;
		wp = sp;  // 并没有增加引用计数
		cout<<"addr ap="<<sp.get()<<"  sp use count="<<sp.use_count()<<endl;
		cout<<"wp use count="<<wp.use_count()<<endl;
		cout<<endl;

		shared_ptr<X> sp2 = wp.lock();  // 弱引用要提升为强引用才能访问托管对象
		cout<<"addr ap="<<sp.get()<<"  sp use count="<<sp.use_count()<<endl;
		cout<<"wp use count="<<wp.use_count()<<endl;
		cout<<"addr sp2="<<sp2.get()<<"  sp2 use count="<<sp2.use_count()<<endl;
		if(!sp2){  cout<<"object is destroyed!"<<endl;  }
		else
		{// 引用计数+1
			sp2->fun();
			cout<<"weak_ptr lock 成功"<<endl;
		}
	}  // 离开作用域,ap、sp2被释放  weak_ptr知道自己托管的对象是否释放了
	cout<<endl;
	shared_ptr<X> sp3 = wp.lock();  // new X的对象已经释放了，提升失败
	if(!sp3){  cout<<"object is destroyed!"<<endl;  }
	else 
	{  
		sp3->fun();
		cout<<"weak_ptr lock 成功"<<endl;
	}
	cout<<"wp use count="<<wp.use_count()<<endl;
	cout<<"addr sp3="<<sp3.get()<<"  sp3 use count="<<sp3.use_count()<<endl;

	return 0;
}
//wp use count=0
//
//X()
//addr ap=0x1eb3030  sp use count=1
//
//addr ap=0x1eb3030  sp use count=1
//wp use count=1
//
//addr ap=0x1eb3030  sp use count=2
//wp use count=2
//addr sp2=0x1eb3030  sp2 use count=2
//X::fun()
//weak_ptr lock 成功
//~X()
//
//object is destroyed!
//wp use count=0
//addr sp3=0  sp3 use count=0
