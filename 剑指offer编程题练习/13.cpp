//链表删除一个节点，
//链表空，链表一个节点，删除的是为尾节点
//不是特殊节点，O(1)完成，尾节点O(n),平均（O(1)*(n-1)+O(n)）/n = O(1);
#include<iostream>
using namespace std;
typedef struct Node
{
	int data;
	struct Node* next;
}*List,node;
int deleteListNode(List* head,node* deleteNode);
void printList(List head);
void test(List* head,node* deleteNode);
#if 0
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
	List head1 = node1;
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	//只有一个节点的链表
	node* node6 = new node;
	List head2 = node6;
	node6->data = 8;
	node6->next = NULL;
#endif
	printList(head1);
	printList(head2);
	test(&head1,node3);  //删除中间节点
	test(&head1,node5);  //删除尾节点
	test(&head2,node6);  //链表只有一个节点
	List head3 = NULL;
	test(&head3,node2);   //指针为空
	printList(head1);
	printList(head2);
	system("pause");
}
#endif
void printList(List head)
{
	if(NULL==head)
		return ;
	while(head!=NULL)
	{
		cout<<head->data<<"\t";
		head = head->next;
	}
	cout<<endl;
}
int deleteListNode(List* head,node* deleteNode)
{
	if(NULL==(*head)||NULL==deleteNode)  //这里要(*head)，如果测试代码直接传NULL,NULL变量也是有一个地址的
		return -1;
	if(deleteNode->next!=NULL)  //中间节点,链表采用O(1)时间复杂度内删除节点，所以不用考虑删除的是头结点,反正都是用后一个节点覆盖
	{
		node* tmp = deleteNode->next;
		deleteNode->data = deleteNode->next->data;
		deleteNode->next = deleteNode->next->next;
		delete tmp;
		tmp = NULL;
	}
	else if((*head)==deleteNode)//只有一个节点的链表
	{
		delete deleteNode;
		deleteNode = NULL;
		(*head) = NULL;  //链表头结点赋值NULL
	}
	else //最后一种情况，删除的是最后一个节点
	{
		List phead = (*head);
		while(phead->next!=deleteNode)
			phead = phead->next;
		phead->next = NULL;
		delete deleteNode;
		deleteNode = NULL;
	}
	return 0;
}
void test(List* head,node* deleteNode)
{
	deleteListNode(head,deleteNode);
	printList(*head);
}