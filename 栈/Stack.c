#include"Stack.h"
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
		ps->a=(STDataType*)realloc(ps->a, sizeof(STDataType)*newspace);
		//��realloc�У���ַΪ�����malloc�÷���ͬ
	}
	ps->a[ps->top] = x;
	ps->top++;
}
void StackPop(Stack* ps) //ɾ��
{
	assert(ps && ps->top!=0);
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

