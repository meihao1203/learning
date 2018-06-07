//题目28：字符串的排列，输入一个字符串，打印出该字符串的所有排列。
//eg:输入字符串abc,则打印出由字符a、b、c所能排列出来的所有字符串abc、acb、bac、bca、cab、cba
//思路：从字符串的第一个字符开始，一次和后面的所有元素交换
//交换完之后，再以后面的字符串中的第一个元素开始，和前面一样，交换后面字符串的多有元素
//就是一个递归过程
#include<iostream>
using namespace std;
void test(char* str);
void permutationStr(char* str,char *beginStr);
int main()
{
	char str[] = "abc";
	test(str);
	cout<<endl;

	char str2[] = "a";
	test(str2);
	cout<<endl;

	char* str3 = NULL;
	test(str3);
	cout<<endl;

	char str4[] = "";
	test(str4);
	cout<<endl;

	system("pause");
}
void test(char* str)
{
	if(NULL==str)
		return ;
	cout<<"origin str="<<str<<endl;
	permutationStr(str,str);
}
void permutationStr(char* str,char *beginStr)
{
	if(NULL==str)
		return ;
	if(*beginStr=='\0')
		cout<<str<<endl;
	for(char* ch = beginStr;*ch!='\0';++ch)
	{
		char tmp = *ch;
		*ch = *beginStr;
		*beginStr = tmp;
		permutationStr(str,beginStr+1);
		//重点，前面交换把最原始的字符串修改了，后面要改回来
		//eg:第一次交换abc,第二次bac,第三次cab
		//我们要的结果是abc,bac,cba
		*beginStr = *ch;  
		*ch = tmp;
	}
}
//origin str=abc
//abc
//acb
//bac
//bca
//cba
//cab
//
//origin str=a
//a
//
//
//origin str=
