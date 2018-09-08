//假定一种编码的编码范围是a ~ y的25个字母，从1位到4位的编码，如果我们把该编码按字典序排序，形成一个数组如下： a, aa, aaa, aaaa, aaab, aaac, … …, b, ba, baa, baaa, baab, baac … …, yyyw, yyyx, yyyy 其中a的Index为0，aa的Index为1，aaa的Index为2，以此类推。 编写一个函数，输入是任意一个编码，输出这个编码对应的Index.
//输入描述:
//输入一个待编码的字符串,字符串长度小于等于100.
//输出描述:
//输出这个编码的index
#if 0
#include<iostream>
#include<string>
using namespace std;
int index(const string& str);
int main()
{
	string str;
	cin>>str;
	cout<<index(str);
	//system("pause");
}
int index(const string& str)
{
	if(""==str)
		return -1;
	static const int NUM = 25;
	//定义数组存放每一位的差值
	// 0 1 2 3对应字符串从左到右的位数
	int cnt[4] = {1};
	for(int idx=1;idx!=4;++idx)
	{
		cnt[idx] = NUM*cnt[idx-1] + 1;
	}
	int index = 0;
	//原字符串从高位到低位
	for(int idx=0;idx!=str.size();++idx)
	{
  		index += (str[idx] - 'a')*cnt[4-idx-1] + 1;  //加1是加自身
	}
	return index - 1; //最低位不能+1，但是统一操作所以加了1
}
#endif