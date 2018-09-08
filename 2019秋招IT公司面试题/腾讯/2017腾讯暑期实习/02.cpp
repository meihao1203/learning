//小Q最近遇到了一个难题：把一个字符串的大写字母放到字符串的后面，各个字符的相对位置不变，且不能申请额外的空间。
//你能帮帮小Q吗？
//
//输入描述:
//
//输入数据有多组，每组包含一个字符串s，且保证:1<=s.length<=1000.
//  
//
//输出描述:
//
//对于每组数据，输出移位后的字符串。
//
//输入例子1:
//
//AkleBiCeilD
//
//输出例子1:
//
//kleieilABCD
#if 0
#include<iostream>
#include<string>
#include<queue>
using namespace std;
int main()
{
	string data;
	queue<string> answer;
	while(cin>>data)
	{
		string tmp(data);
		int iidx = 0;
		for(int idx=0;idx!=data.size();++idx)
		{
			if(data[idx]>='a'&&data[idx]<='z')
				tmp[iidx++] = data[idx];
		}
		for(int idx=0;idx!=data.size();++idx)
		{
			if(data[idx]>='A'&&data[idx]<='Z')
				tmp[iidx++] = data[idx];
		}
		data = tmp;
		answer.push(data);
	}
	while(!answer.empty())
	{
		cout<<answer.front()<<endl;
		answer.pop();
	}
	//system("pause");
}
#endif