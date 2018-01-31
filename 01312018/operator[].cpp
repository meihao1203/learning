 ///
 /// @file    operator[].cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-01-31 13:02:23
 ///
 
#include<iostream>
#include<string.h>
using namespace std;
class CharArr
{
	public:
		CharArr(int size=0)
			:_size(size)
		{
			_arr = new char[size];
		}
		~CharArr()
		{
			delete _arr;
		}
		int size()
		{
			return _size;
		}
		char& operator[](int position)
		{
			static char _null = '\0';
			if(position>=0&position<_size)
			{
				return _arr[position];
			}
			else
			{
				cout<<"下标越界"<<endl;
				return _null;
			}
		}
	private:
		int _size;
		char* _arr;
};
int main()
{
	const char* tmp = "hello,world";
	CharArr ca(strlen(tmp)+1);
	for(int i=0;i!=ca.size();++i)
	{
		ca[i] = tmp[i];
	}
	cout<<tmp<<endl;
	for(int j=0;j!=ca.size();++j)
	{
		cout<<ca[j];
	}
	cout<<endl;
	return 0;
}
//hello,world
//hello,world
