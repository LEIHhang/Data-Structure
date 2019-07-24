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
	QueueNode* _front; // ��ͷ    
	QueueNode* _rear;  // ��β
}Queue;

void QueueInit(Queue* pq); //��ʼ��
void QueueDestory(Queue* pq);//����

QueueNode* BuyQueueNode(QUDataType x);//�����½�� 
void QueuePush(Queue* pq, QUDataType x); //���
void QueuePop(Queue* pq); //����
QUDataType QueueFront(Queue* pq); //���ض�ͷ���
QUDataType QueueBack(Queue* pq); //���ض�β���
int QueueEmpty(Queue* pq); //�п�
int QueueSize(Queue* pq);//�г�

void TestQueue();//����