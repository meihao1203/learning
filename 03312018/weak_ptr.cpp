 ///
 /// @file    weak_ptr.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-03-31 16:31:30
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
		weak_ptr<child> _child;
};
class child
{
	public:
		child(){ cout<<"child()"<<endl; }
		~child(){ cout<<"~child()"<<endl; }
		shared_ptr<father> _father;
};
int main()
{
	shared_ptr<father> sp1(new father);
	shared_ptr<child> sp2(new child);
	cout<<"addr sp1="<<sp1.get()<<"sp1 use count="<<sp1.use_count()<<endl;;
	cout<<"addr sp2="<<sp2.get()<<"sp2 use count="<<sp2.use_count()<<endl;;

	sp1->_child = sp2;
	sp2->_father = sp1;
	cout<<"addr sp1="<<sp1.get()<<"sp1 use count="<<sp1.use_count()<<endl;;
	cout<<"addr sp2="<<sp2.get()<<"sp2 use count="<<sp2.use_count()<<endl;;
	
	return 0;
}
//father()
//child()
//addr sp1=0x21c5c20sp1 use count=1
//addr sp2=0x21c6070sp2 use count=1
//addr sp1=0x21c5c20sp1 use count=2
//addr sp2=0x21c6070sp2 use count=1
//~child()
//~father()
