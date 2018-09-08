//输入的第一行为一个正整数T，表示测试数据组数。 接下来有T组数据。每组数据的第一行包括两个整数m和n，
//表示字符迷阵的行数和列数。接下来有m行，每一行为一个长度为n的字符串，按顺序表示每一行之中的字符。
//再接下来还有一行包括一个字符串，表示要寻找的单词。  数据范围： 对于所有数据，都满足1<=T<=9，
//且输入的所有位于字符迷阵和单词中的字符都为大写字母。要寻找的单词最短为2个字符，最长为9个字符。
//字符迷阵和行列数，最小为1，最多为99。 对于其中50%的数据文件，字符迷阵的行列数更限制为最多为20。
//

//输出描述:
//
//对于每一组数据，输出一行，包含一个整数，为在给定的字符迷阵中找到给定的单词的合法方案数。
//
//输入例子1:
//
//3
//10 10
//AAAAAADROW
//WORDBBBBBB
//OCCCWCCCCC
//RFFFFOFFFF
//DHHHHHRHHH
//ZWZVVVVDID
//ZOZVXXDKIR
//ZRZVXRXKIO
//ZDZVOXXKIW
//ZZZWXXXKIK
//WORD
//3 3
//AAA
//AAA
//AAA
//AA
//5 8
//WORDSWOR
//ORDSWORD
//RDSWORDS
//DSWORDSW
//SWORDSWO
//SWORD
//
//
//输出例子1:
//
//4
//16
//5
#if 0
#include<iostream>
#include<vector>
#include<string>
using namespace std;
static int cnts = 0;
void statistic(char (*arr)[99],int rows,int colums,string words);
int main()
{
	int demos;
	cin>>demos;
	vector<int>  answer;
	char dataArr[99][99];
	while(demos)
	{
		int rows,colums;
		cin>>rows>>colums;
		string tmp;
		for(int idx=0;idx!=rows;++idx)
		{
			cin>>tmp;
			for(int iidx=0;iidx!=colums;++iidx)
			{
				dataArr[idx][iidx] = tmp[iidx];
			}
		}
		cnts = 0;
		string words;
		cin>>words;
		statistic(dataArr,rows,colums,words);
		answer.push_back(cnts);
		--demos;
	}
	for(auto&elem:answer)
		cout<<elem<<endl;
	//system("pause");
}
void core(char (*arr)[99],int rows,int colums,int mrows,int mcolums,string tmp,string words);
void statistic(char (*arr)[99],int rows,int colums,string words)
{
	if(NULL==arr)
		return ;
	for(int idx=0;idx!=rows;++idx)
	{
		for(int iidx=0;iidx!=colums;++iidx)
		{
			string tmp;
			core(arr,rows-1,colums-1,idx,iidx,tmp,words);
		}
	}
}
void rightCore(char (*arr)[99],int rows,int colums,int mrows,int mcolums,string tmp,string words)
{
	if(mrows>rows||mcolums>colums||tmp.size()>words.size())
		return ;
	tmp += arr[mrows][mcolums];
	if(tmp==words)
	{
		++cnts;
		return ;
	}
	//右方
	rightCore(arr,rows,colums,mrows,mcolums+1,tmp,words);
}
void downCore(char (*arr)[99],int rows,int colums,int mrows,int mcolums,string tmp,string words)
{
	if(mrows>rows||mcolums>colums||tmp.size()>words.size())
		return ;
	tmp += arr[mrows][mcolums];
	if(tmp==words)
	{
		++cnts;
		return ;
	}
	//下方
	downCore(arr,rows,colums,mrows+1,mcolums,tmp,words);
}
void rightDownCore(char (*arr)[99],int rows,int colums,int mrows,int mcolums,string tmp,string words)
{
	if(mrows>rows||mcolums>colums||tmp.size()>words.size())
		return ;
	tmp += arr[mrows][mcolums];
	if(tmp==words)
	{
		++cnts;
		return ;
	}
	//右下
	rightDownCore(arr,rows,colums,mrows+1,mcolums+1,tmp,words);
}

void core(char (*arr)[99],int rows,int colums,int mrows,int mcolums,string tmp,string words)
{
	tmp += arr[mrows][mcolums];
	if(tmp==words)
	{
		++cnts;
		return ;
	}
	//右方
	rightCore(arr,rows,colums,mrows,mcolums+1,tmp,words);
	//下方
	downCore(arr,rows,colums,mrows+1,mcolums,tmp,words);
	//右下
	rightDownCore(arr,rows,colums,mrows+1,mcolums+1,tmp,words);
}
#endif