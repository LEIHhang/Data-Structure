#include"Slist.h"
void SlistInit(Slist* pl)
{
	assert(pl);
	pl->_head = NULL;
}
Node* CreatSlistNode(SDataType data) 
{
	Node* NewNode = (Node*)malloc(sizeof(Node));
	if (NewNode == NULL)
	{
		assert(0);
		return;
	}
	NewNode->data = data;
	NewNode->pNext = NULL;
	return NewNode;
}
void SlistPushBack(Slist* pl, SDataType data)
{
	Node* NewNode = NULL;
	Node* pur = NULL;
	assert(pl);
	NewNode = CreatSlistNode(data);
	pur = pl->_head;
	if (pl->_head == NULL)
	{
		pl->_head = NewNode;
	}
	else
	{
		while (pur->pNext)
		{
			pur = pur->pNext;
		}
		pur->pNext = NewNode;
	}
}
void SlistPushFront(Slist* pl, SDataType data)
{
	Node* NewNode = NULL;
	NewNode = CreatSlistNode(data);
	assert(pl);
	NewNode->pNext = pl->_head;
	pl->_head = NewNode;
}
void SlistDelBack(Slist* pl)
{
	Node* pur;
	assert(pl);
	pur = pl->_head;
	if (pl->_head == NULL)
	{
		printf("��Ԫ�ؿ�ɾ");
		return;
	}
	else if (pur->pNext == NULL)
	{
		free(pur);
		pl->_head = NULL;
	}
	else
	{
		while (pur->pNext->pNext)
		{
			pur = pur->pNext;
		}
		free(pur->pNext);//���ͷſռ�
		pur->pNext = NULL;//�ٽ�Ұָ���ÿ�
	}

}
void SlistDelFront(Slist* pl)
{
	if (pl->_head == NULL)
	{
		printf("��Ԫ�ؿ�ɾ��");
	}
	else
	{
		Node* Temp = pl->_head->pNext;
		free(pl->_head);
		pl->_head = Temp;
	}
}
Node* SListFind(Slist* pl, SDataType x)//����ĳ��x��λ��
{
	Node* cur = pl->_head;
	if (pl->_head == NULL)
		return;
	while (cur)
	{
		if (cur->data == x)
		{
			return cur;
		}
		else
		{
			cur = cur->pNext;
		}
	}
	return NULL;
}
void SListInsertAfter(Node* pos, SDataType x) // ��pos�ĺ�����в��� 
{
	Node* NewNode = CreatSlistNode(x);
	NewNode->pNext = pos->pNext;
	pos->pNext = NewNode;
}
void SListEraseAfter(Node* pos)
{
	if (pos->pNext == NULL)
		return;
	else
	{
		Node* Temp = pos->pNext->pNext;
		free(pos->pNext);
		pos->pNext = Temp;
	}
}
void SlistPrint(Slist* pl)
{
	Node* cur = pl->_head;
	while (cur)
	{
		printf("%d->", cur->data);
		cur = cur->pNext;
	}
	printf("NULL\n");
}
int SListEmpty(Slist* pl)//����
{
	return pl->_head == NULL;//Ϊ�շ���1
}
int SListSize(Slist* pl)//�жϳ�
{
	int count = 0;
	if (pl->_head == NULL)
		return 0;
	else
	{
		Node* cur = pl->_head;
		while (cur)
		{
			count++;
			cur = cur->pNext;
		}
		return count;
	}
}
void SListRemove(Slist* pl, SDataType x)//ɾ��x
{
	if (pl->_head == NULL)
		return;
	else
	{
		Node* PreNode;
		Node* cur = pl->_head;
		if (pl->_head->data == x)
		{
			Node* temp = pl->_head->pNext;
			free(pl->_head);
			pl->_head = temp;
			return;
		}
		while (cur!=NULL)
		{
			if (cur->data == x)
			{
				Node* temp = cur->pNext;
				free(cur);
				PreNode->pNext = temp;
				return;
			}
			PreNode = cur;
			cur = cur->pNext;
		}
		return;
	}

}
void SListRemoveAll(Slist* pl, SDataType x)//ɾ������x
{
	if (pl->_head == NULL)
		return;
	else
	{
		while(pl->_head->data == x)
		{
			Node* temp = pl->_head->pNext;
			free(pl->_head);
			pl->_head = temp;
		}
		Node* PreNode;
		Node* cur = pl->_head->pNext;
		while (cur != NULL)
		{
			while (cur != NULL&&cur->data == x)//���ж��Ƿ�Ϊ��
			{
				Node* temp = cur->pNext;
				free(cur);
				PreNode->pNext = temp;
				cur = temp;
			}
			if (cur == NULL)
				return;
			PreNode = cur;
			cur = cur->pNext;
		}
		return;
	}

}