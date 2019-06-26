#define _CRT_SECURE_NO_WARNINGS 1 

#include "SeqList.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
void SeqListInit(SeqList *ps)//��ʼ������
{
	assert(ps);
	ps->_array = NULL;
	ps->_size = 0;
	ps->_capacity = 0;

}
void SeqListDestory(SeqList* ps)// �ͷ�����
{
	assert(ps);
	if (ps->_array)
	{
		free(ps->_array);
		ps->_array = NULL;
	}
	ps->_size = ps->_capacity = 0;

}
void SeqListCheckCapacity(SeqList* ps)
{
	assert(ps);

	if (ps->_array == ps->_capacity)
	{
		size_t newcapacity = ps->_capacity == 0 ? 4 : ps->_capacity * 2;
		ps->_array = realloc(ps->_array, sizeof(DataType)*newcapacity);
		ps->_capacity = newcapacity;
	}
}
void SeqListPushBack(SeqList* ps, DataType x)// β��
{
	assert(ps);
	SeqListCheckCapacity(ps);
	ps->_array[ps->_size] = x;
	ps->_size++;

}
void SeqListPushFront(SeqList* ps, DataType x)//ǰ��
{
	assert(ps);              // 0 1 2 3 4 5 6
	SeqListCheckCapacity(ps);// 1 2 3 4 5 6 7
	size_t end = ps->_size;
	while (end > 0)
	{
		ps->_array[end] = ps->_array[end - 1];
		end--;
	}
	ps->_array[0] = x;
	ps->_size++;
}
void SeqListPopBack(SeqList* ps)//βɾ
{
	assert(ps);

	ps->_size--;
}
void SeqListPopFront(SeqList* ps)//ǰɾ
{
	assert(ps);
	size_t end = ps->_size;
	size_t start = 0;
	while (end > 0)
	{
		ps->_array[start] = ps->_array[start + 1];
		--end;
	}
	ps->_size--;
}

void SeqListInsert(SeqList* ps, size_t pos, DataType x)//����
{
	assert(ps);
	SeqListCheckCapacity(ps);

	size_t start = pos + 1;
	while (start < ps->_size)
	{                                         // 0 1 2 3 4 5
		ps->_array[start] = ps->_array[start - 1];// 1 2 3 4 4 3
		start++;
	}
	ps->_array[pos] = x;
	ps->_size++;

}
void SeqListErease(SeqList* ps, size_t pos)//�ͷ�
{
	assert(ps);
	size_t start = pos;
	size_t count = ps->_size - pos;
	while (count>0)
	{
		ps->_array[start] = ps->_array[start + 1];
		count--;
		start++;
	}
	ps->_size--;
}
size_t SeqListSize(SeqList *ps)//�����С
{
	assert(ps);
	return ps->_size;

}
size_t SeqListFind(SeqList* ps, DataType x) //���������ֵ
{
	assert(ps);
	for (size_t i = 0; i < ps->_size; i++)
	{
		if (ps->_array[i] == x)
		{
			return i;
		}
	}
	return -1;

}
DataType SeqListAt(SeqList* ps, size_t pos)//��λ�������ĳһԪ��
{
	assert(ps);
	return ps->_array[pos];
}