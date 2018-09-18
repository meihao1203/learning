#if 0
#include<iostream>
#include<string>
#include<string.h>
#include<set>
using namespace std;
set<string> result;
bool isTrue(string str)
{
	int len = str.size();
	for(int idx=0;idx<len-1;++idx)
	{
		if(str[idx]==str[idx+1])
			return false;
	}
	return true;
}
bool isAccess(char* str,char* end)
{
	char* p = str;
	char* q = end;
	while(p<q)
	{
		if(*p==*(p+1))
			return false;
		++p;
	}
	return true;
}
void permutationStr(char* str,char *beginStr)
{
	if(NULL==str)
		return ;
	if(*beginStr=='\0')
	{
		if(isTrue(str))
			result.insert(str);
	}
	for(char* ch = beginStr;*ch!='\0';++ch)
	{
		char tmp = *ch;
		*ch = *beginStr;
		*beginStr = tmp;
		/*if(isAccess(str,beginStr+1))*/
			permutationStr(str,beginStr+1);
		*beginStr = *ch;  
		*ch = tmp;
	}
}
int main()
{
	int A,B,C;
	cin>>A>>B>>C;
	string str;
	for(int idx=0;idx<A;++idx)
		str += 'a';
	for(int idx=0;idx<B;++idx)
		str += 'b';
	for(int idx=0;idx<C;++idx)
		str += 'c';
	//int len = str.size();
	//char* arr = new char[len+1];
	//strcpy(arr,str.c_str());
	char* arr = const_cast<char*>(str.c_str());
	permutationStr(arr,arr);
	cout<<result.size()<<endl;
	//delete []arr;
	//arr = NULL;
	//system("pause");
}
#endif