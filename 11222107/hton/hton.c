#include<arpa/inet.h>
#include<stdio.h>
int main(void)
{
	uint32_t val = 0x12345678;
	uint32_t i ;
	uint32_t j;
	i = htonl(val); //0x78563412 , 主机字节序是小端模式
	j = ntohl(val); //0x78563412
	printf("i = %x , j = %x\n",i,j);
	uint16_t val2 = 0x1234;
	uint16_t k;
	uint16_t z;
	k = htons(val2);  //0x3412
	z = ntohs(val2);  //0x3412
	printf("k = %x , z = %x\n",k,z);
	return 0;
}