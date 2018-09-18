#include<iostream>
#include<vector>
#include<sstream>
#include<algorithm>
using namespace std;
typedef struct NODE
{
	int taskId;
	int times;
	int weight;
	int ratio;
}node;
void func(string& line)
{
	int len = line.size();
	for(int idx=0;idx<len;++idx)
		if(line[idx]==',')
			line[idx] = ' ';
}
int main()
{
	int times;
	int taskId =1;
	vector<node> data;
	string line1;
	getline(cin,line1);
	istringstream iss(line1);
	while(iss>>times)
	{
		node tmp;
		tmp.taskId = taskId;
		tmp.times = times;
		data.push_back(tmp);
		++taskId;
	}
	int weight;
	int idx = 0;
	string line2;
	getline(cin,line2);
	istringstream iss2(line2);
	while(iss2>>weight)
	{
		data[idx].weight = weight;
		data[idx].ratio = weight/data[idx].times;
		++idx;
	}
	sort(data.begin(),data.end(),[](node a,node b){return a.weight>b.weight;});
	sort(data.begin(),data.end(),[](node a,node b){return a.ratio>b.ratio;});
	vector<int> result;
	int hours = 0;
	for(int idx=0;idx<data.size();++idx)
	{
		++hours;
		if(data[idx].times>=hours)
			result.push_back(data[idx].taskId);
		else
			--hours;
	}
	for(int idx=0;idx<result.size()-1;++idx)
		cout<<result[idx]<<",";
	cout<<result[result.size()-1]<<endl;
	system("pause");
}
//2,1,4,3,7