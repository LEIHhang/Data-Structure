#include"SeqList.h"
#include<assert.h>
#include<malloc.h>

void SeqListInit(SeqList* ps)//��ʼ������
{
	assert(ps);
	ps->arr = (DateType*)malloc(sizeof(DateType) * 4);
	ps->size = 0;
	ps->capacity = 4;
}
void SeqListCheck(SeqList* ps)//���������������������
{
	assert(ps);
	if (ps->capacity == ps->size)
	{
		ps->arr = (DateType*)realloc(ps->arr, ps->capacity * 2 * sizeof(DateType));
		ps->capacity *= 2;
	}
}
void SeqListDestory(SeqList* ps)//ɾ������
{
	assert(ps);
	free(ps->arr);
	ps->size = 0;
	ps->capacity = 0;
	ps->arr = NULL;
}
void SeqListPushBack(SeqList* ps, DateType x)//β��
{
	assert(ps);
	SeqListCheck(ps);
	size_t end = ps->size;
	ps->arr[end] = x;
	ps->size++;
}
void SeqListPushFront(SeqList* ps, DateType x)//ͷ��
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
void SeqListPrint(SeqList* ps)//��ӡ
{
	assert(ps);
	for (size_t i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->arr[i]);
	}
	printf("\n");
}
void SeqListPopBack(SeqList* ps)//βɾ
{
	assert(ps);
	ps->size -= 1;
}
void SeqListPopFront(SeqList* ps)//ͷɾ
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
void SeqListInsert(SeqList* ps, size_t pos, DateType x)//ָ��λ�ò���
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
void SeqListErase(SeqList* ps, size_t pos)//ָ��λ��ɾ��
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
size_t SeqListFind(SeqList* ps, DateType x)//����x��λ��
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
DateType SeqListAT(SeqList* ps, size_t pos)//���ҵ�ǰλ�õ�ֵ
{
	assert(ps && pos<(ps->size));
	return ps->arr[pos];
}
void SeqListBubbleSort(SeqList* ps)//ð������
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
void menu()//�˵�����
{
	printf("\t\t\t\t************************************\n");
	printf("\t\t\t\t1��ͷ��-----------------------2��β��\n");
	printf("\t\t\t\t3��ɾͷ-----------------------4��ɾβ\n");
	printf("\t\t\t\t5��ָ��λ�ò���---------------6��ָ��λ��ɾ��\n");
	printf("\t\t\t\t7������-----------------------8������\n");
	printf("\t\t\t\t9����ӡ-----------------------10��ɾ��\n");
	printf("\t\t\t\t-------------0���˳�����--------------\n");
	printf("\t\t\t\t************************************\n");
}
void choose()//ѡ����
{
	SeqList s;
	SeqListInit(&s);
	while (1)
	{
		menu();
		int n;//����ѡ��
		scanf("%d", &n);
		switch (n)
		{
		case 0:
			exit(-1);
			break;
		case 1:
		{
			DateType x;
			printf("������Ҫ�����ֵ��");
			scanf("%d", &x);
			SeqListPushFront(&s, x);
			break;
		}
		case 2:
		{
			DateType x;
			printf("������Ҫ�����ֵ��");
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
			printf("������Ҫ�����λ�ã�");
			scanf("%d", &pos);
			printf("\n");
			DateType x;
			printf("������Ҫ�����ֵ��");
			scanf("%d", &x);
			SeqListInsert(&s, pos, x);
			break;
		}
		case 6:
		{
			int pos;
			printf("������Ҫɾ����λ�ã�");
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
			printf("/t/t/t/t1�������������е�����λ��---------------2������ĳ��λ�õ���\n");
			int n;
			scanf("%d", &n);
			switch (n)
			{
			case 1:
			{
				DateType a;
				printf("����������ҵ�����");
				scanf("%d", &a);
				if (SeqListFind(&s, a) == -1)
					printf("û�������\n");
				else
					printf("������ڵ�%d��λ��\n", SeqListFind(&s, a));
				break;
			}
			case 2:
			{
				int a;
				printf("����������ҵ�λ�ã�");
				scanf("%d", &a);
				printf("���λ�õ�ֵΪ%d\n", SeqListAT(&s, a));
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
			printf("�����������������\n");
			break;
		}
	}
}






