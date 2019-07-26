#include<stdio.h>
#include<assert.h>
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
void InsertSort(int* a, int n);//��������
void ShellSort(int* a, int n);//ϣ������
void SelectSort(int* a, int n);//ѡ������
void HeapSort(int* a, int n);//������
void BubbleSort(int* a, int n);//ð��
void QuickSort(int* arr, int left, int right);//��������


