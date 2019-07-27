#include"Sort.h"

void InsertSort(int* arr, int n)//��������
{
	int i = 0;
	int j = 0;
	for (i = 1; i <= n - 1; i++)
	{
		int temp = arr[i];//ȡ�ڶ���Ԫ�ؿ�ʼ�Ƚ�
		for (j = i - 1; j >= 0; j--)
		{
			if (temp < arr[j])
			{
				arr[j + 1] = arr[j];//�����һ��Ԫ�رȽϣ���С�Ļ������ƶ���λ
			}
			else
				break;
		}
		//��Ϊ���һ��j--�ˣ�����û���ƶ�
		//��������jҪ��һ
		arr[j + 1] = temp;
	}
}
void ShellSort(int* arr, int n)//ϣ������
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
void SelectSort(int* arr, int n)//ѡ������
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

void HeapSort(int* a, int size)//������//����
{
	//1���Ƚ�һ�����(���������
	for (int i = size / 2 - 1; i >= 0; i--)
	{
		AdjustDown(a, size, i);//���µ���,n���±�
	}
	int end = size - 1;
	//2��ÿ����Ѷ��Ͷ�βԪ�ؽ���
 	while (end>0)
	{
		Swap(&a[0], &a[end]);
		//3�����µ������ı����鷶Χ
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
int TreeCatchMid(int* arr, int left, int right)//����ȡ��
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
int _QuickSort_1(int* arr, int left, int right)//��������1
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
	//if (arr[left] > key)//��Ҫ�ж�
	//{
		Swap(&arr[left], &arr[index]);
	//}
	return left;
}

void QuickSort_1(int* arr, int left, int right)
{
	if (left >= right)//�ݹ���ֹ��������Ϊdiv������ʱ�����Ϊ0��������left>right�Ŀ���
		return;
	//if (right - left < 10)//���ٵݹ�����
	//	InsertSort(arr, right - left);
	//else
	//{
		int div = _QuickSort_1(arr, left, right);

		QuickSort_1(arr, left, div - 1);
		QuickSort_1(arr, div + 1, right);
	//}
}

int _QuickSort_2(int* arr, int left, int right)//�ڿӷ���������ȡ��
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
	if (left >= right)//�ݹ���ֹ��������Ϊdiv������ʱ�����Ϊ0��������left>right�Ŀ���
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
	if (left >= right)//�ݹ���ֹ��������Ϊdiv������ʱ�����Ϊ0��������left>right�Ŀ���
		return;

	int div = _QuickSort_3(arr, left, right);

	QuickSort_3(arr, left, div - 1);
	QuickSort_3(arr, div + 1, right);
}

void QuickSortNR(int* arr, int left, int right)//�ǵݹ����������ջ
{
	//1����ջ����������±�
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

		//2������ѹջ
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

void MergeSort(int* arr, int n)//�鲢����
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