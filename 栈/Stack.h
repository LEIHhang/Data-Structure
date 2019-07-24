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

void StackInit(Stack* ps); //初始化
void StackDestory(Stack* ps);//销毁

void StackPush(Stack* ps, STDataType x);//插入
void StackPop(Stack* ps); //删除
STDataType StackTop(Stack* ps);//指向栈顶元素
bool StackEmpty(Stack* ps); //判空
int StackSize(Stack* ps);//求长

