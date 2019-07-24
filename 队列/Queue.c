#include"Queue.h"
//�����У�ͷָ��ʼ��ָ���һ��Ԫ�أ�βָ��ָ�����һ��Ԫ��
void QueueInit(Queue* pq) //��ʼ��
{
	assert(pq);
	pq->_front = NULL;
	pq->_rear = NULL;
}
void QueueDestory(Queue* pq)//����
{
	assert(pq && pq->_front != NULL);
	while (pq->_front)
	{
		QueueNode* next = pq->_front->next;
		free(pq->_front);
		pq->_front = next;
	}
	pq->_front = pq->_rear = NULL;
}

QueueNode* BuyQueueNode(QUDataType x)//�����½�� 
{
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	newnode->val = x;
	newnode->next = NULL;
	return newnode;
}
void QueuePush(Queue* pq, QUDataType x) //���
{
	assert(pq);
	if (pq->_rear == NULL)
	{
		pq->_rear = pq->_front = BuyQueueNode(x);
	}
	else
	{
		QueueNode* newnode = BuyQueueNode(x);
		pq->_rear->next = newnode;
		pq->_rear = newnode;
	}
}
void QueuePop(Queue* pq)//����
{
	assert(pq && pq->_front != NULL);

	QueueNode* next = pq->_front->next;
	free(pq->_front);
	pq->_front = next;
	
	if (pq->_front == NULL)
		pq->_rear = NULL;
	//���ֻʣһ��Ԫ�ر�ɾ���ˣ�����Ҫ�ÿգ�
	//����������Ұָ��ʶ�𲻳����ǿն���
}
QUDataType QueueFront(Queue* pq) //���ض�ͷ���ֵ
{
	assert(pq && pq->_front != NULL);
	return pq->_front->val;
}
QUDataType QueueBack(Queue* pq) //���ض�β���ֵ
{
	assert(pq && pq->_rear != NULL);
	return pq->_rear->val;
}
int QueueEmpty(Queue* pq) //�п�
{
	assert(pq);
	return pq->_front == NULL;
}
int QueueSize(Queue* pq)//�г�
{
	assert(pq);
	int k = 0;
	QueueNode* cur = pq->_front;
	while (cur)
	{
		k++;
		cur = cur->next;
	}
	return k;
}

void TestQueue()//����
{
	Queue pq;
	QueueInit(&pq);
	QueuePush(&pq, 1);
	QueuePush(&pq, 2);
	QueuePush(&pq, 3);
	
}