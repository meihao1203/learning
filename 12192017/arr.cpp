 ///
 /// @file    arr[]*.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2017-12-19 18:45:32
 ///
 
#include<iostream>
using namespace std;
class PAT
{
	private:
		int _ix;
	public:
		PAT()
		{
			cout<<"PAT"<<endl;
		}
};
int main()
{
	PAT (*ad)[3];   //数组指针
	PAT ad1[3];
	ad = &ad1;
}
