#include<iostream>
#include<string>
using namespace std;
int main()
{
	int N;
	cin>>N;
	string result = "1";
	for(int idx=0;idx<N;++idx)
	{
		int tmp = 0,carry = 0;
		for(int jdx=result.size()-1;jdx>=0;--jdx)
		{
			tmp = result[jdx] - '0';
			tmp  = (tmp<<1) + carry;
			carry = tmp/10;
			result[jdx] = tmp%10 + '0';
		}
		if(carry>0)  //最终结果还要加上进位
		{
			char ch = carry + '0';
			result.insert(0,1,ch);
		}
	}
	cout<<result<<endl;
	system("pause");
}