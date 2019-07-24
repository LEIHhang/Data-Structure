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

void ListNodeInit(List* plt);//初始化
void ListNodeDestory(List* plt);//销毁
void ListNodePushBack(List* plt, DataType x);//头插
void ListNodePushFront(List* plt, DataType x);//尾插
void ListNodeDelBack(List* plt);//尾删
void ListNodeDelFront(List* plt);//头删除
ListNode* ListNodeFind(List* plt, DataType x);//查找
void ListNodeInsert(ListNode* pos, List* plt, DataType x);//在pos前插入结点值为x的结点
void ListNodeRemove(List* plt, DataType x);//删除值为x的第一个结点
void ListNodeRemoveAll(List* plt, DataType x);//删除所有值为X的结点
