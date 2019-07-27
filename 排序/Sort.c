#include"Sort.h"

void InsertSort(int* arr, int n)//插入排序
{
	int i = 0;
	int j = 0;
	for (i = 1; i <= n - 1; i++)
	{
		int temp = arr[i];//取第二个元素开始比较
		for (j = i - 1; j >= 0; j--)
		{
			if (temp < arr[j])
			{
				arr[j + 1] = arr[j];//从最后一个元素比较，若小的话往后移动移位
			}
			else
				break;
		}
		//因为最后一次j--了，但是没有移动
		//所以这里j要加一
		arr[j + 1] = temp;
	}
}
void ShellSort(int* arr, int n)//希尔排序
{
	int tag = n;
	int i = 0;
	int j = 0;
	while (tag>1)
	{
		tag = tag / 3 + 1;
		for (i = 0; i <= n - 1; i++)
		{
			int* temp = &arr[i];
			for (j = i + tag; j <= n - 1; j += tag)
			{
				if (*temp > arr[j])
				{
					Swap(temp, &arr[j]);
					temp = &arr[j];
				}
				else
					break;
			}	
		}
	}
}
void SelectSort(int* arr, int n)//选择排序
{
	int begin = 0;
	int end = n - 1;
	int index = 0;
	int rear = 0;
	while (begin<=end)
	{
		for (index = begin; index<=end; index++)
		{
			if (arr[begin] > arr[index])
				Swap(&arr[begin], &arr[index]);
		}
		for (index = begin; index <= end; index++)
		{
			if (arr[end] < arr[index])
				Swap(&arr[end], &arr[index]);
		}
		begin++;
		end--;
	}

}

void HeapSort(int* a, int size)//堆排序//升序
{
	//1、先建一个大堆(升序建立大堆
	for (int i = size / 2 - 1; i >= 0; i--)
	{
		AdjustDown(a, size, i);//向下调整,n是下标
	}
	int end = size - 1;
	//2、每次令堆顶和堆尾元素交换
 	while (end>0)
	{
		Swap(&a[0], &a[end]);
		//3、向下调整，改变数组范围
		AdjustDown(a, end, 0);
		end--;
	}
}

void BubbleSort(int* arr, int n)
{

	for (size_t j = n-1; j > 0; j--)
	{
		for (size_t i = 0; i < j; i++)
		{
			if (arr[i]>arr[i + 1])
			{
				Swap(&arr[i], &arr[i + 1]);
			}
		}
	}
}
int TreeCatchMid(int* arr, int left, int right)//三数取中
{
	int mid = left + (right - left) / 2;
	if (arr[left] < arr[right])
	{
		if (arr[mid] < arr[right])
		{
			if (arr[left] < arr[mid])
				return mid;
			else
				return left;
		}
		else
			return right;
	}
	else//left>right
	{
		if (arr[mid] < arr[right])
		{
			return right;
		}
		else if (arr[mid] < arr[left])//mid>right
		{
			return mid;
		}
		else //mid>left>right
			return left;
	}
}
int _QuickSort_1(int* arr, int left, int right)//快速排序1
{
	int key = arr[right];
	int index = right;
	while (left<right)
	{
		while (left<right && arr[left]<=key)
		{
			++left;
		}
		while (left<right && arr[right] >= key)
		{
			--right;
		}
		Swap(&arr[left], &arr[right]);
	}
	//if (arr[left] > key)//需要判断
	//{
		Swap(&arr[left], &arr[index]);
	//}
	return left;
}

void QuickSort_1(int* arr, int left, int right)
{
	if (left >= right)//递归终止条件，因为div传进来时候可能为0；所以有left>right的可能
		return;
	//if (right - left < 10)//减少递归的深度
	//	InsertSort(arr, right - left);
	//else
	//{
		int div = _QuickSort_1(arr, left, right);

		QuickSort_1(arr, left, div - 1);
		QuickSort_1(arr, div + 1, right);
	//}
}

