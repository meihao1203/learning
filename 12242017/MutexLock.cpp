 ///
 /// @file    MutexLock.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2017-12-24 14:14:46
 ///
 
#include<iostream>
#include<pthread.h>
using namespace std;
class MutexLock
{
	private:
		pthread_mutex_t mutex;
		//pthread_cond_t cond;
	public:
		MutexLock()
		{
			cout<<"MutexLock()"<<endl;
			pthread_mutex_init(&mutex,NULL);
		}
		~MutexLock()
		{
			cout<<"~Mutexlock()"<<endl;
			pthread_mutex_destroy(&mutex);
		}
		void lock()
		{
			//cout<<"Lock()"<<endl;
			pthread_mutex_lock(&mutex);
		}
		void unlock()
		{
			//cout<<"unlock()"<<endl;
			pthread_mutex_unlock(&mutex);
		}
};
int num = 0;
void *func(void* p)
{
	MutexLock *mutp = (MutexLock*)p;
	for(int idx=0;idx!=5e8;idx++)
	{
		(*mutp).lock();
		num++;
		(*mutp).unlock();
	}
	pthread_exit(NULL);
}
int main(void)
{
	MutexLock mut;
	pthread_t pth;
	pthread_create(&pth,NULL,func,(void*)&mut);
	for(int idx=0;idx!=5e8;idx++)
	{
		mut.lock();
		num++;
		mut.unlock();
	}
	pthread_join(pth,NULL);
	cout<<"num="<<num<<endl;
}
//没有加锁的情况，数据大了就没有一次正确
//MutexLock()
//num=997991482
//
//加锁的情况
//MutexLock()
//num=1000000000
//~Mutexlock()
//~Mutexlock()
