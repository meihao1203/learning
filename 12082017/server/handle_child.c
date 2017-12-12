#include"func.h"
void do_cd(int new_fd,pcmd pc)
{
	char dir[MAXSIZE];
	bzero(dir,sizeof(dir));
	sscanf(pc->cmd_buf+3,"%s",dir);
	chdir(dir);
	bzero(dir,sizeof(dir));
	getcwd(dir,sizeof(dir));
	int len = strlen(dir);
	send(new_fd,&len,sizeof(int),0);
	send_n(new_fd,dir,len);
}
void do_ls(int new_fd,pcmd pc)
{
	char *pwd = getcwd(NULL,0);
	DIR *dir = NULL;
	dir = opendir(pwd);
	if(NULL==dir)
	{
		perror("opendir");
		return ;
	}
	struct dirent *q = NULL;
	off_t I;
	while( (q=readdir(dir))!=NULL )
	{
		if((strcmp(q->d_name,".")!=0)&&(strcmp(q->d_name,"..")!=0))
		{
			bzero(pc,sizeof(cmd));
			file_stat(pc->cmd_buf,q->d_name);  //传入数组，获取ls -ll命令能显示的所有信息
			//printf("%s\n",pc->cmd_buf);
			pc->cmd_len = strlen(pc->cmd_buf);
			if(q->d_type==4)   //那个文件宏定义判断是不是目录有问题，其他正常
			{
				pc->cmd_buf[0] = 'd';
			}
			send(new_fd,&pc->cmd_len,sizeof(int),0);
			send_n(new_fd,pc->cmd_buf,pc->cmd_len);
		}
	}
	int end = 0;
	send(new_fd,&end,sizeof(int),0); //发送0，对方拿到就知道这边数据发送完了
}
void child_handle(int new_fd)
{
	pcmd pc = (pcmd)calloc(1,sizeof(cmd));
	int recv_ret;
	while(1)
	{
		bzero(pc,sizeof(cmd));
		recv_ret = recv(new_fd,&pc->cmd_len,sizeof(int),0);
		if(recv_ret==0||pc->cmd_len==0)
		{
			printf("client exit!\n");
			close(new_fd);
			free(pc);
			pc = NULL;
			return ;
		}
		recv_n(new_fd,pc->cmd_buf,pc->cmd_len);
		if(strncmp("cd",pc->cmd_buf,2)==0)
		{	
			do_cd(new_fd,pc);
		}
		else if(strncmp("ls",pc->cmd_buf,2)==0)
		{
			do_ls(new_fd,pc);
		}
		else if(strncmp("puts",pc->cmd_buf,4)==0)
		{
			int flag;
			recv(new_fd,&flag,sizeof(int),0);
			if(0==flag)
			{
				recv_file(new_fd);
			}
		}
	}
}
