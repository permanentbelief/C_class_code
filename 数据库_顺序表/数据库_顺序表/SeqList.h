#pragma once
#include <stdio.h>
#include <assert.h>
#define N 100
typedef int DataType;
typedef struct SeqList //  ����
{
	DataType* _array;// ��������
	size_t _size;// �����С
	size_t _capacity;// �����ݻ�
}SeqList;

void SeqListInit(SeqList* ps);//��ʼ������
void SeqListDestory(SeqList* ps);//��������
void SeqListPushBack(SeqList* ps, DataType x);// β��
void SeqListPushFront(SeqList* ps, DataType x);//ǰ��
void SeqListPopBack(SeqList* ps);//βɾ
void SeqListPopFront(SeqList* ps);//ǰɾ
void SeqListInsert(SeqList* ps, size_t pos, DataType x);//����
void SeqListErase(SeqList* ps, size_t pos);//�ͷ�
size_t SeqListSize(SeqList *ps);//�����С
size_t SeqListFind(SeqList* ps, DataType x);//���������ĳһ��ֵ
DataType SeqListAt(SeqList* ps, size_t pos);//��λ�������ĳһԪ��