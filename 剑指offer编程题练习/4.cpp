#include<iostream>
using namespace std;
//替换字符串中的空格为%20
void replaceBlank(char *str,int length)
{
	if(NULL==str||length<=0)
		return ;
	int oldStrLen = 0;
	int newStrLen = 0;
	int blankCnts = 0;
	char* tmp = str;
	while('\0'!=*tmp)
	{
		++oldStrLen;
		if(' '==*tmp)
			++blankCnts;
		++tmp;
	}
	newStrLen = oldStrLen + blankCnts*2;
	if(newStrLen>length)
		return ;
	int idxNewStr = newStrLen;
	int idxOldStr = oldStrLen;
	while(idxOldStr>=0&&idxNewStr>idxOldStr)
	{
		if(' '==str[idxOldStr])
		{
			--idxOldStr;
			idxNewStr -= 3;
			str[idxNewStr+1] = '%';
			str[idxNewStr+2] = '2';
			str[idxNewStr+3] = '0';		
		}
		else
		{
			str[idxNewStr] = str[idxOldStr];
			--idxNewStr;
			--idxOldStr;
		}

	}
}
//int main()
//{
//	char str[100] = "We  are happy.";
//	cout<<"origin str="<<str<<endl;
//	replaceBlank(str,100);
//	cout<<"final str="<<str<<endl;
//	system("pause");
//}
