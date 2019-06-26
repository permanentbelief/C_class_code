#pragma once
#include <stdio.h>
#include <assert.h>
#define N 100
typedef int DataType;
typedef struct SeqList //  链表
{
	DataType* _array;// 链表数组
	size_t _size;// 链表大小
	size_t _capacity;// 链表容积
}SeqList;

void SeqListInit(SeqList* ps);//初始化链表
void SeqListDestory(SeqList* ps);//销毁链表
void SeqListPushBack(SeqList* ps, DataType x);// 尾插
void SeqListPushFront(SeqList* ps, DataType x);//前插
void SeqListPopBack(SeqList* ps);//尾删
void SeqListPopFront(SeqList* ps);//前删
void SeqListInsert(SeqList* ps, size_t pos, DataType x);//插入
void SeqListErase(SeqList* ps, size_t pos);//释放
size_t SeqListSize(SeqList *ps);//链表大小
size_t SeqListFind(SeqList* ps, DataType x);//查找链表的某一个值
DataType SeqListAt(SeqList* ps, size_t pos);//定位于链表的某一元素