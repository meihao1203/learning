 ///
 /// @file    file.cpp
 /// @author  meihao1203(meihao19931203@outlook.com)
 /// @date    2018-03-29 11:29:01
 ///
 
#include<iostream>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
class safeFile
{
	public:
		safeFile(const char*);
		~safeFile();
		void write(const char*);
		void write(void*,int);
	private:
		FILE* _fp;
};
safeFile::safeFile(const char* str)
{
	cout<<"safeFile(const char*)"<<endl;
	_fp = fopen(str,"w+");
	if(NULL==_fp)
	{
		perror("fopen");
		exit(-1);
	}
}
safeFile::~safeFile()
{
	cout<<"~safeFile()"<<endl;
	fclose(_fp);
}
void safeFile::write(const char*str)
{
	cout<<"write(const char*)"<<endl;
	if(fputs(str,_fp)==EOF)
	{
		perror("fputs");
		exit(-1);
	}
}
void safeFile::write(void* src,int count)
{
	cout<<"write(const char*,int)"<<endl;
	if(fwrite(src,count,1,_fp)==0)
	{
		perror("fwrite");
		exit(-1);
	}
}
typedef struct
{
	int date;
	char buf[512];
}data;
int main()
{
	safeFile test("meihao");
	test.write("hello,world!");
	data d1;
	d1.date=10;
	strcpy(d1.buf,"03282018");
	test.write((void*)&d1,sizeof(d1));
}
