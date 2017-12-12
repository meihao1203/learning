#include<stdio.h>
#include<string.h>
int main(int argc , char **argv)
{
	FILE *fp = popen(argv[1],"w");
	char buf[128]="hello , world!";
	fwrite(buf,sizeof(char),strlen(buf),fp);
	pclose(fp);
	return 0;
}