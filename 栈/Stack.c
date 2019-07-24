#include"Stack.h"
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
		ps->a=(STDataType*)realloc(ps->a, sizeof(STDataType)*newspace);
		//当realloc中，地址为空则和malloc用法相同
	}
	ps->a[ps->top] = x;
	ps->top++;
}
void StackPop(Stack* ps) //删除
{
	assert(ps && ps->top!=0);
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

