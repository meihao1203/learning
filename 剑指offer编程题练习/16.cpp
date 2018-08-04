//题目16：定义一个函数，输入一个链表的头结点，反转该链表并输出反转后链表的头结点。
#include<iostream>
using namespace std;
typedef struct node
{
	int data;
	struct node* next;
}*pList,Node;
void print(pList head);
pList reverseList(pList* head);
void test(pList* head);
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

	test(&head1);
	test(&head2);  //只有一个结点
	pList null  = NULL;
	test(&null);
}
void test(pList* head)
{
	print(*head);
	pList newList = reverseList(head);
	if(NULL==newList)
		return ;
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
pList reverseList(pList* head)
{
	if(NULL==(*head))
		return NULL;
	pList newList = NULL;
	Node* current = (*head);
	Node* pre = NULL;
	Node* next = NULL;
	while(current!=NULL)
	{
		next = current->next;  //记录当前结点的下一个结点
		if(next==NULL)  //结点末尾，等同一个结点
		{
			newList = current;
		}
		current->next = pre;  //逆转
		pre = current; 
		current = next;
	}
	return newList;
}
