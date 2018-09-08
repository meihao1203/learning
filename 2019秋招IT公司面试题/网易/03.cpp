#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<iterator>
#include<sstream>
#if 1
using namespace std;
string preProcessTimeStr(string timeStr);
int seconds(string);
int main()
{
	int demo;
	cin>>demo;
	map<int,set<string> > data;
	while(demo)
	{
		int cnt;
		cin>>cnt;	
		while(cnt)
		{
			int weekday;
			cin>>weekday;
			int cntTime;
			cin>>cntTime;
			set<string> tmpset;
			while(cntTime)
			{
				string timeStr;
				cin>>timeStr;
				string time = preProcessTimeStr(timeStr);
				tmpset.insert(time);
				--cntTime;
			}
			data.insert(::make_pair(weekday,tmpset));
			--cnt;
		}
		//测试数据	
		/*for(auto& elem:data)
		{
			cout<<elem.first<<" ";
			for(auto& elem2:elem.second)
			{
				cout<<elem2<<" ";
			}
			cout<<endl;
		}*/
		int MAXTIMESECONDS = 24*60*60;
		int cntTest;
		cin>>cntTest;
		int tmpCntTest = cntTest;
		int* arr = new int[cntTest]();
		while(cntTest)
		{
			int weekday;
			string timePeriod;
			cin>>weekday>>timePeriod;
			auto it = data.find(weekday);
			if(it!=data.end())
			{//对应星期有开放时间段
				int timeSeconds = seconds(timePeriod);
				for(int idx=0;idx!=(it->second).size();++idx)
				{
					int time1,time2;
					auto it2 = (it->second).begin();
					istringstream iss(*it2);
					iss>>time1>>time2;
					if(timeSeconds<time1)
					{
						arr[cntTest-1] = time1 - timeSeconds;
						break;
					}
					else if(time1<=timeSeconds<=time2)
					{
						arr[cntTest-1] = 0;
						break;
					}
					else if(timeSeconds>time2 && (idx+1)==(it->second).size())
					{
						++it;
						if(it==data.end())
							it = data.begin();
						istringstream iss2(*((it->second).begin()));
						int nextTime;
						iss2>>nextTime;
						arr[cntTest-1] = MAXTIMESECONDS - timeSeconds + nextTime;
					}
				}
			}
			else 
			{//对应的星期没有开放时间段
				for(int idx=(weekday+1),iidx=0;iidx!=7;++iidx,++idx)
				{
					if(idx==8)
						idx = 1;
					it = data.find(idx);
					if(it!=data.end())
						break;
				}
				int days = it->first - weekday;
				int timeSeconds = seconds(timePeriod);
				int time2;
				istringstream iss(*(it->second).begin());
				iss>>time2;
				arr[cntTest-1] = (days - 1)* MAXTIMESECONDS + time2 +  MAXTIMESECONDS - timeSeconds;
			}
			--cntTest;
		}
		for(int idx=tmpCntTest-1;idx>=0;--idx)
			cout<<arr[idx]<<endl;
		delete []arr;
		arr = NULL;
		--demo;
	}

	system("pause");
}
string preProcessTimeStr(string timeStr)
{
	if(timeStr=="")
		return 0;
	int len = strlen(timeStr.c_str());
	for(int idx=0;idx!=len;++idx)
	{
		if(timeStr[idx]=='-'||timeStr[idx]==':')
			timeStr[idx] = ' ';
	}
	istringstream iss(timeStr);
	int hour,minute,second;
	int firstSeconds,senondSeconds;
	iss>>hour>>minute>>second;
	firstSeconds = hour * 60 * 60 + minute * 60 + second;
	iss>>hour>>minute>>second;
	senondSeconds = hour * 60 * 60 + minute * 60 + second;
	ostringstream oss;
	oss<<firstSeconds<<" "<<senondSeconds;
	return oss.str();
}
int seconds(string str)
{
	char* p = const_cast<char*>(str.c_str());
	while(*p!='\0')
	{
		if(*p==':')
			*p = ' ';
		++p;
	}
	istringstream iss(str);
	int hour,minute,second;
	iss>>hour>>minute>>second;
	return hour*60*60+minute*60+second;
}
#endif
//1
//4
//3 1 10:00:00-15:00:00
//1 2 08:00:00-14:00:00 18:00:00-20:00:00
//6 3 09:00:00-11:00:00 13:00:00-14:00:00 17:00:00-22:00:00
//7 3 09:00:00-10:30:00 13:30:00-14:00:00 17:30:00-22:00:00
//5
//2 19:03:30
//3 14:02:23
//1 02:00:00
//5 17:00:00
//4 13:13:13
//53790
//0
//21600
//57600
//157607
//请按任意键继续. . .