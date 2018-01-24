///
/// @file    test.cpp
/// @author  meihao1203(meihao19931203@outlook.com)
/// @date    2018-01-24 10:31:36
///

#include<iostream>
#include<unistd.h>
#include"MutexLock.h"
#include"Condtion.h"
static int ret = 0;
static MutexLock mutex ;
static Condtion cond ;
using namespace std;
void *func(void *args)
{
	while(1)
	{
		mutex.lock();
		if(0==ret)
		{
			cond.wait(mutex);
		}
		if(ret>0)
		{
			cout<<"consume: "<<ret--<<endl;
		}
		if(0==ret)
		{
			mutex.unlock();
			cout<<"exit"<<endl;
			pthread_exit(NULL);
		}
		mutex.unlock();
	}
}
int main()
{
	pthread_t pid;
	pthread_t pid2;
	pthread_create(&pid,NULL,func,NULL);
	pthread_create(&pid2,NULL,func,NULL);
	sleep(1);	//让所有消费者线程全部挂在队列等待
	for(int i=0;i!=10;++i)
	{
		mutex.lock();
		ret++;
		cout<<"product: "<<ret<<endl;
		//cond.notify();   //测试notify只要一个线程就好了
		mutex.unlock();
	}
	cout<<"ret= "<<ret<<endl;
	cond.notifyall();
	pthread_join(pid,NULL);
	pthread_join(pid2,NULL);
	//对象生存期结束自动销毁，不用destroy锁和变量了
	return 0;
}
//MutexLock()
//Condtion()
//product: 1
//product: 2
//product: 3
//product: 4
//product: 5
//product: 6
//product: 7
//product: 8
//product: 9
//product: 10
//ret= 10
//consume: 10
//consume: 9
//consume: 8
//consume: 7
//consume: 6
//consume: 5
//consume: 4
//consume: 3
//consume: 2
//consume: 1
//exit
//exit
//~Condtion()
//~MutexLock()
