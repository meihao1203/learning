#if 0 
#include<iostream>
#include<string>
#include<string.h>
using namespace std;
int main()
{
	string str;
	cin>>str;
	int strLen = str.size();
	int hash[256] ;
	memset(hash, -1, 256 * sizeof(int));
	int pre = -1, maxLen = 0;
	for (int idx = 0; idx < strLen; ++idx)
	{
		pre = pre>hash[str[idx]]?pre:hash[str[idx]];
		maxLen = maxLen>(idx-pre)?maxLen:(idx-pre);
		hash[str[idx]] = idx;
	}
	cout<<maxLen<<endl;
	//system("pause");
}
#endif