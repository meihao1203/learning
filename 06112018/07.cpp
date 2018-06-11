////题目42(扩展)：字符串坐旋转，把字符串前面的若干个字转移到字符串的尾部。
//eg："abcdefg"和数字2，-> "cdefgab"
#include<iostream>
#include<string.h>
using namespace std;
void reverse(char* pBegin,char* pEnd);
void leftReverse(char* pstr,int n);
void test(char* str,int n);
int main()
{
	char str[] = "abcdefg";  //这里是常量字符串const char*，存放在文字常量区，是不能交换的。
	test(str,2);
	cout<<endl;

	char str2[] = "I am a student.";
	test(str2,4);
	cout<<endl;

	system("pause");
}
void test(char* str,int n)
{
	cout<<str<<endl;
	leftReverse(str,n);
	cout<<str<<endl;
}
void leftReverse(char* pstr,int n)
{
	if(NULL==pstr||n<=0)
		return ;
	int len = strlen(pstr);
	if(len<n)
		return ;
	char* pBegin = pstr;
	char* pEnd = pBegin + len - 1;
	reverse(pBegin,pEnd);

	pBegin = pstr;
	pEnd = pBegin + len - 1 - n;
	reverse(pBegin,pEnd);

	pBegin = pEnd + 1;
	pEnd = pEnd + n;
	reverse(pBegin,pEnd);
}
void reverse(char* pBegin,char* pEnd)
{
	if(NULL==pBegin||NULL==pEnd)
		return ;
	while(pBegin<pEnd)
	{
		char tmp = *pBegin;
		*pBegin = *pEnd;
		*pEnd = tmp;
		++pBegin;
		--pEnd;
	}
}
//abcdefg
//cdefgab
//
//I am a student.
// a student.I am
//
