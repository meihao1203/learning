#include<stdio.h>
#include<string.h>
int main(int argc,char **argv)
{
	FILE *fp=fopen(argv[1],"wb+");
	char buf[128];
	strcpy(buf,"hello world");
	fwrite(buf,sizeof(char),strlen(buf),fp);
	fseek(fp,0,SEEK_SET);
	char str[128];
	fread(str,sizeof(char),sizeof(buf),fp);
	printf("str=%s\n",str);
	fclose(fp);
	return 1;
}
