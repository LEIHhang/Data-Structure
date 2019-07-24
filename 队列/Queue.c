#include"Queue.h"
//队列中，头指针始终指向第一个元素，尾指针指向最后一个元素
void QueueInit(Queue* pq) //初始化
{
	assert(pq);
	pq->_front = NULL;
	pq->_rear = NULL;
}
void QueueDestory(Queue* pq)//销毁
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

QueueNode* BuyQueueNode(QUDataType x)//创建新结点 
{
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	newnode->val = x;
	newnode->next = NULL;
	return newnode;
}
void QueuePush(Queue* pq, QUDataType x) //入队
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
void QueuePop(Queue* pq)//出队
{
	assert(pq && pq->_front != NULL);

	QueueNode* next = pq->_front->next;
	free(pq->_front);
	pq->_front = next;
	
	if (pq->_front == NULL)
		pq->_rear = NULL;
	//如果只剩一个元素被删除了，则需要置空，
	//否则会误产生野指针识别不出来是空队列
}
QUDataType QueueFront(Queue* pq) //返回队头结点值
{
	assert(pq && pq->_front != NULL);
	return pq->_front->val;
}
QUDataType QueueBack(Queue* pq) //返回队尾结点值
{
	assert(pq && pq->_rear != NULL);
	return pq->_rear->val;
}
int QueueEmpty(Queue* pq) //判空
{
	assert(pq);
	return pq->_front == NULL;
}
int QueueSize(Queue* pq)//判长
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

void TestQueue()//测试
{
	Queue pq;
	QueueInit(&pq);
	QueuePush(&pq, 1);
	QueuePush(&pq, 2);
	QueuePush(&pq, 3);
	
}