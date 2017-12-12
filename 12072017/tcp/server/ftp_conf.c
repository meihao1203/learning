#include"ftp.h"
static void ftp_arg_set(char* line, char* arg) 
{	
	char* ptr = strchr(line, '=');
	if(ptr == NULL)
	{
		ERR_EXIT("no =");
	}
	strcpy(arg, ptr + 1);
}
void ftp_init_from_file(char* path, char* ip, char* port)
{
	FILE* fp_conf = fopen(path, "r");
	if(fp_conf == NULL)
	{
		ERR_EXIT("open conf file fail!");	
	}
	char line[128] ;

	memset(line, 0, 128);
	fgets(line, 128, fp_conf) ;
	line[strlen(line) - 1] = '\0' ;
	ftp_arg_set(line, ip);

	memset(line, 0, 128);
	fgets(line, 128, fp_conf) ;
	line[strlen(line) - 1] = '\0' ;
	ftp_arg_set(line, port);
	fclose(fp_conf);
}
