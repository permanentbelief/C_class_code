#define _CRT_SECURE_NO_WARNINGS 1 
#include "SeqList.h"

void TestSeqList1()
{
	SeqList s1;
	SeqListInit(&s1);//动态开辟空间 存在内存泄漏的危险

	//SeqListPushBack(&s1, 1);
	/*SeqListPushBack(&s1, 2);
	SeqListPushBack(&s1, 3);
	SeqListPushBack(&s1, 4);*/
	//SeqListPushBack(&s1, 5);
	SeqListPushFront(&s1, 6);
	//SeqListPopBack(&s1);
	//SeqListPopBack(&s1);
	SeqListPushFront(&s1, 7);
	SeqListPushFront(&s1, 8);
	SeqListPushFront(&s1, 9);
	SeqListPushFront(&s1, 10);
	SeqListPushFront(&s1, 11);
	SeqListErease(&s1, 3);
	size_t n = SeqListFind(&s1, 9);
	printf("%u\n", n);

	//SeqListErease(&s1, 0);
	//SeqListPopFront(&s1);
	for (size_t i = 0; i < SeqListSize(&s1); i++)
	{
		printf("%d ", SeqListAt(&s1, i));
	}

}
int main()
{
	TestSeqList1();
	system("pause");
	return 0;
}