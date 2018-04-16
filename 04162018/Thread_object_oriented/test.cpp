 ///
 /// @file    test.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-04-16 10:29:41
 ///
 
#include<iostream>
#include<time.h>
#include<unistd.h>
#include"Thread.h"
using namespace std;
class Derived:public meihao::Thread
{
	public:
		void run();
};
void Derived::run()
{
	srand(time(NULL));
	int i=0;
	while(i<5)
	{
		int num = rand()%100;
		cout<<"thread produce num "<<num<<endl;
		i++;
	}
}
int main()
{
	meihao::Thread* pthread = new Derived;
	pthread->start();
	pthread->join();
	delete pthread;
	return 0;
}
//Thread()
//thread produce num 50
//thread produce num 11
//thread produce num 10
//thread produce num 18
//thread produce num 57
//~Thread()
