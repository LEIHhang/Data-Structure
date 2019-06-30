#pragma once
#include<assert.h>
#include<stdio.h>
#include<malloc.h>
typedef int SDataType;

typedef struct SlistNode
{
	SDataType data;
	struct SlistNode* pNext;
}Node;

typedef struct Slist
{
	Node* _head;
}Slist;

void SlistInit(Slist* pl);//初始化
void SlistPushBack(Slist* pl, SDataType data);//尾插
void SlistPushFront(Slist* pl, SDataType data);//头插
void SlistDelBack(Slist* pl);//尾删
void SlistDelFront(Slist* pl);//头删除
void SlistPrint(Slist* pl);//输出
Node* SListFind(Slist* plist, SDataType x);//查找某个x的位置
void SListInsertAfter(Node* pos, SDataType x); // 在pos的后面进行插入 
void SListEraseAfter(Node* pos);//删除POS后
void SListRemove(Slist* plist, SDataType x);//删除全部值为x的元素
int SListEmpty(Slist* pl);//检查空
int SListSize(Slist* pl);//判断长
void SListRemove(Slist* pl, SDataType x);//删除x
void SListRemoveAll(Slist* pl, SDataType x);//删除所有x