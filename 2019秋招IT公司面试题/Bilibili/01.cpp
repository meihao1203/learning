#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
static vector<string> ans;
void func(string& tmp,int N,int sum)
{
	if(sum>N)
		return;
	if(sum==N)
	{
		ans.push_back(tmp);
		return;
	}
	string obj2 = tmp+'2';
	func(obj2,N,sum*2+1);
	string obj3 = tmp+'3';
	func(obj3,N,sum*2+2);
}
int main()
{
	int N;
	cin>>N;
	string result = "";
	int sum = 0;
	func(result,N,sum);
	sort(ans.begin(),ans.end(),[](string a,string b){return a.size()<b.size();});
	cout<<ans[0]<<endl;
	//system("pause");
}