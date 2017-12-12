#ifndef __FUNC_H__
#define __FUNC_H__
#define FILENAME "meihao.mp4"
#define MAXSIZE 1024
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
#include<time.h>
#include<pwd.h>
#include<grp.h>
#include<dirent.h>


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

typedef struct
{
	 int cmd_len;
	 char cmd_buf[MAXSIZE];
}cmd,*pcmd;

void send_fd(int fds,int fd);
void read_fd(int fds,int *fd);
void child_work(int fds);
void child_handle(int new_fd);
void make_child(pchild p,int num);
void sendfile(int new_fd);
void recv_n(int new_fd,char *buf,int len);
void send_n(int new_fd,char *buf,int len);

void get_arg(char *line,char *arg);
void file_read_arg(char *buf,char *ip,char *port);

void child_handle(int new_fd);
void do_cd(int new_fd,pcmd pc);
void do_ls(int new_fd,pcmd pc);
void change_time_type(char *t);
void change_st_mode(char *perm,struct stat buf);
void file_stat(char *res,char *filename);

#endif
