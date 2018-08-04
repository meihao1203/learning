//题目37：输入两个链表，找出它们的第一个公共节点。
//思路：两个单链表有公共结点就意味着有一些节点重合。首先遍历求出两个链表的长度，长的链表
//先走多出来的步数，之后两个链表同时开始遍历，直到遇到相同的节点。
#if 0
#include<iostream>
using namespace std;
typedef struct node
{
	int data;
	struct node* next;
}*pList,Node;
Node* firstCommentNode(pList first,pList second);
int lengthOfList(pList List);
void printList(pList List);
void test(pList first,pList second);
void test0();
void test1();
void test2();
int main()
{
	test0();  //正常情况，相同节点4
	cout<<endl;

	test1();  //没有公共节点
	cout<<endl;

	test2();  //空指针
	system("pause");
}
void test(pList first,pList second)
{
	printList(first);
	printList(second);
	Node* node = firstCommentNode(first,second);
	if(NULL!=node)
	cout<<node->data<<"("<<node->next->data<<")"<<endl;
	else
		cout<<"no common node"<<endl;
}
void test0()
{
#if 1
	node* node1 = new node;
	node1->data = 1;
	node* node2 = new node;
	node2->data = 2;
	node* node3 = new node;
	node3->data = 3;
	node* node4 = new node;
	node4->data = 4;
	node* node5 = new node;
	node5->data = 5;
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	node5->next = NULL;
	pList first = node1;

	node* node6 = new node;
	node6->data = 6;
	node6->next = node4;
	pList second = node6;
#endif
	test(first,second);
}
void test1()
{
#if 1
	node* node1 = new node;
	node1->data = 1;
	node* node2 = new node;
	node2->data = 2;
	node* node3 = new node;
	node3->data = 3;
	node* node4 = new node;
	node4->data = 4;
	node* node5 = new node;
	node5->data = 5;
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	node5->next = NULL;
	pList first = node1;

	node* node6 = new node;
	node6->data = 1;
	node* node7 = new node;
	node7->data = 2;
	node* node8 = new node;
	node8->data = 3;
	node* node9 = new node;
	node9->data = 4;
	node6->next = node7;
	node7->next = node8;
	node8->next = node9;
	node9->next = NULL;
	pList second = node6;
#endif
	test(first,second);
}
void test2()
{
	pList first = NULL;
	pList second = NULL;
	test(first,second);
}
void printList(pList List)
{
	if(NULL==List)
		return ;
	pList head = List;
	while(head!=NULL)
	{
		cout<<head->data<<"->";
		head = head->next;
	}
	cout<<"NULL"<<endl;
}
Node* firstCommentNode(pList first,pList second)
{
	if(NULL==first||NULL==second)
		return NULL;
	int firstListLen = lengthOfList(first);
	int secondListLen = lengthOfList(second);
	int diff = firstListLen>secondListLen?(firstListLen-secondListLen):(secondListLen-firstListLen);
	pList firstHead = first;
	pList secondHead = second;
	if(firstListLen>secondListLen)
	{
		for(int idx=0;idx!=diff;++idx)
			firstHead = firstHead->next;
	}
	else
	{
		for(int idx=0;idx!=diff;++idx)
			secondHead = secondHead->next;
	}
	while(firstHead!=NULL&&
		secondHead!=NULL&&
		firstHead->data!=secondHead->data)
	{
		firstHead = firstHead->next;
		secondHead = secondHead->next;
	}
	return firstHead;
}
int lengthOfList(pList List)
{
	if(NULL==List)
		return 0;
	pList head = List;
	int len = 0;
	while(head!=NULL)
	{
		++len;
		head = head->next;
	}
	return len;
}
#endif
//1->2->3->4->5->NULL
//6->4->5->NULL
//4(5)
//
//1->2->3->4->5->NULL
//1->2->3->4->NULL
//no common node
//
//no common node