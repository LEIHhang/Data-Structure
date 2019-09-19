#include"BinaryTree.h"
typedef BTNode* QUDataType;

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

//************************************�����Ƕ���

// ͨ��ǰ�����������"ABD##E#H##CF##G##"����������
BTNode* BinaryTreeCreate(BTDataType* arr, int* pi)
{
	if (arr[*pi] == '#')
		return NULL;

	BTNode* root = (BTNode*)malloc(sizeof(BTNode));
	root->data = arr[*pi];
	(*pi)++;

	root->left = BinaryTreeCreate(arr, pi);
	(*pi)++;

	root->right = BinaryTreeCreate(arr, pi);

	return root;
}

void BinaryTreeDestory(BTNode** root)//����
{
	if (*root == NULL)
		return;
	BinaryTreeDestory(&(*root)->left);
	BinaryTreeDestory(&(*root)->right);
	free(*root);
}
int BinaryTreeSize(BTNode* root);
int BinaryTreeLeafSize(BTNode* root)//�ж�Ҷ�ӽ�����
{
	if (root == NULL)
		return 0;
	if (root->left == NULL&&root->right == NULL)
		return 1;
	return BinaryTreeLeafSize(root->left)
		+ BinaryTreeLeafSize(root->right);
}
int BinaryTreeLevelKSize(BTNode* root, int k);
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)//����
{
	if (root == NULL)
		return NULL;
	if (root->data == x)//�Ӹ���
		return root;

	BTNode* lret = BinaryTreeFind(root->left, x);//����������
	if (lret != NULL)
		return lret;

	BTNode* rret = BinaryTreeFind(root->right, x);//����������
	if (rret != NULL)
		return rret;

	return NULL;//�������������Ҳ������ؿ�
}

// ����
void BinaryTreePrevOrder(BTNode* root);
void BinaryTreeInOrder(BTNode* root);
void BinaryTreePostOrder(BTNode* root);
// �ǵݹ����
// �������
void BinaryTreeLevelOrder(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root != NULL)
		QueuePush(&q, root);
	while (!QueueEmpty(&q))
	{
		BTNode* sign = QueueFront(&q);
		QueuePop(&q);
		printf("%c ", sign->data);
		if (sign->left != NULL)
			QueuePush(&q, sign->left);
		if (sign->right != NULL)
			QueuePush(&q, sign->right);
	}
}
// �ж϶������Ƿ�����ȫ������
bool  BinaryTreeComplete(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root != NULL)
		QueuePush(&q, root);
	while (QueueFront(&q)!=NULL)
	{
		BTNode* sign = QueueFront(&q);
		QueuePop(&q);
		QueuePush(&q, sign->left);
		QueuePush(&q, sign->right);
	}
	while (!QueueEmpty(&q))
	{
		if (QueueFront(&q) != NULL)
			return false;
		QueuePop(&q);
	}
	return true;
}
void BinaryTreePrevOrderNonR(BTNode* root);
void BinaryTreeInOrderNonR(BTNode* root);
void BinaryTreePostOrderNonR(BTNode* root);

void test1()
{
	BTNode* root = NULL;
	BTDataType* arr = "ABD##E#H##CF##G##";
	int i = 0;
	root=BinaryTreeCreate(arr, &i);
	BinaryTreeLevelOrder(root);
	printf("\n");
	printf("Ҷ�ӽڵ����Ϊ%d", BinaryTreeLeafSize(root));
}