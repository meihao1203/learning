 ///
 /// @file    test.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-04-16 16:37:28
 ///
 
#include<iostream>
#include"Buffer.h"
#include<time.h>
#include<unistd.h>
#include"Thread.h"
using namespace std;
struct Producer
{
	void produce(meihao::Buffer& buffer)
	{
		::srand(time(NULL));
		int i = 0;
		while(i<5)
		{
			int num = rand()%100;
			buffer.push(num);
			//cout<<"prodece a num "<<num<<endl;  // 放在这里可能导致不一致了
			sleep(1);
			i++;
		}
	}
};
struct Consumer
{
	void consumer(meihao::Buffer& buffer)
	{
		int i = 0;
		while(i<5)
		{
			int num = buffer.pop();
			//cout<<"consumer a num "<<num<<endl;
			sleep(2);
			i++;
		}
	}
};
int main()
{
	Producer p1;
	Consumer c1;
	meihao::Buffer buffer(5);
	meihao::Thread produceThread(bind(&Producer::produce,&p1,ref(buffer)));  
	//生产者线程
	meihao::Thread consumThread(bind(&Consumer::consumer,&c1,ref(buffer)));
	//消费者线程
	produceThread.start();
	consumThread.start();

	produceThread.join();
	consumThread.join();

	return 0;
}
