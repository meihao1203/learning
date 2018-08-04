//题目17：输入两个递增排序的链表，合并这两个链表并使新链表中的结点仍然是按照递增排序的
//思路：两个链表，分别从头开始比较，选择小的一个作为合并链表的新结点。由于每次都是这样的操作，可以用递归
#if 0
#include<iostream>
using namespace std;
typedef struct node
{
	int data;
	struct node* next;
}*pList,Node;
void print(pList head);
//pList merge(pList* head1,pList* head2);  //merge要到的新的链表，可以不用去修改原来的链表
pList merge(pList head1,pList head2); 
//void test(pList* head1,pList* head2);
void test(pList head1,pList head2);
int main()
{
#if 1
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
	node6->data = 2;
	node6->next = NULL;
	//
	node* node7 = new node;
	pList head3 = node7;
	node7->data = 1;
	node7->next = NULL;
#endif
	/*test(head1,head2);*/  //一个多个结点，一个一个结点
	/*test(head2,head3);*/
	pList head4 = NULL;
	test(head4,head3);  //一个空结点
	system("pause");
}
pList merge(pList head1,pList head2)
{
	if(NULL==head1)
		return head2;
	else if(NULL==head2)
		return head1;
	pList newHead = NULL;
	if(head1->data<head2->data)
	{
		newHead = head1;
		//(*head1) = (*head1)->next;
		newHead->next = merge(head1->next,head2);
	}
	else
	{
		newHead = head2;
		//(*head2) = (*head2)->next;
		newHead->next = merge(head1,head2->next);
	}
	return newHead;
}
void test(pList head1,pList head2)
{
	print(head1);
	print(head2);
	pList newList = merge(head1,head2);
	print(newList);
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
#endif