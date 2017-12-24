 ///
 /// @file    worldStatistic.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2017-12-24 10:45:48
 ///
 
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<stdio.h>
#include<iomanip>
using namespace std;
class wordStatistic
{
	private:
		vector<string> vers;
		vector<int> veri;
	public:
		void readFile(string);
		void writeFile();
};
void wordStatistic::readFile(string file_name)
{
		ifstream ifs(file_name.c_str());
		if(!ifs.good())
		{
			perror("ifstream");
			return ;
		}
		string tmpword;
		int tmpwordsize;
		int idx;
		cout<<"正在统计文件……"<<endl;
		while(!ifs.eof())
		{
			ifs>>tmpword;
			if(tmpword[0]>='0'&&tmpword[0]<='9')
			{
				continue;
			}
			tmpwordsize = vers.size();
			for(idx=0;idx<tmpwordsize;++idx)
			{
				//if(vers[idx].compare(tmpword)==0)   //==也可以比较
				if(vers[idx]==tmpword) 
				{
					veri[idx]++;
					break;
				}
			}
			if(idx==tmpwordsize)
			{
				vers.push_back(tmpword);
				veri.push_back(1);
			}
		}
		cout<<"文件统计完毕!"<<endl;
}
void wordStatistic::writeFile()
{
	ofstream ofs("answer.bat");
	if(!ofs.good())
	{
		perror("ofstream");
		return ;
	}
	cout<<"正在写入统计结果……"<<endl;
	for(int idx=0;idx<vers.size();++idx)
	{
		ofs<<setw(20)<<vers[idx]<<setw(20)<<veri[idx]<<endl;
	}
	cout<<"写入统计结果完毕！"<<endl;
}
int main()
{
	wordStatistic WS;
	WS.readFile("The_Holy_Bible.txt");
	WS.writeFile();
	return 0;
}
