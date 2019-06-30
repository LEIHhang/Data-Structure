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

void SlistInit(Slist* pl);//��ʼ��
void SlistPushBack(Slist* pl, SDataType data);//β��
void SlistPushFront(Slist* pl, SDataType data);//ͷ��
void SlistDelBack(Slist* pl);//βɾ
void SlistDelFront(Slist* pl);//ͷɾ��
void SlistPrint(Slist* pl);//���
Node* SListFind(Slist* plist, SDataType x);//����ĳ��x��λ��
void SListInsertAfter(Node* pos, SDataType x); // ��pos�ĺ�����в��� 
void SListEraseAfter(Node* pos);//ɾ��POS��
void SListRemove(Slist* plist, SDataType x);//ɾ��ȫ��ֵΪx��Ԫ��
int SListEmpty(Slist* pl);//����
int SListSize(Slist* pl);//�жϳ�
void SListRemove(Slist* pl, SDataType x);//ɾ��x
void SListRemoveAll(Slist* pl, SDataType x);//ɾ������x