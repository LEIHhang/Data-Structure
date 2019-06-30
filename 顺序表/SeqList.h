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
void SeqListCheck(SeqList* ps);//检查空间是否够用，不够扩容，任何插入操作都要用
void SeqListInit(SeqList* ps);//初始化函数，分配四个数据大小的空间
void SeqListDestory(SeqList* ps);//删除
void SeqListPushBack(SeqList* ps,DateType x);//尾插
void SeqListPushFront(SeqList* ps, DateType x);//头插
void SeqListPopBack(SeqList* ps);//删除尾
void SeqListPopFront(SeqList* ps);//删除头
void SeqListInsert(SeqList* ps,size_t pos,DateType x);//指定位置插入
void SeqListErase(SeqList* ps, size_t pos);//指定位置删除
size_t SeqListSize(SeqList* ps);//返回当前指向空余位置
size_t SeqListFind(SeqList* ps, DateType x);//查找x的位置
DateType SeqListAT(SeqList* ps, size_t pos);//查找当前位置的值