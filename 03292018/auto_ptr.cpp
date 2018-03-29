 ///
 /// @file    auto_ptr.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-03-29 20:07:19
 ///
 
#include<iostream>
#include<memory>
using namespace std;
int main()
{
	double* a = new double(123.45);
	auto_ptr<double> ta(a);
	cout<<"addr a="<<a<<"  *a="<<*a<<endl;
	cout<<"addr ta="<<ta.get()<<"  *ta="<<*ta<<endl;

	int* b = new int(10);
	auto_ptr<int> tb(b);
	auto_ptr<int> tbb(tb);
//表达的是值语义,但是实现有缺陷,在底层已经发生了所有权的转移
	cout<<"addr b="<<b<<"  *b="<<*b<<endl;
	cout<<"addr tbb="<<tbb.get()<<"  *tbb="<<*tbb<<endl;
	cout<<"addr tb="<<tb.get()<<"  *tb="<<*tb<<endl;  // tb已经不能再用了，所有权已经转移了
	return 0;
}
//addr a=0xc83c20  *a=123.45
//addr ta=0xc83c20  *ta=123.45
//addr b=0xc84050  *b=10
//addr tbb=0xc84050  *tbb=10
//Segmentation fault (core dumped)
