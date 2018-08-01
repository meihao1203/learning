#include<iostream>
using namespace std;
#if 0
void makeNextArr(const char* tStr,int* next);
//KMP算法中，next数组中next[i]的值的含义就是:匹配串中0~i中的最大前后缀长度
//学习博客：https://blog.csdn.net/ebowtang/article/details/49129363
void KMP(const char* sStr,const char* tStr);
void testNext(const char* tStr,int* next,int nextLen);
void test();
int main()
{
	test();

	char* sStr = "abcabcabc";
	char* tStr = "abcab";
	cout<<"主串："<<sStr<<endl;
	cout<<"匹配串："<<tStr<<endl;
	KMP(sStr,tStr);
	cout<<endl;

	char* sStr2 = "abcdefabcdef";
	char* tStr2 = "abcab";
	cout<<"主串："<<sStr2<<endl;
	cout<<"匹配串："<<tStr2<<endl;
	KMP(sStr2,tStr2);

	system("pause");
}
void test()
{
	cout<<"---start test makeNextArr---"<<endl;
	char* tStr = "abcdex";
	int next[6];
	testNext(tStr,next,6);
	cout<<endl;

	char* tStr2 = "abcabx";
	int next2[6];
	testNext(tStr2,next2,6);
	cout<<endl;

	char* tStr3 = "aaaaa";
	int next3[6];
	testNext(tStr3,next3,5);
	cout<<endl;

	char* tStr4 = "abcab";
	int next4[5];
	testNext(tStr4,next4,5);
	cout<<endl;

	char* tStr5 = "abaabb";
	int next5[6];
	testNext(tStr5,next5,6);
	cout<<endl;
	cout<<"---end test makeNextArr---"<<endl;
	cout<<endl;
}
void testNext(const char* tStr,int* next,int nextLen)
{
	cout<<tStr<<endl;
	makeNextArr(tStr,next);
	for(int idx=0;idx<nextLen;++idx)
		cout<<"next["<<idx<<"] = "<<next[idx]<<"   ";
	cout<<endl;
}
void makeNextArr(const char* tStr,int* next)
{
	if(NULL==tStr||NULL==next)
		return ;
	int k = 0;  //模式匹配最初k值设置为0
	//k值表示如果匹配串和主串的第0个字符匹配失败，那么下一次还是用匹配串的第0个字符和主串的下一个字符开始匹配
	next[0] = 0;  //eg:S表示主串，T表示匹配串，S[i] != T[0],那么下次匹配 (S[i+1],T[0])
	for(int idx = 1;idx<strlen(tStr);++idx)  //循环计算其他next值
	{
		while(tStr[idx]!=tStr[k] &&
			k>0)  //计算下一个next的值，如果相等，累加k，不等就判断k值是否大于0，大于0就试着计算S[0]~S[k-1]中的最大前后缀
		{
			k = next[k-1];   //第0个字符，next[0] = 0;第k-1个字符，最大前后缀就是next[k-1]。
		}
		if(tStr[idx]==tStr[k])
			++k;
		next[idx] = k;
	}
}
void KMP(const char* sStr,const char* tStr)
{
	if(NULL==sStr||NULL==tStr)
		return ;
	int sStrLen = strlen(sStr);
	int tStrLen = strlen(tStr);
	int* next = new int[tStrLen]();
	makeNextArr(tStr,next);
	for(int idx=0,iidx=0;idx<sStrLen;++idx)
	{
		while(iidx>0&&
			sStr[idx]!=tStr[iidx])
		{
			iidx = next[iidx-1];   //匹配串中第iidx个和主串第idx个不行等，减小回溯，比较匹配串中第next[iidx-1]个。
		}
		if(sStr[idx]==tStr[iidx])
		{
			++iidx;  //iidx加到和匹配字符串长度相等的时候就表示找到一个子串
		}
		if(iidx==tStrLen)
		{
			cout<<"find sub str,pos is:"<<idx-(iidx-1)<<endl;
			//有可能主串中有多个子串，利用next数组，减少回溯，查找下一个。
			iidx = next[iidx-1];
		}
	}
}
#endif
//---start test makeNextArr---
//abcdex
//next[0] = 0   next[1] = 0   next[2] = 0   next[3] = 0   next[4] = 0   next[5] = 0
//
//abcabx
//next[0] = 0   next[1] = 0   next[2] = 0   next[3] = 1   next[4] = 2   next[5] = 0
//
//aaaaa
//next[0] = 0   next[1] = 1   next[2] = 2   next[3] = 3   next[4] = 4
//
//abcab
//next[0] = 0   next[1] = 0   next[2] = 0   next[3] = 1   next[4] = 2
//
//abaabb
//next[0] = 0   next[1] = 0   next[2] = 1   next[3] = 1   next[4] = 2   next[5] = 0
//
//---end test makeNextArr---
//
//主串：abcabcabc
//匹配串：abcab
//find sub str,pos is:0
//find sub str,pos is:3
//
//主串：abcdefabcdef
//匹配串：abcab