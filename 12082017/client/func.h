#ifndef __FUNC_H__
#define __FUNC_H__
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
#include<dirent.h>


typedef struct 
{
	int len;
	char buf[128];
}data,*pdata;

typedef struct
{
	 int cmd_len;
	 char cmd_buf[MAXSIZE];
}cmd,*pcmd;

void sendfile(int sfd);
void recv_n(int sfd,char *buf,int len);
void send_n(int sfd,char *buf,int len);

void deal_cmd(char *cmd);
int is_file_exist(char *filename);
int upload_file(int sfd,char *file_name);
#endif
