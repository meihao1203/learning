//给定一个字符串s，你可以从中删除一些字符，使得剩下的串是一个回文串。如何删除才能使得回文串最长呢？
//输出需要删除的字符个数。
//
//输入描述:
//
//输入数据有多组，每组包含一个字符串s，且保证:1<=s.length<=1000.
//  
//输出描述:
//
//对于每组数据，输出一个整数，代表最少需要删除的字符个数。
//
//输入例子1:
//
//abcda
//google
//
//输出例子1:
//
//2
//2
#if 0
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int max(int& a,int& b,int&c )
{
	return a>b?(a>c?a:c):(b>c?b:c);
}
int main(int argc,char** argv)
{
	string data;
	vector<int> answer;
	while(cin>>data)
	{
		int dataLen = data.size();
		//定义二维数组
		int** arr = new int*[dataLen+1];
		for(int idx=0;idx<=dataLen;++idx)
		{
			arr[idx] = new int[dataLen+1];
		}
		//旋转
		string dataReverse(data);
		for(int idx=0;idx!=dataLen;++idx)
		{
			dataReverse[idx] = data[dataLen-1-idx];
		}
		for(int idx=0;idx<=dataLen;++idx)
		{
			arr[0][idx] = 0;
		}
		for(int idx=0;idx<=dataLen;++idx)
		{
			arr[idx][0] = 0;
		}
		for(int idx=1;idx<=dataLen;++idx)
		{
			for(int iidx=1;iidx<=dataLen;++iidx)
			{
				if(data[idx-1]==dataReverse[iidx-1])
					arr[idx][iidx] = arr[idx-1][iidx-1] + 1;
				else 
					arr[idx][iidx] = max(arr[idx][iidx-1],arr[idx-1][iidx],arr[idx-1][iidx-1]);
			}
		}
		answer.push_back(dataLen-arr[dataLen][dataLen]);
		//释放
		for(int idx=0;idx<=dataLen;++idx)
		{
			delete []arr[idx];
			arr[idx] = NULL;
		}
		delete []arr;
		arr = NULL;
	}
	for(auto&elem:answer)
		cout<<elem<<endl;
	//system("pause");
}
#endif