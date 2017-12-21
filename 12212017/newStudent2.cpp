///
/// @file    newStudent2.cpp
/// @author  meihao1203(meihao19931203@outlook.com)
/// @date    2017-12-21 11:06:11
///

//只生产栈对象，不生成堆对象
//1.将构造函数放入private区域;  new生成堆对象的第二步就是要调用构造函数，设置为私有，new就不能成功
//2.operator new函数 放入到private区域

#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;
class Student
{
	private:
		int _id;
		char *_name;
		//void * operator new(size_t count);
		//void operator delete(void *p);
		void * operator new(size_t count){}  //只是为了不生成堆对象，没必要重写
		void operator delete(void *p){}
	public:
		Student(int id,const char *name):_id(id)
		{
			cout<<"Student()"<<endl;
			_name = new char[strlen(name)+1];
			strcpy(_name,name);
		}
		~Student()
		{
			cout<<"~Student()"<<endl;
			delete []_name;
			_name = NULL;
		}
		void print()const
		{
			cout<<"id:"<<_id<<endl;
			cout<<"name:"<<_name<<endl;
		}
};
int main(void)
{
	//Student *stu = new Student(110,"meihao");  //new 创建Student类对象时才会调用Student类内部重写的new、delete表达式
	Student stu1(110,"meihao");
	stu1.print();
	return 0;
}
//Student()
//id:110
//name:meihao
//~Student()
