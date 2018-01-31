 ///
 /// @file    operator_new_delete.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-01-31 13:35:15
 ///
 
#include<iostream>
#include<string.h>
using namespace std;
class CSstudent
{
	public:
		static void* operator new(size_t nsize)  // nsize的值由操作系统自己确定
		{
			cout<<"operator new() size = "<<nsize<<endl;
			void *tmp = new char[nsize];   // char的单位刚好是1
			// new有两个版本，一个new(size_t)一个new[](size_t)
			return tmp;
		}
		static void operator delete(void* tmp)
		{
			cout<<"operator delete()"<<endl;
			delete []tmp;
		}
	public:
		int _id; // size = 4;
		char _name[3]; // size = 3;
};
//内存对齐 4 + 3 +1 = 8;
int main()
{
	CSstudent *s1 = new CSstudent;
	s1->_id = 110;
	strcpy(s1->_name,"hello,world");
	cout<<sizeof(*s1)<<endl;
	delete s1;
}
//operator new() size = 8
//8
//operator delete()
