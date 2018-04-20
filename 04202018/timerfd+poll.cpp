 ///
 /// @file    timerfd+poll.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-04-20 11:13:35
 ///
 
#include<iostream>
#include<time.h>
#include<poll.h>
#include<sys/timerfd.h>
#include<string.h>
#include<unistd.h>
using namespace std;
int main()
{
	int timerfd = timerfd_create(CLOCK_REALTIME,0);
	struct itimerspec new_value;
	memset(&new_value,0,sizeof(new_value));
	new_value.it_interval.tv_sec = 1;  //时间间隔
	new_value.it_value.tv_sec = 5;  //初始时间
	timerfd_settime(timerfd,0,&new_value,NULL);
	struct pollfd fd;
	bzero(&fd,sizeof(pollfd));
	fd.fd = timerfd;
	fd.events = POLLIN;
	time_t t;
	time(&t);
	cout<<ctime(&t)<<endl;
	while(1)
	{
		int ret = poll(&fd,1,-1);  // 永久等待时间发生
		if(ret>0)
		{
			time(&t);
			cout<<ctime(&t)<<endl;
			long long int tmp;
			read(timerfd,&tmp,sizeof(long long int));  // 读走数据，不然会一直触发
		}
		else
		{
			return -1;
		}
	}
}
//Fri Apr 20 11:29:48 2018
//
//Fri Apr 20 11:29:53 2018
//
//Fri Apr 20 11:29:54 2018
//
//Fri Apr 20 11:29:55 2018
//
//Fri Apr 20 11:29:56 2018
//
//^C
