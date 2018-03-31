 ///
 /// @file    shared_ptr.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-03-31 10:42:47
 ///
 
#include<iostream>
#include<memory>
using namespace std;
int main()
{
	shared_ptr<int> sp(new int(1));
	cout<<"*sp="<<*sp<<"  sp.use_count="<<sp.use_count()<<endl;
	shared_ptr<int> sp2 = sp;  // 赋值,只是引用计数增加1
	cout<<"*sp="<<*sp<<"  sp.use_count="<<sp.use_count()<<endl;
	cout<<"*sp2="<<*sp2<<"  sp2.use_count="<<sp2.use_count()<<endl;
}
//*sp=1  sp.use_count=1
//*sp=1  sp.use_count=2
//*sp2=1  sp2.use_count=2
