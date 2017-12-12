#include<stdio.h>
#include<unistd.h>
#include<shadow.h>
#include<string.h>
#include<stdlib.h>
#define _XOPE_SOURCE
void get_salt(char *salt,char *passwd)
{
	int i,j;
	for(i=0,j=0;j!=3;++i)
	{
		if(passwd[i]=='$')
			j++;
	}
	printf("\n%d\n",i);
	strncpy(salt,passwd,i-1);
}
int main()
{
	struct spwd *sp;
	char *passwd;
	char *name;
	char salt[512]={0};
	//获得输入的用户名和密码;
	//char *getpass(const char *prompt);
	name = getpass("please input usrname:");
	passwd = getpass("please input passwd:");
	//struct spwd *getspnam(const char *name);
	sp = getspnam(name); //struct spwd *getspnam(const char *name);
	if(NULL==sp)
	{
		perror("getspnam");
		return -1;
	}
	get_salt(salt,sp->sp_pwdp);
	printf("%s\n",salt);
	if( ( strcmp(sp->sp_pwdp,crypt(passwd,salt)) )==0)
		printf("success!\n");
	else 
		printf("fail!\n");
	return 0;
}