int _QuickSort_2(int* arr, int left, int right)//挖坑法适用三数取中
{
	int index=TreeCatchMid(arr, left, right);
	Swap(&arr[index], &arr[right]);
	int key = arr[right];
	while (left < right)
	{
		while (left < right && arr[left] <= key)
		{
			++left;
		}
		arr[right] = arr[left];
		while (left < right && arr[right] >= key)
		{
			--right;
		}
		arr[left] = arr[right];
	}

	arr[right] = key;
	return right;
}

void QuickSort_2(int* arr, int left, int right)
{
	if (left >= right)//递归终止条件，因为div传进来时候可能为0；所以有left>right的可能
		return;

	int div = _QuickSort_2(arr, left, right);

	QuickSort_2(arr, left, div - 1);
	QuickSort_2(arr, div + 1, right);
}

int _QuickSort_3(int* arr, int left,int right)
{
	int cur = left;
	int prev = cur - 1;
	int key = arr[right];
	while (cur < right)
	{
		while (arr[cur] < key&&arr[++prev] != arr[cur])
		{
			Swap(&arr[cur], &arr[prev]);
		}
		++cur;
	}
	++prev;
	Swap(&arr[prev], &arr[right]);
	return prev;
}

void QuickSort_3(int* arr, int left,int right)
{
	if (left >= right)//递归终止条件，因为div传进来时候可能为0；所以有left>right的可能
		return;

	int div = _QuickSort_3(arr, left, right);

	QuickSort_3(arr, left, div - 1);
	QuickSort_3(arr, div + 1, right);
}

void QuickSortNR(int* arr, int left, int right)//非递归快速排序，用栈
{
	//1、建栈，存放左右下标
	Stack s;
	StackInit(&s);
	StackPush(&s, left);
	StackPush(&s, right);
	while (!StackEmpty(&s))
	{
		int end = StackTop(&s);
		StackPop(&s);

		int begin = StackTop(&s);
		StackPop(&s);

		int div = _QuickSort_3(arr, begin, end);

		//2、不断压栈
		if (begin < div - 1)
		{
			StackPush(&s, begin);
			StackPush(&s, div - 1);
		}
		if (end > div + 1)
		{
			StackPush(&s, div + 1);
			StackPush(&s, end);
		}
	}
}

void _MergeSort(int* arr, int left,int right,int* tmp)
{
	if (left == right)
		return;
	int begin = left;
	int end = right;
	int mid = left + (right - left) / 2;
	_MergeSort(arr, left, mid, tmp);
	_MergeSort(arr, mid+1, right, tmp);

	int begin1 = left;
	int end1 = mid;
	int begin2 = mid+1;
	int end2 = right;
	int index = left;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (arr[begin1] < arr[begin2])
		{
			tmp[left] = arr[begin1];
			begin1++;
			left++;
		}
		else
		{
			tmp[left] = arr[begin2];
			begin2++;
			left++;
		}
	}

	while (begin1 <= end1)
	{
		tmp[left] = arr[begin1];
		begin1++;
		left++;
	}
	while (begin2 <= end2)
	{
		tmp[left] = arr[begin2];
		begin2++;
		left++;
	}

	memcpy(&arr[index], &tmp[index], (right - index + 1)*sizeof(int));
}

void MergeSort(int* arr, int n)//归并排序
{
	int* tmp = (int*)malloc(sizeof(int)*n);
	int left = 0;
	int right = n - 1;
	_MergeSort(arr, left, right, tmp);
	free(tmp);
}

void PrintSort(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main()
{
	int arr[10] = { 6, 4, 0, 1, 7, 3, 2, 9, 5, 8};
	//InsertSort(arr, 10);
	//SelectSort(arr, 10);
	//ShellSort(arr, 10);
	//HeapSort(arr, 10);
	//BubbleSort(arr, 10);
	//QuickSort_3(arr, 0, 9);
	//QuickSortNR(arr, 0, 9);
	MergeSort(arr, 10);
	PrintSort(arr, 10);
}