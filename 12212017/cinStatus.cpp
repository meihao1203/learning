 ///
 /// @file    cinStatus.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2017-12-21 18:15:15
 ///
 
#include<iostream>
#include<limits>
using namespace std;
void print()
{
	cout<<"cin.badbit="<<cin.bad()<<endl;
	cout<<"cin.failbit="<<cin.fail()<<endl;
	cout<<"cin.eofbit="<<cin.eof()<<endl;
	cout<<"cin.goodbit="<<cin.good()<<endl;
	cout<<endl;
}
int main()
{
	print();
	int num;
	while(cin>>num)
		cout<<"num="<<num<<endl;
	print();
	cin.clear();
	print();
	cin.ignore(numeric_limits<streamsize>::max(),'\n');  //skip bad input
	//cin.ignore(1024,'\n');  //输入流忽略1024个字符或者直到遇到'\n'
	string s;   //输入流异常
	cin>>s;
	cout<<s<<endl;
	print();
	return 0;
}
//cin.badbit=0
//cin.failbit=0
//cin.eofbit=0
//cin.goodbit=1
//
//1
//num=1
//a
//cin.badbit=0
//cin.failbit=1
//cin.eofbit=0
//cin.goodbit=0
//
//cin.badbit=0
//cin.failbit=0
//cin.eofbit=0
//cin.goodbit=1
//
//abcd
//abcd
//cin.badbit=0
//cin.failbit=0
//cin.eofbit=0
//cin.goodbit=1
