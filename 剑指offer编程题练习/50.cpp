//写一个函数，用来把字符串转换成int整数
#include<iostream>
using namespace std;
enum Status{kValid = 0,kInvalid};
int g_nStatus = kValid;
long long int StrToIntCore(const char* digit,bool minus);
int StrToInt(const char* str)
{
	g_nStatus = kInvalid;
	long long int num = 0;
	if(NULL!=str&&*str!='\0')
	{
		//先判断字符串是不是开头有'+'或'-'
		bool minus = false;
		if(*str=='+')
			++str;
		else if(*str=='-')
		{
			++str;
			minus = true;
		}
		if(*str != '\0')
		{
			num = StrToIntCore(str,minus);
		}
	}
	return (int)num;
}
long long int StrToIntCore(const char* digit,bool minus)
{
	long long int num = 0;
	while(*digit != '\0')
	{
		if(*digit>='0'&&*digit<='9')
		{
			int flag = minus ? -1 : 1;
			num = num * 10 + flag * (*digit - '0');
			if((!minus&&num>0x7FFFFFFF)||  //整数溢出
				(minus&&num<(signed int)0x80000000))  //负数溢出
			{
				num = 0;
				break;
			}
			++digit;
		}
		else
		{
			num = 0;
			break;
		}
	}
	if(*digit == '\0')
	{
		g_nStatus = kValid;
	}
	return num;
}
int main()
{
	char arr[] = "+12345";
	cout<<StrToInt(arr)<<endl;
	cout<<endl;
	cout<<0x70000000<<endl;
	cout<<0x80000000<<endl;
	cout<<(signed int)0x80000000<<endl;
	cout<<(signed int)0x70000000<<endl;
	system("pause");
}
//12345
//
//1879048192
//2147483648
//-2147483648
//1879048192
