 ///
 /// @file    timerfd.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-04-20 10:43:28
 ///
 
#include<iostream>
#include<sys/timerfd.h>
#include<unistd.h>
#include<stdio.h>
#include<string.h>
#include<time.h>
using namespace std;
int main()
{
	int timerfd = timerfd_create(CLOCK_REALTIME,0);
	if(-1==timerfd)
	{
		perror("timerfd_create");
		return -1;
	}
	struct itimerspec new_value;
	memset(&new_value,0,sizeof(itimerspec));
	new_value.it_value.tv_sec = 5; //初始到期时间
	new_value.it_interval.tv_sec = 3;  //间隔时间
	int ret = timerfd_settime(timerfd,0,&new_value,NULL);
	if(-1==ret)
	{
		perror("timerfd_settimer");
		return -1;
	}
	long int timeNum;
	time_t t;
	time(&t);  // 获取当前秒数
	// 读到的是个8为的整数
	cout<<ctime(&t)<<endl;
	while(ret = read(timerfd,&timeNum,8),time(&t),cout<<ctime(&t))  // 时间到，timerfd可读，要把数据读走，不然阻塞,否则定时器没法正常工作了
	{
		cout<<"timerfd read cnt "<<timeNum<<endl<<endl;
	}
}
//Fri Apr 20 11:12:22 2018
//
//Fri Apr 20 11:12:27 2018
//timerfd read cnt 1
//
//Fri Apr 20 11:12:30 2018
//timerfd read cnt 1
//
//Fri Apr 20 11:12:33 2018
//timerfd read cnt 1
//
//Fri Apr 20 11:12:36 2018
//timerfd read cnt 1
//
//Fri Apr 20 11:12:39 2018
//timerfd read cnt 1
//
//Fri Apr 20 11:12:42 2018
//timerfd read cnt 1
//
//^C
