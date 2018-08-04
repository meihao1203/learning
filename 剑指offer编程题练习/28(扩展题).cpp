//题目28扩展：求字符的所有组合
//eg:a,b,c;a,b,c,ab,ac,bc,abc
//思路：从1个的组合到字符个数个组合
//分两步：n-1个字符串中长度为m-1的组合；n-1个字符的长度中长度为m的组合
//eg:a -> (b,c)中取长度0的组合；(b,c)中取长度1的组合
//递归出口：长度=0或者字符串到达末尾。
#include<iostream>
#include<string>
using namespace std;
void Combination(char* str,int length);
void combination(char* str,int length,string result);
void test(char* str,int length);
int main()
{
	char str[] = "abc";
	test(str,strlen(str));
	cout<<endl;

	char str2[] = "ab";
	test(str2,strlen(str2));
	cout<<endl;

	char* str3 = NULL;
	test(str3,0);
	cout<<endl;

	char str4[] = "";
	test(str4,1);
	cout<<endl;

	char str5[] = "a";
	test(str5,2);
	cout<<endl;

	system("pause");
}
void test(char* str,int length)
{
	if(NULL==str)
		cout<<"origin str is NULL"<<endl;
	else
	cout<<"origin str="<<str<<endl;
	Combination(str,length);
}
void combination(char* str,int length,string result)
{
	if(*str=='\0'||length==0)
	{
		cout<<result<<endl;
		return ;
	}
	string tmp = result + *str;
	if( strlen(str+1)>=length-1 )
	{
		combination(str+1,length-1,tmp);
	}
	if(strlen(str+1)>=length)
	{
		combination(str+1,length,result);
	}
}
void Combination(char* str,int length)
{
	if(NULL==str||length<=0)
		return;
	string res;
	for(int idx = 1;idx<=length;++idx)
	{
		combination(str,idx,res);
	}
}
