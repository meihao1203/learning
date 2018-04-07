 ///
 /// @file    typeid.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-04-04 19:08:31
 ///
 
#include<iostream>
#include<typeinfo>
using namespace std;
class animal
{
	public:
		virtual void voice() = 0;
};
class cat:public animal
{
	public:
		void voice()
		{
			cout<<"cat::voice()"<<"喵喵"<<endl;
		}
};
class dog:public animal
{
	public:
		void voice()
		{
			cout<<"dog::voice()"<<"汪汪"<<endl;
		}
};
void play(animal* tmp)
{
	if(typeid(*tmp).name()==typeid(dog).name())
	{
		dog* pd = dynamic_cast<dog*> (tmp);
		pd->voice();
	}
	else if(typeid(*tmp).name()==typeid(cat).name())
	{
		cat* pc = dynamic_cast<cat*> (tmp);
		pc->voice();
	}
}
int main()
{
	animal* pa = new cat;
	cout<<typeid(double).name()<<endl;  // 只输出类型第一个字母
	cout<<typeid(5).name()<<endl;
	cout<<"typeid(pa).name()"<<typeid(pa).name()<<endl;  // 指针类型
	cout<<"typeid(*pa).name()"<<typeid(*pa).name()<<endl;  // 指针所存的值类型
	play(pa);
	dog d;
	play(&d);
	cout<<"typeid(d).name()"<<typeid(d).name()<<endl;
	cout<<"typeid(&d).name()"<<typeid(&d).name()<<endl;
	return 0;
}
//d
//i
//typeid(pa).name()P6animal
//typeid(*pa).name()3cat
//cat::voice()喵喵
//dog::voice()汪汪
//typeid(d).name()3dog
//typeid(&d).name()P3dog
