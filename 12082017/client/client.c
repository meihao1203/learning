#include"func.h"
int main(int argc,char **argv)
{
        if(3!=argc)
        {
                printf("error args\n");
                return -1;
        }
        int sfd = socket(AF_INET,SOCK_STREAM,0);
        if(-1==sfd)
        {
                perror("socket");
                return -1;
        }
        struct sockaddr_in ser;
        bzero(&ser,sizeof(ser));
        ser.sin_family = AF_INET;
        ser.sin_port = htons(atoi(argv[2]));
        ser.sin_addr.s_addr = inet_addr(argv[1]);
        int ret = connect(sfd,(struct sockaddr *)&ser,sizeof(ser));
        if(-1==ret)
        {
                perror("connect");
                return -1;
        }
		pdata pd = (pdata)calloc(1,sizeof(data));
		pcmd pc = (pcmd)calloc(1,sizeof(cmd));
		char read_cmd[MAXSIZE];
		int read_len;
     while( bzero(read_cmd,sizeof(read_cmd)) , (read_len = read(0,pc->cmd_buf,sizeof(pc->cmd_buf)))>0 )
     {
	 		deal_cmd(pc->cmd_buf);
	 		pc->cmd_len = strlen(pc->cmd_buf);
	 		send(sfd,&pc->cmd_len,sizeof(int),0);
	 		send_n(sfd,pc->cmd_buf,pc->cmd_len);
            if(strncmp("cd",pc->cmd_buf,2)==0)    //cmd->cd
	 		{
				bzero(pd,sizeof(data));
	 			recv(sfd,&pd->len,sizeof(int),0);
	 			recv_n(sfd,pd->buf,pd->len);
	 			printf("%s\n",pd->buf);
	 		}
			else if(strncmp("ls",pc->cmd_buf,2)==0)    //cmd->ls
			{
				while(1)
				{
					bzero(pd,sizeof(data));
					recv(sfd,&pd->len,sizeof(int),0);
					if(pd->len==0)
					{
						break;   //那边数据发送完毕
					}
					recv_n(sfd,pd->buf,pd->len);
					printf("%s\n",pd->buf);
				}
			}
			else if(strncmp("puts",pc->cmd_buf,4)==0)\
			{
				char puts_name[265] = {0};
				sscanf(pc->cmd_buf+5,"%s",puts_name);
				int flag;
				if(0==(is_file_exist(puts_name)))
				{
					flag = 0;
					send(sfd,&flag,sizeof(int),0);
					int ret = upload_file(sfd,puts_name);
					if(0==ret)
					{
						printf("upload %s success\n",puts_name);
					}
					else
					{
						printf("upload %s fail\n",puts_name);
					}
				}
				else 
				{
					flag = -1; 
					send(sfd,&flag,sizeof(int),0);
				}
			}
     }
     //memset(&d,0,sizeof(d));
     //ret = recv(sfd,&d.len,sizeof(int),0);
     //printf("ret =%d\n",ret);
     close(sfd);
     return 0;
}
