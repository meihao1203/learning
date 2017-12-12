#include<stdio.h>
typedef struct student
{
	int num ;
	char name[20];
	float score;
}stu;
int main()
{
	stu s;
	char *p="110 meihao 99.99";
	int ret;
	ret=sscanf(p,"%d %s %f",&s.num,(char *)&s.name,&s.score);
	if(3!=ret)
	{
		perror("sscanf");
		return -1;
	}
	printf("%d %s %4.2f\n",s.num,s.name,s.score);
	return 1;
}
