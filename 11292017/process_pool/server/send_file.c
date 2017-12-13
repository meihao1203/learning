#include"func.h"
void sendfile(int new_fd)
{
        data d;
        memset(&d,0,sizeof(d));
        d.len = strlen(FILENAME);
        strcpy(d.buf,FILENAME);
        int ret = send(new_fd,&d,4+d.len,0);  //先发送文件名给客户端，客户端获得这个文件名建立一个新的相同名字的文件；文件名的长度存放在d.len里面，所以发送长度就为4+d.len;
        if(-1==ret)
        {
                perror("send");
                return  ;
        }
        int fdr = open(FILENAME,O_RDONLY);
        if(-1==fdr)
        {
                perror("open");
                return ;
        }
        while(memset(&d,0,sizeof(d)),(d.len=read(fdr,d.buf,sizeof(d.buf)))>0)
        {
                send_n(new_fd,(char*)&d,4+d.len);
        }
        int flag = 0;  //标志这边已经发送完文件里，客户端可以断开连接了
        send(new_fd,&flag,sizeof(int),0);
        close(new_fd);
        close(fdr);
}