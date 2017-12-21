///
/// @file    newStudent1.cpp
/// @author  meihao1203(meihao19931203@outlook.com)
/// @date    2017-12-21 11:06:11
///

//使用new表达式时发生的三个步骤：
//1.调用名为operator new的标准库函数，分配足够大的原始的未类型化的内存，以保存指定类型的一个对象
//2.运行该类型的一个构造函数去初始化对象
//3.返回指向新分配并构造的构造函数对象的指针
//
//使用delete表达式时，发生的步骤：
//1.调用对象的析构函数
//2.调用名为operator delete的标准库函数释放该对象所用的内存

//void * operator new (size_t);
//void * operator new[](size_t);
//void operator delete(void *);
//void operator delete[](void *);
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
		~Student()
		{
			cout<<"~Student()"<<endl;
			delete []_name;
			_name = NULL;
		}
		void * operator new(size_t count)
		{
			cout<<"operator new()"<<endl;
			void *p = malloc(count);
			return p;
		}
		void operator delete(void *p)
		{
			cout<<"operator delete()"<<endl;
			free(p);
			p = NULL;
		}
		void print()const
		{
			cout<<"id:"<<_id<<endl;
			cout<<"name:"<<_name<<endl;
		}
};
int main(void)
{
	Student *stu1 = new Student(110,"meihao");  //new 创建Student类对象时才会调用Student类内部重写的new、delete表达式
	stu1->print();
	delete stu1;
	cout<<"stu1:"<<stu1<<endl;
	//char *name = new char('a');   //重写的new表达式的作用域只在Student类内，其他不变
	//cout<<*name<<endl;
	return 0;
}
//operator new()
//Student()
//id:110
//name:meihao
//~Student()
//operator delete()
//stu1:0x1d72030
