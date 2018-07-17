///
/// @file    newStudent.cpp
/// @author  meihao1203(meihao19931203@outlook.com)
/// @date    2018-07-17 20:06:11
///

//1。显式调用的时候，析构函数相当于的一个普通的成员函数
//
//2。编译器隐式调用析构函数，如分配了对内存，显式调用析构的话引起重复释放堆内存的异常
//
//3。把一个对象看作占用了部分栈内存，占用了部分堆内存（如果申请了的话），这样便于理解这个问题
//	 系统隐式调用析构函数的时候，会加入释放栈内存的动作（而堆内存则由用户手工的释放）
//	 用户显式调用析构函数的时候，只是单纯执行析构函数内的语句，不会释放栈内存，摧毁对象
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
	//private:
		~Student()
		{
			cout<<"~Student(),this="<<this<<endl;
			delete []_name;
			_name = NULL;
		}
	public:
		void destory()
		{
			cout<<"destory()"<<endl;
			//delete this;  //只能创建堆对象，对象调用会传递this指针
			this->~Student();  //这个也可以
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
	delete stu1;  //显示调用只能释放堆空间
	//stu1对象的栈空间没有释放
	cout<<"-------------"<<endl;

	Student stu2(111,"mei"); 
	//stu2.destory();
	cout<<"-------------"<<endl;

	return 0;
}
/* 加了stu2.destroy() */
//Student()
//~Student(),this=0x6b3c20
//-------------
//Student()
//destory()
//~Student(),this=0x7ffd50775f80
//-------------
//~Student(),this=0x7ffd50775f80


/* 不加stu2.destroy() */
//Student()
//~Student(),this=0x9fdc20
//-------------
//Student()
//-------------
//~Student(),this=0x7ffc4045b2e0
