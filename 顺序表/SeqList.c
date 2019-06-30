#include"SeqList.h"
#include<assert.h>
#include<malloc.h>

void SeqListInit(SeqList* ps)//初始化函数
{
	assert(ps);
	ps->arr = (DateType*)malloc(sizeof(DateType) * 4);
	ps->size = 0;
	ps->capacity = 4;
}
void SeqListCheck(SeqList* ps)//检查容量函数，不够扩容
{
	assert(ps);
	if (ps->capacity == ps->size)
	{
		ps->arr = (DateType*)realloc(ps->arr, ps->capacity * 2 * sizeof(DateType));
		ps->capacity *= 2;
	}
}
void SeqListDestory(SeqList* ps)//删除函数
{
	assert(ps);
	free(ps->arr);
	ps->size = 0;
	ps->capacity = 0;
	ps->arr = NULL;
}
void SeqListPushBack(SeqList* ps, DateType x)//尾插
{
	assert(ps);
	SeqListCheck(ps);
	size_t end = ps->size;
	ps->arr[end] = x;
	ps->size++;
}
void SeqListPushFront(SeqList* ps, DateType x)//头插
{
	assert(ps);
	SeqListCheck(ps);
	size_t end = ps->size;
	for (; 1<= end; end--)
	{
		ps->arr[end] = ps->arr[end - 1];
	}
	ps->arr[0] = x;
	ps->size++;
}
void SeqListPrint(SeqList* ps)//打印
{
	assert(ps);
	for (size_t i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->arr[i]);
	}
	printf("\n");
}
void SeqListPopBack(SeqList* ps)//尾删
{
	assert(ps);
	ps->size -= 1;
}
void SeqListPopFront(SeqList* ps)//头删
{
	assert(ps);
	size_t start = 1;
	size_t end = ps->size;
	for (; start < end; start++)
	{
		ps->arr[start-1] = ps->arr[start];
	}
	ps->size--;
}
void SeqListInsert(SeqList* ps, size_t pos, DateType x)//指定位置插入
{
	assert(ps && pos<(ps->size));
	SeqListCheck(ps);
	size_t end = ps->size;
	for (; pos < end; end--)
	{
		ps->arr[end] = ps->arr[end - 1];
	}
	ps->arr[pos] = x;
	ps->size++;
}
void SeqListErase(SeqList* ps, size_t pos)//指定位置删除
{
	assert(ps && pos < (ps->size));
	size_t start = pos + 1;
	size_t end = ps->size;
	for (; start < end; start++)
	{
		ps->arr[start - 1] = ps->arr[start];
	}
	ps->size--;
}
size_t SeqListFind(SeqList* ps, DateType x)//查找x的位置
{
	assert(ps);
	for (size_t start = 0; start < ps->size; start++)
	{
		if (ps->arr[start] == x)
		{
			return start;
		}
	}
	return -1;
}
DateType SeqListAT(SeqList* ps, size_t pos)//查找当前位置的值
{
	assert(ps && pos<(ps->size));
	return ps->arr[pos];
}
void SeqListBubbleSort(SeqList* ps)//冒泡排序
{
	assert(ps);
	size_t times = ps->size;
	while (--times && times>0)
	{
		for (size_t start = 0; start < times; start++)
		{
			if (ps->arr[start] > ps->arr[start + 1])
			{
				DateType temp = ps->arr[start];
				ps->arr[start] = ps->arr[start + 1];
				ps->arr[start + 1] = temp;
			}
		}
	}
}
void menu()//菜单函数
{
	printf("\t\t\t\t************************************\n");
	printf("\t\t\t\t1、头插-----------------------2、尾插\n");
	printf("\t\t\t\t3、删头-----------------------4、删尾\n");
	printf("\t\t\t\t5、指定位置插入---------------6、指定位置删除\n");
	printf("\t\t\t\t7、排序-----------------------8、查找\n");
	printf("\t\t\t\t9、打印-----------------------10、删除\n");
	printf("\t\t\t\t-------------0、退出程序--------------\n");
	printf("\t\t\t\t************************************\n");
}
void choose()//选择函数
{
	SeqList s;
	SeqListInit(&s);
	while (1)
	{
		menu();
		int n;//输入选择
		scanf("%d", &n);
		switch (n)
		{
		case 0:
			exit(-1);
			break;
		case 1:
		{
			DateType x;
			printf("请输入要插入的值：");
			scanf("%d", &x);
			SeqListPushFront(&s, x);
			break;
		}
		case 2:
		{
			DateType x;
			printf("请输入要插入的值：");
			scanf("%d", &x);
			SeqListPushBack(&s, x);
			break;
		}
		case 3:
		{
			SeqListPopFront(&s);
			break;
		}
		case 4:
		{
			SeqListPopBack(&s);
			break;
		}
		case 5:
		{
			int pos;
			printf("请输入要插入的位置：");
			scanf("%d", &pos);
			printf("\n");
			DateType x;
			printf("请输入要插入的值：");
			scanf("%d", &x);
			SeqListInsert(&s, pos, x);
			break;
		}
		case 6:
		{
			int pos;
			printf("请输入要删除的位置：");
			scanf("%d", &pos);
			SeqListErase(&s, pos);
			break;
		}
		case 7:
		{
			SeqListBubbleSort(&s);
			break;
		}
		case 8:
		{
			printf("/t/t/t/t1、查找列中已有的数的位置---------------2、查找某个位置的数\n");
			int n;
			scanf("%d", &n);
			switch (n)
			{
			case 1:
			{
				DateType a;
				printf("输入你想查找的数：");
				scanf("%d", &a);
				if (SeqListFind(&s, a) == -1)
					printf("没有这个数\n");
				else
					printf("这个数在第%d个位置\n", SeqListFind(&s, a));
				break;
			}
			case 2:
			{
				int a;
				printf("输入你想查找的位置：");
				scanf("%d", &a);
				printf("这个位置的值为%d\n", SeqListAT(&s, a));
				break;
			}
			}
			break;
		}
		case 9:
		{
			SeqListPrint(&s);
			break;
		}
		case 10:
		{
			SeqListDestory(&s);
			break;
		}
		default:
			printf("输入错误，请重新输入\n");
			break;
		}
	}
}






