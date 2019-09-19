#include"BinaryTree.h"
typedef BTNode* QUDataType;

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

//************************************上面是队列

// 通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树
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

void BinaryTreeDestory(BTNode** root)//销毁
{
	if (*root == NULL)
		return;
	BinaryTreeDestory(&(*root)->left);
	BinaryTreeDestory(&(*root)->right);
	free(*root);
}
int BinaryTreeSize(BTNode* root);
int BinaryTreeLeafSize(BTNode* root)//判断叶子结点个数
{
	if (root == NULL)
		return 0;
	if (root->left == NULL&&root->right == NULL)
		return 1;
	return BinaryTreeLeafSize(root->left)
		+ BinaryTreeLeafSize(root->right);
}
int BinaryTreeLevelKSize(BTNode* root, int k);
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)//查找
{
	if (root == NULL)
		return NULL;
	if (root->data == x)//从根找
		return root;

	BTNode* lret = BinaryTreeFind(root->left, x);//从左子树找
	if (lret != NULL)
		return lret;

	BTNode* rret = BinaryTreeFind(root->right, x);//从右子树找
	if (rret != NULL)
		return rret;

	return NULL;//即左右子树都找不到返回空
}

// 遍历
void BinaryTreePrevOrder(BTNode* root);
void BinaryTreeInOrder(BTNode* root);
void BinaryTreePostOrder(BTNode* root);
// 非递归遍历
// 层序遍历
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
// 判断二叉树是否是完全二叉树
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
	printf("叶子节点个数为%d", BinaryTreeLeafSize(root));
}