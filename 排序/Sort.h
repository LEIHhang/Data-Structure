#include<stdio.h>
#include<assert.h>
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
void InsertSort(int* a, int n);//插入排序
void ShellSort(int* a, int n);//希尔排序
void SelectSort(int* a, int n);//选择排序
void HeapSort(int* a, int n);//堆排序
void BubbleSort(int* a, int n);//冒泡
void QuickSort(int* arr, int left, int right);//快速排序


