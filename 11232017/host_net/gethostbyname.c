#include<netdb.h>
#include<stdio.h>
#include<arpa/inet.h>
#include<string.h>
#include<strings.h>
int main(int argc,char **argv)
{
	if(2!=argc)
	{
		printf("error argcs\n");
		return -1;
	}
	struct hostent *p = NULL;
	p = gethostbyname(argv[1]);
	printf("正式主机名: %s\n",p->h_name);
	char *pstr = NULL;
	for(pstr=*(p->h_aliases);pstr!=NULL;pstr=*(++p->h_aliases))
	{
		printf("主机别名: %s\n",pstr);
	}
	char dst[64];
	char *pstr1 = *(p->h_addr_list);
	while(NULL!=pstr1)
	{
		bzero(dst,sizeof(dst));
		inet_ntop(p->h_addrtype,pstr1,dst,sizeof(dst));
		printf("IP地址 %s\n",dst);
		pstr1 = *(++p->h_addr_list);
	}
	bzero(dst,sizeof(dst));
	p = gethostbyname(argv[1]);
	inet_ntop(p->h_addrtype,*(p->h_addr_list),dst,sizeof(dst));
	printf("%s\n",dst);
	return 0;
}