#include"head.h"
typedef struct student
{
	int num;
	char name[20];
	float score;
}stu,pstu;
int main(int argc, char **argv)
{
	//stu s[2]={{100,"meihao",89.23},{101,"xiaomei",34.23}};
	stu s[2]={100,"meihao",89.23,101,"xiaomei",34.23};
	printf("%5d %10s %5.2f\n",s[0].num,s[0].name,s[0].score);
	printf("%5d %10s %5.2f\n",s[1].num,s[1].name,s[1].score);
	int fdw = open(argv[1],O_RDWR|O_CREAT,0666);
	write(fdw,&s[1],sizeof(stu));
	lseek(fdw,0,SEEK_SET);
	stu tmp;
	int ret = read(fdw,&tmp,sizeof(stu));
	printf("%5d %10s %5.2f\n",tmp.num,tmp.name,tmp.score);
	return 0;
}
