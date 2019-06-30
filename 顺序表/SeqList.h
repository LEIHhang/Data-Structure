#pragma once
#include<stdio.h>
typedef int DateType;
typedef struct SeqList
{
	DateType* arr;
	size_t size;
	size_t capacity;
}SeqList;
void menu();
void SeqListCheck(SeqList* ps);//���ռ��Ƿ��ã��������ݣ��κβ��������Ҫ��
void SeqListInit(SeqList* ps);//��ʼ�������������ĸ����ݴ�С�Ŀռ�
void SeqListDestory(SeqList* ps);//ɾ��
void SeqListPushBack(SeqList* ps,DateType x);//β��
void SeqListPushFront(SeqList* ps, DateType x);//ͷ��
void SeqListPopBack(SeqList* ps);//ɾ��β
void SeqListPopFront(SeqList* ps);//ɾ��ͷ
void SeqListInsert(SeqList* ps,size_t pos,DateType x);//ָ��λ�ò���
void SeqListErase(SeqList* ps, size_t pos);//ָ��λ��ɾ��
size_t SeqListSize(SeqList* ps);//���ص�ǰָ�����λ��
size_t SeqListFind(SeqList* ps, DateType x);//����x��λ��
DateType SeqListAT(SeqList* ps, size_t pos);//���ҵ�ǰλ�õ�ֵ