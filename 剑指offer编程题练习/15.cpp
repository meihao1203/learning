//题目15：输入一个链表，输出该链表中倒数第k个节点。
//注意代码的鲁棒性
#include<iostream>
using namespace std;
typedef struct node
{
	int data;
	struct node* next;
}*pList,Node;
Node* findKthToTail(pList head,int k);
void print(pList head);
void test(pList head,int k);

int main()
{
	node* node1 = new node;
	node1->data = 1;
	node1->next = NULL;
	node *node2 = new node;
	node2->data = 2;
	node2->next = NULL;
	node* node3 = new node;
	node3->data = 3;
	node3->next = NULL;
	node* node4 = new node;
	node4->data = 4;
	node4->next = NULL;
	node* node5 = new node;
	node5->data = 5;
	node5->next = NULL;
	pList head1 = node1;
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	//只有一个节点的链表
	node* node6 = new node;
	pList head2 = node6;
	node6->data = 8;
	node6->next = NULL;

	print(head1);
	print(head2);
	test(head1,3);
	test(head1,1);
	test(head1,5);
	test(head2,1);
	test(NULL,2);
	test(head2,2);
	system("pause");
}

Node* findKthToTail(pList head,int k)
{
	if(NULL==head||k<=0)
		return NULL;
	Node* pFront = head;
	Node* pBehind = NULL;
	for(int idx=0;idx!=k-1;++idx)  //倒数第k个，k-1
	{
		if(pFront->next!=NULL)
		{
			pFront = pFront->next;
		}
		else 
		{
			return NULL;
		}
	}
	pBehind = head;
	while(pFront->next!=NULL)
	{
		pFront = pFront->next;
		pBehind = pBehind->next;
	}
	return pBehind;
}
void print(pList head)
{
	if(NULL==head)
		return ;
	while(head->next!=NULL)
	{
		cout<<head->data<<"\t";
		head = head->next;
	}
	cout<<head->data<<"\t";
	cout<<endl;
	return ;
}
void test(pList head,int k)
{
	Node* res = findKthToTail(head,k);
	if(NULL==res)
		return ;
	cout<<res->data<<endl;
}
//相关题目
//求链表的中间节点，如果链表中结点总数为奇数，返回中间结点；偶数返回中间两个结点的任意一个。
//思路：定义两个指针，同时从链表的头结点出发，一个指针一次走一步，另一个指针一次走两步。
//走的快的指针到链表末尾时，走得慢的指针指针正好在中间。

//判断一个单项链表是否形成了环形结构。
//思路：走的快的指针走到了链表末尾也没有追上走的满的指针说明没有环。
