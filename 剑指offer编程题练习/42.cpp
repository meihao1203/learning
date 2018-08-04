//题目42：输入一个英文句子，翻转句子中单词的顺序，但单词内只读的顺序不变。标点符号和普通字母一样处理。
//eg："I am a student."，"student. a am I"
//思路：先对这个字符串翻转，然后再对每一个单词翻转.
#include<iostream>
using namespace std;
void reverse(char* pBegin,char* pEnd);
void reverseSentence(char* pstr);
void test(char* str);
int main()
{
	char str[] = "  I  am a student.  ";  //这里是常量字符串const char*，存放在文字常量区，是不能交换的。
	test(str);
}
void test(char* str)
{
	cout<<str<<endl;
	reverseSentence(str);
	cout<<str<<endl;
	reverseSentence(str);
	cout<<str<<endl;
}
void reverseSentence(char* pstr)
{
	if(NULL==pstr)
		return ;
	//对整个句子进行翻转
	char* pBegin = pstr;
	char* pEnd = pstr;
	while(*pEnd!='\0')
		++pEnd;
	reverse(pBegin,--pEnd);
	//对句子中每个单词翻转
	pBegin = pEnd = pstr;
	while(*pBegin!='\0')
	{
		while(*pBegin==' ')
		{ //找到第一个不为空格的字符
			++pBegin;
			++pEnd;
		}
		while(*pEnd!=' '&&*pEnd!='\0')  //找到字符后出现的第一个空格
		{
			++pEnd;
		}
		reverse(pBegin,--pEnd);  //这里是先减一操作，完了再传参
		++pEnd;
		pBegin = pEnd;
	}
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
 //I  am a student.
 //student. a am  I
 //I  am a student.
