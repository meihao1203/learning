#include<iostream>
#include<stdlib.h>
#define max  ~( 1<<(sizeof(int)*8-1) )
using namespace std;
//散列函数采用除留余数法
//冲突解决采用开放定址法的线性探测法
int hashFunc(int key,int length);
int initHashTable(int* hashTable,int length);  //成功返回0，失败返回-1
int hashInsert(int* hashTable,int key,int length);   //成功返回0，失败返回-1
static enum status{failture=-1,success=0} flag;
int hashSearch(int*hashTable,int key,int length);  
void test();
int main()
{
	test();
}
void test()
{
	int arr[12] = {12,67,56,16,25,37,22,29,15,47,48,34};
	int* hashTable = new int[12]();
	int ret = initHashTable(hashTable,12);
	if(-1==ret)
		cout<<"initHashTable fail!"<<endl;

	cout<<"哈希表待插入元素：";
	for(int idx=0;idx!=12;++idx)
	{
		cout<<arr[idx]<<" ";
		hashInsert(hashTable,arr[idx],12);
	}
	cout<<endl;

	cout<<"哈希表：";
	for(int idx=0;idx!=12;++idx)
	{
		cout<<hashTable[idx]<<" ";
	}
	cout<<endl;

	cout<<"对应插入元素序列在哈希表查找元素：";
	for(int idx=0;idx!=12;++idx)
	{
		int ret = hashSearch(hashTable,arr[idx],12);
		if( ret==-1 && flag == failture)
		{
			cout<<"search "<<arr[idx]<<" fail"<<endl;
		}
		cout<<hashTable[ret]<<" ";
	}
	cout<<endl;
	cout<<"查找1:"<<endl;
	int rett = hashSearch(hashTable,1,12);
	if( rett==-1 && flag == failture)
	{
		cout<<"search "<<1<<" fail"<<endl;
		return ;
	}
	cout<<hashTable[rett]<<endl;
}
int initHashTable(int* hashTable,int length)
{
	if(nullptr==hashTable || length<=0)
		return -1;
	for(int idx=0;idx!=length;++idx)
	{
		hashTable[idx] = max;
	}
	return 0;
}
int hashFunc(int key,int length)
{
	if(key==max||length<=0)
		return -1;
	return key % length;  //除留余数
}
int hashInsert(int* hashTable,int key,int length)
{
	if(nullptr==hashTable||length<=0)
		return -1;
	int hashAddr = hashFunc(key,length);
	if(-1==hashAddr)
		return -1;
	for(int idx=0;idx!=length;++idx)  //循环，最大哈希表长度
	{
		if(hashTable[hashAddr]!=max)  //冲突
			hashAddr = (hashAddr+1) % 12; //开放定址法的线性探测法,查找下一个可存放数据的空间
		else 
			break;
	}
	if(max==hashTable[hashAddr])
	{
		hashTable[hashAddr] = key;
		return 0;
	}
	return -1;
}
int hashSearch(int*hashTable,int key,int length)
{
	flag = success;
	if(nullptr==hashTable||length<=0)
	{
		flag = failture;
		return -1;
	}
	int hashAddr = hashFunc(key,length);
	while(key!=hashTable[hashAddr])
	{
		hashAddr = (hashAddr+1) % length;
		if(max==hashTable[hashAddr] || hashAddr == hashFunc(key,length))  //如果探测到下一个地址为空，还没有找到，或者循环找了一遍又回到最开始的hashAddr
		{
			flag = failture;
			return -1;
		}
	}
	return hashAddr;
}
//哈希表待插入元素：12 67 56 16 25 37 22 29 15 47 48 34 
//哈希表：12 25 37 15 16 29 48 67 56 34 22 47 
//对应插入元素序列在哈希表查找元素：12 67 56 16 25 37 22 29 15 47 48 34 
//查找1:
//search 1 fail
