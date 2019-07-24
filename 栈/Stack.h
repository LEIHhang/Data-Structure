#pragma once;
#include<stdio.h>
#include<assert.h>
#include<malloc.h>
#include <stdbool.h> 

typedef int STDataType;

typedef struct Stack
{
	STDataType* a;
	int top;
	int capacity;
}Stack;

void StackInit(Stack* ps); //��ʼ��
void StackDestory(Stack* ps);//����

void StackPush(Stack* ps, STDataType x);//����
void StackPop(Stack* ps); //ɾ��
STDataType StackTop(Stack* ps);//ָ��ջ��Ԫ��
bool StackEmpty(Stack* ps); //�п�
int StackSize(Stack* ps);//��

