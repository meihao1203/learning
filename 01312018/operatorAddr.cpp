 ///
 /// @file    operatorAddr.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-01-31 15:44:41
 ///
 
#include<iostream>
using namespace std;
class data
{
	public:
		data()
		{
			cout<<"data()"<<endl;
		}
		int size()
		{
			return 5;
		}
};
class Data
{
	public:
		Data():_pstr(new data)
		{
			cout<<"Data()"<<endl;
		}
		data* operator->()   //返回data类型的指针
		{
			return _pstr;
		}
	private:
		data* _pstr;
};
int main()
{
	Data p;
	cout<<p->size()<<endl;
	cout<<(p.operator->())->size()<<endl;
	return 0;
}
//data()
//Data()
//5
//5
