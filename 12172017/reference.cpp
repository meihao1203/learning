 ///
 /// @file    reference.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2017-12-17 17:15:27
 ///
 
#include<iostream>
using namespace std;
class point
{
	private:
		int _ix;
		int _iy;
		int &_rix;
		double &_rdz;
	public:
		point(int ix,int iy,double &rdz)
			//:_ix(ix),_iy(iy),_rix(ix),_rdz(rdz)   //error,应用的是一个局部变量，局部变量释放就错了
			:_ix(ix),_iy(iy),_rix(_ix),_rdz(rdz)
		{
			cout<<"构造函数"<<endl;
		}
		//如果调用了拷贝构造函数，那么两个对象的_rix就都是引用的同一个_ix
		point(const point &rhs):_ix(rhs._ix),_iy(rhs._iy),_rix(rhs._rix),_rdz(rhs._rdz)
		{
			cout<<"拷贝构造函数"<<endl;
		}
		void print()
		{
			cout<<"("<<_ix<<","<<_iy<<","<<_rix<<","<<_rdz<<")"<<endl;
		}
		void set_Ix(int ix)
		{
			_ix = ix;
		}
};
int main(void)
{
	double d = 1.1;
	point p1(3,4,d);
	p1.print();
	point p2(p1);
	p2.print();
	cout<<"------------"<<endl;
	p1.set_Ix(7);
	p1.print();
	p2.print();
	cout<<"------------"<<endl;
	d = 9.9;
	p1.print();
	p2.print();
	return 0;
}
//构造函数引用了局部变量的后果
//构造函数
//(3,4,32767,1.1)
//拷贝构造函数
//(3,4,32767,1.1)
//(7,4,32767,1.1)
//(3,4,32767,1.1)

//构造函数
//(3,4,3,1.1)
//拷贝构造函数
//(3,4,3,1.1)
//------------
//(7,4,7,1.1)
//(3,4,7,1.1)
//------------
//(7,4,7,9.9)
//(3,4,7,9.9)
