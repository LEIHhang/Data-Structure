#include"DList.h"
ListNode* BuyNewNode(DataType x)
{
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	newnode->val = x;
	newnode->next = NULL;
	newnode->prev = NULL;
	return newnode;
}
void ListNodeInit(List* plt)//初始化
{
	plt->head = (ListNode*)malloc(sizeof(ListNode));
	ListNode* head = plt->head;
	head->prev = head;
	head->next = head;
}
void ListNodeDestory(List* plt)//销毁
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
void ListNodePushFront(List* plt, DataType x)//头插
{
	ListNode* head = plt->head;
	ListNode* first = head->next;
	ListNode* newnode = BuyNewNode(x);

	newnode->next = first;
	first->prev = newnode;

	head->next = newnode;
	newnode->prev = head;
}
void ListNodePushBack(List* plt, DataType x)//尾插
{
	ListNode* head = plt->head;
	ListNode* tail = head->prev;
	ListNode* newnode = BuyNewNode(x);

	newnode->next = head;
	head->prev = newnode;

	tail->next = newnode;
	newnode->prev = tail;
}
void ListNodeDelBack(List* plt)//尾删
{
	ListNode* head = plt->head;
	ListNode* beftail = head->prev->prev;
	free(head->prev);
	beftail->next = head;
	head->prev = beftail;
}
void ListNodeDelFront(List* plt)//头删除
{
	ListNode* head = plt->head;
	ListNode* second = head->next->next;
	free(head->next);
	head->next = second;
	second->prev = head;
}
ListNode* ListNodeFind(List* plt, DataType x)//查找
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
void ListNodeInsert(ListNode* pos, List* plt, DataType x)//在pos前插入结点值为x的结点
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
void ListNodeDel(ListNode* pos, List* plt)//删除pos结点
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
void ListNodeRemove(List* plt, DataType x)//删除值为x的第一个结点
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
void ListNodeRemoveAll(List* plt, DataType x)//删除所有值为X的结点
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
void ListNodePrint(List* plt)//打印
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