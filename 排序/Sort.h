#include<stdio.h>
#include<assert.h>
#include<malloc.h>
#include<stdbool.h>
void Swap(int* a, int* b)//����AB
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
void AdjustDown(int* a, int size, int n)//size�ǶѴ�С��n���±�
{
	assert(a);
	int parent = n;//�������Ľ���±�һ���Ǹ��ڵ�
	int child = 2 * parent + 1;//����
	while (child < size)//���жϵ�Ҷ�ӽ��Ϊֹ
	{
		if (parent * 2 + 2 == size)//�ж������ҽڵ�
			child = 2 * parent + 1;
		else
			child = (a[2 * parent + 1] > a[2 * parent + 2] ?
			2 * parent + 1 : 2 * parent + 2);//ȡ�ϴ�ĺ��Ӻ͸���㽻��
		if (a[parent] < a[child])//�������
		{
			Swap(&a[parent], &a[child]);//������С���Ӻͷ���
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;//���Һ��Ӷ��ȷ�����ֹͣ
	}
}

typedef int STDataType;

typedef struct Stack
{
	STDataType* a;
	int top;
	int capacity;
}Stack;

void StackInit(Stack* ps) //��ʼ��
{
	assert(ps);
	ps->a = NULL;
	ps->capacity = 0;
	ps->top = 0;
}
void StackDestory(Stack* ps)//����
{
	assert(ps);
	if (ps->a != NULL)
	{
		free(ps->a);
		ps->top = 0;
		ps->capacity = 0;
		ps->a = NULL;//�ͷ���ռ�Ӧ���������ʼ״̬
	}
}
void StackPush(Stack* ps, STDataType x)//����
{
	assert(ps);
	if (ps->capacity == ps->top)
	{
		int newspace = (ps->capacity == 0 ? 2 : ps->capacity * 2);
		ps->capacity = newspace;
		ps->a = (STDataType*)realloc(ps->a, sizeof(STDataType)*newspace);
		//��realloc�У���ַΪ�����malloc�÷���ͬ
	}
	ps->a[ps->top] = x;
	ps->top++;
}
void StackPop(Stack* ps) //ɾ��
{
	assert(ps && ps->top != 0);
	--ps->top;
}
STDataType StackTop(Stack* ps)//����ջ��Ԫ��
{
	assert(ps&&ps->top != 0);
	return ps->a[ps->top - 1];
}
bool StackEmpty(Stack* ps) //�п�
{
	assert(ps);
	return !ps->top;
}
int StackSize(Stack* ps)//��
{
	assert(ps);
	return ps->top;
}

void InsertSort(int* a, int n);//��������
void ShellSort(int* a, int n);//ϣ������
void SelectSort(int* a, int n);//ѡ������
void HeapSort(int* a, int n);//������
void BubbleSort(int* a, int n);//ð��
void QuickSort(int* arr, int left, int right);//��������


