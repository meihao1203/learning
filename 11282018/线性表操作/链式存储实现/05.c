//5��Լɪ�������˳��洢�������
#if 0
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
node* joseph(pNode* head,int m)
{
	node* phead = *head;
	int idx = 0;
	int len = 1;
	if((*head) == NULL)
		return NULL;
	phead = phead->next;
	while(phead != (*head))
	{
		++len;
		phead = phead->next;
	}
	phead = *head;
	while(len>1)  //ֻʣһ��Ԫ��
	{
		if(phead->data != -1)
			++idx;
		if(idx == m)
		{
			idx = 0;
			--len;
			phead->data = -1;
		}
		phead = phead->next;
	}
	phead = *head;
	while(phead->data == -1)
	{
		phead = phead->next;
	}
	return phead;
}
node* buildList()
{
	//��������
	//2->1->3->5->2 ѭ���������2ָ��ͷ��2
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
	node5->next = node1;
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
	node* tmp = joseph(&head,3);
	printf("%d \n",tmp->data);
}
int main()
{
	test();
	system("pause");  //stdlib.h
}
#endif
//5
//�밴���������. . .