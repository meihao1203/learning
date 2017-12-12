#include<stdio.h>
int main(int argc,char **argv)
{
	FILE *fp = popen(argv[1],"r");
	char buf[128];
	fread(buf,sizeof(char),sizeof(buf),fp);
	fputs(buf,stdout);
	//fputs(buf,1);
	return 0;
}