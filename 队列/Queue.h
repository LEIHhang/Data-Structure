#pragma once;
#include<stdio.h>
#include<assert.h>

typedef int QUDataType;

typedef struct QueueNode
{
	QUDataType val;
	struct QueueNode* next;
}QueueNode;

typedef struct Queue
{
	QueueNode* _front; // 队头    
	QueueNode* _rear;  // 队尾
}Queue;

void QueueInit(Queue* pq); //初始化
void QueueDestory(Queue* pq);//销毁

QueueNode* BuyQueueNode(QUDataType x);//创建新结点 
void QueuePush(Queue* pq, QUDataType x); //入队
void QueuePop(Queue* pq); //出队
QUDataType QueueFront(Queue* pq); //返回队头结点
QUDataType QueueBack(Queue* pq); //返回队尾结点
int QueueEmpty(Queue* pq); //判空
int QueueSize(Queue* pq);//判长

void TestQueue();//测试