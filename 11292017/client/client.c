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
        data d;
        bzero(&d,sizeof(d));
        recv(sfd,&d.len,sizeof(int),0);  //先接收要接收的文件名字大小
        recv(sfd,&d.buf,d.len,0);
        printf("file name is %s\n",d.buf);
        int fdw = open(d.buf,O_WRONLY|O_CREAT,0666);
        if(-1==fdw)
        {
                perror("open");
                return -1;
        }
        while(1)
        {
                memset(&d,0,sizeof(d));
                recv_n(sfd,(char*)&d.len,sizeof(int));
                if(d.len>0)
                {
                        recv_n(sfd,d.buf,d.len);
                        write(fdw,d.buf,d.len);
                }
                else
                {
                        break;
                }
        }
        memset(&d,0,sizeof(d));
        ret = recv(sfd,&d.len,sizeof(int),0); //阻塞，等待服务器关闭文件描述符这边就会读到0，然后再执行下面；
        //printf("ret =%d\n",ret);
        close(sfd);
        close(fdw);
        return 0;
}
