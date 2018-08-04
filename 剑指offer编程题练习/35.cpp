//题目35：在字符串中找出第一个只出现一次的字符。如输入"abaccdeff"，则输出'b'。
//思路：习惯性思维就是从头开始暴力破解，复杂度O(n^2);
//字符的ASCII码占一个字节，有256种可表示的字符，这里不再仅限于26个英文字符。
//建立一个简单的hash表，一个整数4个字节，2^2*2^8=1K大小，第一次全部初始化为0。
//遍历字符串，每个字符代表的ASCII码做为数组下标，对应的值+1.最后再次遍历字符串，找出第一个出现次数为1的字符。
#if 1
#include<iostream>
#include<string>
using namespace std;
char findFirstAppearOneceChar(const char* str);
void test(const char* str,char expected);
int main()
{
	test("abaccdeff",'b');
	cout<<endl;

	test("aabbcc",-1);
	cout<<endl;

	test("abcabder",'c');
	cout<<endl;

	test("",-1);
	cout<<endl;

	const char* str = NULL;
	test(str,-1);
	system("pause");
}
void test(const char* str,char expected)
{
	if(findFirstAppearOneceChar(str)==expected)
		return;
	else
		cout<<str<<" "<<findFirstAppearOneceChar(str)<<" false"<<endl;
}
char findFirstAppearOneceChar(const char* str)
{
	if(NULL==str)
		return -1;
	char* hashTable = new char[256];  //一个字节可以表示256中字符
	memset(hashTable,0,256);
	const char* pstr = str;
	while(*pstr!='\0')
	{
		++hashTable[(int)(*pstr)];
		pstr++;
	}
	pstr = str;
	while(*pstr!='\0')
	{
		if(hashTable[(int)(*pstr)]==1)
			return *pstr;
		++pstr;
	}
	return -1;
}
#endif