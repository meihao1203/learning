#include <stdio.h>
#include <unistd.h>
#include <string.h>
int main()
{
    char szBuf[32],szBuf2[50];
    printf("Input string:");
	//fflush(stdout);	//要刷新标准输出流，才可以立即在屏幕上显示”Input  string”
//fflush用于linux中的时候，只对fflush(stdout)有效。
    int iRet=read(0,szBuf,sizeof(szBuf));
    szBuf[iRet]=0;	//read是以无类型指针方式读的数据，不会自动在缓冲区后加0结束标记。
    sprintf(szBuf2,"The string is:%s",szBuf);
    write(1,szBuf2,strlen(szBuf2));
    return 0;
}
