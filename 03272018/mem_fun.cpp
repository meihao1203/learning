 ///
 /// @file    mem_fun.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-03-27 16:43:29
 ///
 
//成员函数适配器
//mem_fun()  //函数参数为类指针
#include<iostream>
#include<functional>
#include<algorithm>
#include<vector>
using namespace std;
class Num
{
	int _val;
	public:
	Num(){ _val=0; }
	Num(int val){ _val=val; }
	bool display(){ cout<<_val<<"  "; return true; }
	int squareval(){ _val*=_val; return _val; }
	int lessconst(int k){ _val-=k;return _val; }
	friend ostream& operator<<(ostream& os,const Num& rhs);
};
ostream& operator<<(ostream& os,const Num& rhs)
{
	os<<rhs._val;
}
int main()
{
	vector<Num*> v1;
	Num arr[10];
	for(int i=0;i<10;++i)
	{
		arr[i] = Num(i+1);
		v1.push_back(&arr[i]);
	}
	cout<<"原始数据："<<endl;
	for_each(v1.begin(),v1.end(),mem_fun(&Num::display));
	//for_each(v1.begin(),v1.end(),mem_fun<bool,Num>(&Num::display));
	cout<<endl;
	// for_each(v1.begin(),v1.end(),mem_fun(&Num::squareval));
	for_each(v1.begin(),v1.end(),mem_fun<int,Num>(&Num::squareval));
	cout<<"数据平方："<<endl;
	for(auto& elem:v1)
	cout<<*elem<<"  ";
	cout<<endl;
	for_each(v1.begin(),v1.end(),bind2nd(mem_fun<int,Num>(&Num::lessconst),5));
	// bind2nd(函数对象,指定值) 把指定值绑定到函数对象的第二个参数上
	cout<<"减去常数："<<endl;
	for(auto& elem:v1)
	cout<<*elem<<"  ";
	cout<<endl;
	return 0;
}
//原始数据：
//1  2  3  4  5  6  7  8  9  10  
//数据平方：
//1  4  9  16  25  36  49  64  81  100  
//减去常数：
//-4  -1  4  11  20  31  44  59  76  95  
