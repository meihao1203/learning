 ///
 /// @file    test.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-04-15 16:06:47
 ///
 
#include<iostream>
#include"Thread.h"
#include<time.h>
#include<unistd.h>
using namespace std;
void print()
{
	srand(time(NULL));
	int i = 0;
	while(i<5)
	//while(1)
	{
		int num = rand()%100;
		cout<<"produce num is "<<num<<endl;
		sleep(1);
		i++;
	}
}
struct pprint
{
	void print()
	{
		::print();  // 匿名空间，访问的就是全局的print()
	}
};
int main()
{
	meihao::Thread thread(bind(&pprint::print,pprint()));
	thread.start();
	thread.join();  // 主线程等待回收子线程
	return 0;
}
//Noncopyable()
//Thread(ThreadCallback)
//join()
//produce num is 90
//produce num is 58
//produce num is 72
//produce num is 44
//produce num is 88
//~Thread()
//~Noncopyable()
