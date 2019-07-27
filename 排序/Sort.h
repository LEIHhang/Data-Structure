#include<stdio.h>
#include<assert.h>
#include<malloc.h>
#include<stdbool.h>
void Swap(int* a, int* b)//交换AB
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
typedef struct Heap
{
	int* a;
	int size;
	int capacity;
}Heap;
void AdjustDown(int* a, int size, int n)//size是堆大小，n是下标
{
	assert(a);
	int parent = n;//传进来的结点下标一定是父节点
	int child = 2 * parent + 1;//左孩子
	while (child < size)//当判断到叶子结点为止
	{
		if (parent * 2 + 2 == size)//判断有无右节点
			child = 2 * parent + 1;
		else
			child = (a[2 * parent + 1] > a[2 * parent + 2] ?
			2 * parent + 1 : 2 * parent + 2);//取较大的孩子和父结点交换
		if (a[parent] < a[child])//构建大堆
		{
			Swap(&a[parent], &a[child]);//交换较小孩子和夫结点
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;//左右孩子都比夫结点大就停止
	}
}

typedef int STDataType;

typedef struct Stack
{
	STDataType* a;
	int top;
	int capacity;
}Stack;

void StackInit(Stack* ps) //初始化
{
	assert(ps);
	ps->a = NULL;
	ps->capacity = 0;
	ps->top = 0;
}
void StackDestory(Stack* ps)//销毁
{
	assert(ps);
	if (ps->a != NULL)
	{
		free(ps->a);
		ps->top = 0;
		ps->capacity = 0;
		ps->a = NULL;//释放完空间应当保留其初始状态
	}
}
void StackPush(Stack* ps, STDataType x)//插入
{
	assert(ps);
	if (ps->capacity == ps->top)
	{
		int newspace = (ps->capacity == 0 ? 2 : ps->capacity * 2);
		ps->capacity = newspace;
		ps->a = (STDataType*)realloc(ps->a, sizeof(STDataType)*newspace);
		//当realloc中，地址为空则和malloc用法相同
	}
	ps->a[ps->top] = x;
	ps->top++;
}
void StackPop(Stack* ps) //删除
{
	assert(ps && ps->top != 0);
	--ps->top;
}
STDataType StackTop(Stack* ps)//返回栈顶元素
{
	assert(ps&&ps->top != 0);
	return ps->a[ps->top - 1];
}
bool StackEmpty(Stack* ps) //判空
{
	assert(ps);
	return !ps->top;
}
int StackSize(Stack* ps)//求长
{
	assert(ps);
	return ps->top;
}

void InsertSort(int* a, int n);//插入排序
void ShellSort(int* a, int n);//希尔排序
void SelectSort(int* a, int n);//选择排序
void HeapSort(int* a, int n);//堆排序
void BubbleSort(int* a, int n);//冒泡
void QuickSort(int* arr, int left, int right);//快速排序


