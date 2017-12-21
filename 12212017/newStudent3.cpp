///
/// @file    newStudent1.cpp
/// @author  meihao1203(meihao19931203@outlook.com)
/// @date    2017-12-21 11:06:11
///

//只创建堆对象
//将析构函数放到private区域
#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;
class Student
{
	private:
		int _id;
		char *_name;
	public:
		Student(int id,const char *name):_id(id)
		{
			cout<<"Student()"<<endl;
			_name = new char[strlen(name)+1];
			strcpy(_name,name);
		}
	private:
		~Student()
		{
			cout<<"~Student()"<<endl;
			delete []_name;
			_name = NULL;
		}
	public:
		void destory()
		{
			cout<<"destory()"<<endl;
			delete this;  //只能创建堆对象，对象调用会传递this指针
			//this->~Student();  //这个也可以
		}
		void print()const
		{
			cout<<"id:"<<_id<<endl;
			cout<<"name:"<<_name<<endl;
		}
};
int main(void)
{
	Student *stu1 = new Student(110,"meihao");
	stu1->print();
	//delete stu1;   //不能调析构函数，无法释放
	stu1->destory();
	
	//Student stu1(110,"meihao");   //析构函数是私有，不能创建
	return 0;
}
//Student()
//id:110
//name:meihao
//destory()
//~Student()
