#if 1
#include<iostream>
#include<vector>
#include<string>
#include<set>
using namespace std;
vector<string> passwordList(string userName,string motherName,int pwdLen);
//len[1,10^5],  pwd[1,26]
//userName = RadheGupta
//motherName = RADHIKA
//pwdLen = 3  {r,a,d,h}=={a,d,h,r}
//{adh,adr,ahr,dhr}
int main()
{
	string userName = "RadheGupta";
	string motherName = "RADHIKA";
	int pwdLen = 3;
	vector<string>ans = passwordList(userName,motherName,pwdLen);
	for(auto&elem:ans)
		cout<<elem<<" ";
	cout<<endl;
	system("pause");
}
void func(vector<string>& ans,int pwdLen,string samechar,string& tmp);
vector<string> passwordList(string userName,string motherName,int pwdLen)
{
	if( userName.size()>100000||userName.size()<1||motherName.size()>100000||motherName.size()<1||pwdLen<1||pwdLen>26 )	
		return vector<string>();
	set<char> user;
	//userName
	for(int idx=0;idx!=userName.size();++idx)
	{
		if( (userName[idx]>='a'&&userName[idx]<='z') || 
			(userName[idx]>='A'&&userName[idx]<='Z') )
		{
			if(userName[idx]>='A'&&userName[idx]<='Z')
			{
				char tmp = userName[idx] + 32;
				user.insert(tmp);
			}
			else
			{
				user.insert(userName[idx]);
			}
		}
		else 
		{
			return vector<string>();
		}
	}
	//mother
	set<char> sameChar;
	for(int idx=0;idx!=motherName.size();++idx)
	{
		if( (motherName[idx]>='a'&&motherName[idx]<='z') || 
			(motherName[idx]>='A'&&motherName[idx]<='Z') )
		{
			if(motherName[idx]>='A'&&motherName[idx]<='Z')
			{
				char tmp = motherName[idx] + 32;
				if(user.find(tmp)!=user.end())
				{
					sameChar.insert(tmp);
				}
			}
			else
			{
				if(user.find(motherName[idx])!=user.end())
				{
					sameChar.insert(motherName[idx]);
				}
			}
		}
	}
	//sameChar就是最终结果了
	if(pwdLen>sameChar.size())
		return vector<string>();
	vector<string> ans;
	vector<char> sortChar;
	string samechar ;
	for(auto elem:sameChar)
	{
		sortChar.push_back(elem);
	}
	for(int idx=0;idx!=sortChar.size();++idx)
	{
		samechar+=(sortChar[idx]);
	}
	//排序结果
	string tmp = "";
	func(ans,pwdLen,samechar,tmp);
	return ans;
}
void func(vector<string>& ans,int pwdLen,string samechar,string& tmp)
{
	if(tmp.size()==pwdLen)
	{
		ans.push_back(tmp);
		return ;
	}
	string ttmp = tmp;
	for(int idx=0;idx!=samechar.size();++idx)
	{
		string ttmp = tmp;
		ttmp += samechar[idx];
		func(ans,pwdLen,samechar.substr(idx+1),ttmp);
	}
}
#endif