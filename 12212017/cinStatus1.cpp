 ///
 /// @file    cinStatus1.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2017-12-21 18:34:21
 ///
 
#include<iostream>
#include<limits>
using namespace std;
int main()
{
	int num;
	while(cin>>num,!cin.eof())   //这里可以是(cin>>num,1),不然cin异常就会推出while
	{
		if(cin.good())
		{
			cout<<"num="<<num<<endl;
		}
		else if(cin.fail())
		{
			cin.clear();   //重置输入流状态必须在ignore前面
			cin.ignore(numeric_limits<streamsize>::max(),'\n');
		}
		else
		{
			break;
		}
	}
	return 0;
}
//1
//num=1
//2
//num=2
//a
//b
//1
//num=1
//^Z
//[3]+  Stopped                 ./a.out
