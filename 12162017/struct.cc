 ///
 /// @file    struct.cc
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2017-12-16 09:08:50
 ///
 
#include<iostream>
using namespace std;
struct mh
{
	int a;
	int b;
};
class MH
{
	//private:     //不写默认是private
	public:
		MH();
		void setIa(int Ia);
		void setIb(int Ib);
	private:
		int _ia;
		int _ib;
};
int main(void)
{
	mh n1;
	n1.a = 10;
	n1.b = 20;
	MH n2;
	n2.setIa(100);
	n2.setIb(200);
	return 0;
}
void MH::setIa(int Ia)
{
	_ia = Ia;
}
void MH::setIb(int Ib)
{
	_ib = Ib;
}
MH::MH()
{
	cout<<"构造函数"<<endl;
}
