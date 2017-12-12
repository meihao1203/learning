#ifndef __FUNC_H__
#define __FUNC_H__
#define FILENAME "meihao.mp4"
#include<stdio.h>
#include<string.h>
#include<strings.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<sys/stat.h>
#include<sys/epoll.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<fcntl.h>
#include<unistd.h>


typedef struct
{
        int pid;
        int fds;
        int status;
}child,*pchild;

typedef struct
{
        int len;  //buf里面存放的数据长度
        char buf[128];
}data,*pdada;


void send_fd(int fds,int fd);
void read_fd(int fds,int *fd);
void child_handle(int fds);
void make_child(pchild p,int num);
void sendfile(int new_fd);
void recv_n(int new_fd,char *buf,int len);
void send_n(int new_fd,char *buf,int len);
#endif