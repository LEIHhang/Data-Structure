#pragma once
#include<stdio.h>
#include<assert.h>
#include<malloc.h>

typedef int DataType;

typedef struct ListNode
{
	DataType val;
	struct ListNode* prev;
	struct ListNode* next;
}ListNode;

typedef struct List
{
	ListNode* head;
}List;

void ListNodeInit(List* plt);//��ʼ��
void ListNodeDestory(List* plt);//����
void ListNodePushBack(List* plt, DataType x);//ͷ��
void ListNodePushFront(List* plt, DataType x);//β��
void ListNodeDelBack(List* plt);//βɾ
void ListNodeDelFront(List* plt);//ͷɾ��
ListNode* ListNodeFind(List* plt, DataType x);//����
void ListNodeInsert(ListNode* pos, List* plt, DataType x);//��posǰ������ֵΪx�Ľ��
void ListNodeRemove(List* plt, DataType x);//ɾ��ֵΪx�ĵ�һ�����
void ListNodeRemoveAll(List* plt, DataType x);//ɾ������ֵΪX�Ľ��
