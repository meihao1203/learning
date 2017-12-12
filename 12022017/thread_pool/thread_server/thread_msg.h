#ifndef __THREAD_MSG_H__
#define __THREAD_MSG_H__
#include"func.h"
#define FILENAME "meihao.mp4"

typedef struct Node 
{
	int new_fd;
	struct Node *next;
}node,*pnode;   //客户端链接产的的new_fd,保存起来，待会放到队列

typedef struct 
{
	pnode head;
	pnode tail;
	pthread_mutex_t mutex;  //操作队列要保证同步，所以互斥锁放到这个结构体里面
	int size;
}que,*pque;  //队列链表，用来保存链接产生的new_fd 

typedef void *(*thread_handle)(void *);
typedef struct
{
	pthread_t *thread;
	int num;
	int capacity;
	que que_t;
	thread_handle func; 
	pthread_cond_t cond;
	int flag;   //这个结构体里面存放服务端启动所需要的所有信息，启动服务端初始化一次就好了，所以设置一个flag防止多次启动初始化；
}factory,*pfactory;  //这个结构体让程序可以不用分开定义多个变量，还有子线程只要传入结构体指针就可以访问main所有信息，不用把这些信息全部设置为全局变量

typedef struct
{
	int len;
	char buf[1024];
}data,*pdata;

void factory_init(pfactory f,int num,int capacity,thread_handle thread_func);
void factory_start(pfactory f);
void que_init(pque que_t);
void que_insert(pque que_t,int new_fd);
void que_get(pfactory f,int *new_fd);

void *thread_func(void *p);

void send_n(int new_fd,char *buf,int len);
void recv_n(int new_fd,char *buf,int len);

void sendfile(int new_fd);


#endif