//1�������Ա���ɾ��������Сֵ��Ԫ�أ��ճ���λ�������һ��Ԫ���(����ɾ��Ϊʲô��Ҫ�)
#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
	int data;
	struct Node* next;
}node,*pNode;
node* delNode(pNode* head,pNode del)
{  //������ɾ��ָ�����del������������ͷ���
	node* cur = *head;
	if(head==NULL||del==NULL)
	{
		if(head==NULL)
			return NULL;
		else
			return *head;
	}
	//���Ҫɾ������ͷ���
	if( (*head) == del )
	{
		*head = (*head)->next;
		free(del);
		del = NULL;
		return *head;
	}
	//ɾ����ͷ���
	while(cur != NULL)
	{
		if(cur->next == del)
		{
			cur->next = cur->next->next;
			free(del);
			del = NULL;
			break;
		}
		cur = cur->next;
	}
	return *head;
}
node* delMinElement(pNode* head)
{
	node* min = *head;
	node* phead = *head;
	if( (*head) == NULL )
		return NULL;
	
	while(phead != NULL)
	{
		if(phead->data < min->data )
			min = phead;
		phead = phead->next;
	}
	*head = delNode(head,min);
	return *head;
}
node* buildList()
{
	//��������
	//2->1->3->5->2
	node* head = NULL;
	node* node1 = (node*)malloc(sizeof(node));
	node* node2 = (node*)malloc(sizeof(node));
	node* node3 = (node*)malloc(sizeof(node));
	node* node4 = (node*)malloc(sizeof(node));
	node* node5 = (node*)malloc(sizeof(node));
	node1->data = 2;
	
	node2->data = 1;
	
	node3->data = 3;
	
	node4->data = 5;
	
	node5->data = 2;
	head = node1;
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	node5->next = NULL;
	return head;
}
void printList(pNode head)
{
	while(head!=NULL)
	{
		printf("%d ",head->data);
		head = head->next;
	}
	printf("\n");
}
void test()
{
	node* head = buildList();
	//ɾ����С���
	head = delMinElement(&head);
	printList(head);
}
int main()
{
	test();
	system("pause");  //stdlib.h
}
//2 3 5 2
//�밴���������. . .
