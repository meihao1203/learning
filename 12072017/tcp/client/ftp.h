#ifndef __FTP_H__
#define __FTP_H__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <fcntl.h>
#include <sys/time.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <signal.h>
#define BUF_SIZE 8*1024
#define ERR_EXIT(msg) do { \
						perror(msg);\
						exit(1);\
						}while(0)
typedef struct tag_session
{
	int  sess_sfd ;
	char sess_buf[BUF_SIZE] ;

}session_t, *psession_t ;
typedef int socket_t ;
void ftp_init_from_file(char* path, char* ip, char* port);
socket_t socket_server(char* ip, char* port);
void client_handle(psession_t arg);
int recvn(socket_t fd_recv, char* recv_buf, int len );
int readn(int fd_read, char* read_buf, int len );
int sendn(socket_t fd_send, char* send_buf, int len );
int writen(int fd_write, char* write_buf, int len );
socket_t socket_client(char* ip, char* port);
void trim_space(char* src);
int upload(socket_t fd_up, char* file_name);
int download(socket_t fd_down, char* file_name);
#endif


