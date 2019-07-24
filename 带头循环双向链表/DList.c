#include"DList.h"
ListNode* BuyNewNode(DataType x)
{
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	newnode->val = x;
	newnode->next = NULL;
	newnode->prev = NULL;
	return newnode;
}
void ListNodeInit(List* plt)//��ʼ��
{
	plt->head = (ListNode*)malloc(sizeof(ListNode));
	ListNode* head = plt->head;
	head->prev = head;
	head->next = head;
}
void ListNodeDestory(List* plt)//����
{
	ListNode* cur = plt->head->next;
	ListNode*head = plt->head;
	while (cur != head)
	{
		ListNode* next = cur->next;
		free(cur);
		cur = next;
	}
	plt->head = NULL;
}
void ListNodePushFront(List* plt, DataType x)//ͷ��
{
	ListNode* head = plt->head;
	ListNode* first = head->next;
	ListNode* newnode = BuyNewNode(x);

	newnode->next = first;
	first->prev = newnode;

	head->next = newnode;
	newnode->prev = head;
}
void ListNodePushBack(List* plt, DataType x)//β��
{
	ListNode* head = plt->head;
	ListNode* tail = head->prev;
	ListNode* newnode = BuyNewNode(x);

	newnode->next = head;
	head->prev = newnode;

	tail->next = newnode;
	newnode->prev = tail;
}
void ListNodeDelBack(List* plt)//βɾ
{
	ListNode* head = plt->head;
	ListNode* beftail = head->prev->prev;
	free(head->prev);
	beftail->next = head;
	head->prev = beftail;
}
void ListNodeDelFront(List* plt)//ͷɾ��
{
	ListNode* head = plt->head;
	ListNode* second = head->next->next;
	free(head->next);
	head->next = second;
	second->prev = head;
}
ListNode* ListNodeFind(List* plt, DataType x)//����
{
	ListNode* head = plt->head;
	ListNode* cur = head->next;
	while (cur != head)
	{
		if (cur->val == x)
			return cur;
		cur = cur->next;
	}
	return NULL;
}
void ListNodeInsert(ListNode* pos, List* plt, DataType x)//��posǰ������ֵΪx�Ľ��
{
	ListNode* head = plt->head;
	ListNode* cur = head->next;
	while (cur != head)
	{
		if (cur == pos)
		{
			ListNode* newnode = BuyNewNode(x);
			ListNode* beforenode = cur->prev;
			newnode->next = pos;
			pos->prev = newnode;

			beforenode->next = newnode;
			newnode->prev = beforenode;
			return;
		}
		cur = cur->next;
	}
	return NULL;
}
void ListNodeDel(ListNode* pos, List* plt)//ɾ��pos���
{
	ListNode* head = plt->head;
	ListNode* cur = head->next;
	while (cur != head)
	{
		if (cur == pos)
		{
			ListNode* beforenode = cur->prev;
			
			beforenode->next = pos->next;
			pos->next->prev = beforenode;
			free(pos);
			return;
		}
		cur = cur->next;
	}
	return NULL;
}
void ListNodeRemove(List* plt, DataType x)//ɾ��ֵΪx�ĵ�һ�����
{
	ListNode* head = plt->head;
	ListNode* cur = head->next;
	while (cur != head)
	{
		if (cur->val == x)
		{
			ListNode* beforenode = cur->prev;

			beforenode->next = cur->next;
			cur->next->prev = beforenode;
			free(cur);
			return;
		}
		cur = cur->next;
	}
	return NULL;
}
void ListNodeRemoveAll(List* plt, DataType x)//ɾ������ֵΪX�Ľ��
{
	ListNode* head = plt->head;
	ListNode* cur = head->next;
	while (cur != head)
	{
		if (cur->val == x)
		{
			ListNode* beforenode = cur->prev;

			beforenode->next = cur->next;
			cur->next->prev = beforenode;
			free(cur);
			cur = beforenode->next;
		}
		else
		cur = cur->next;
	}
	return NULL;
}
void ListNodePrint(List* plt)//��ӡ
{
	ListNode* head = plt->head;
	ListNode* cur = head->next;
	printf("head<==>");
	while (cur != head)
	{
		printf("%d<==>", cur->val);
		cur = cur->next;
	}
	printf("\n");
	return;
}