#include<stdio.h>
#include<strings.h>
int main()
{
	FILE *fp = fopen("./1.txt","r+");
	char buf[3];
	while(!feof(fp))
	{
		bzero(buf,sizeof(buf));
		fread(buf,sizeof(char),sizeof(buf)-1,fp);
		printf("%s\n",buf);
	}
	return 0;
}