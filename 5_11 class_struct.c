#define _CRT_SECURE_NO_WARNINGS 1 
#include <stdio.h>
#include <assert.h>
//memset��ʵ�� Ϊʲô���������ַ�ʽʵ��
//void* my_memset(void * dst, const void * src, size_t num)
//{
//	assert(dst&&src);
//	char* _src = ( char*)src;
//	char* _dst = (char*)dst;
//	for (size_t i = 0; i < num; i++)
//	{
//		*dst = *src;
//		_src++;
//		_dst++;
//	}
//	return _src;
//}
// memcpy ����ȷʹ�÷���
//void *my_memcpy(void* dst, const void* src, size_t size)
//{
//	assert(dst&&src);
//	char* ch_dst = (char*)dst;
//	const char* ch_src = (const char*)src;
//	for (size_t i = 0; i < size; ++i)
//	{
//		ch_dst[i] = ch_src[i];
//	}
//	return dst;
//}
//int main()
//{
//	char arr1[6] = "abcde";
//	char arr2[] = "ddadada";
//	printf("%s", my_memcpy(arr1, arr2, sizeof(arr2)*sizeof(char)));
//	system("pause");
//}
//mem_memmove ��ʵ��
//void* my_memmove(void *str, const void * src, size_t size)
//{
//	assert(str&&src);
//	char* ch_str = (char*)str;
//	const char* ch_src = (const char*)src;
//	if (ch_src < ch_str && ch_str < ch_src + size)
//	{
//		//�Ӻ���ǰ ����
//		for (int i = size-1; i >= 0; i--)
//		{
//			ch_str[i] = ch_src[i];
//		}
//	}
//	else
//	{ 
//		// ��ǰ���󿽱�
//		for (int i = 0; i < size; i++)
//		{
//			ch_str[i] = ch_src[i];
//		}
//	}
//	return str;
//
//}
//int main()
//{
//	int a1[10] = { 1, 2, 3, 4, 5 };
//	int a2[10] = { 1, 2, 3, 4, 5 };
//	my_memmove(a2 + 3, a2, 5 * sizeof(int));
//}
//struct Student
//{
//	char _name[20];
//	int _age;
//	char _tel[15];//����
//}stu3, stu4, stu5;
//int main()
//{
//	struct Student stu1;
//	strcpy(stu1._name, "peter");
//	stu1._age = 16;
//	strcpy(stu1._tel, "23681631");
//
//	struct Student stu2;
//	memcpy(&stu2, &stu1, sizeof(struct Student));
//
//}
// ����
//struct
//{
//	int a;
//	char b;
//	float c;
//}x; //ֻ���������x����
//int main()
//{
//	x.a = 10;
//
//}
//struct
//{
//	int a;
//	char b;
//	float c;
//}a[20], *p;
//
//typedef struct ListNode
//{
//	int _data;
//	struct ListNode* _node;
//}ListNode;
//int main()
//{
//	ListNode node = { 10, NULL };
//	return 0;
//}

//�ڴ����
// �ڴ�������
//1. ��һ����Ա���ڽṹ��ƫ����Ϊ0�ĵ�ַ��
//2  ������Ա����Ҫ���뵽ĳ�����֣�������������������ַ��
//������= ������Ĭ�ϵĶ����� �� �ó�Ա��С�Ľ�Сֵ�� VS ��Ĭ��Ϊ8
//3. �ṹ���ܴ�СΪ����������ÿ����Ա����һ������������������
//4. ���Ƕ���˽ṹ��������Ƕ�׵Ľṹ����뵽�Լ�����������������������
//�ṹ��������С��������������������Ƕ�׽ṹ��Ķ�����������������
//
//
//struct S1
//{
//	char c1; // c1(1)[3]ci(4)c2(1)
//	int i;
//	char c2;
//};
//struct S2
//{
//	char c1;  // c1(1)c2(1)[2]ci(4)  8����������4�ı��� ����Ϊ8
//	char c2;
//	int i;
//};
//struct S3
//{
//	double d;  //d(8)c(1)[3]i(4) //16 ���������� 8�ı���
//	char c;
//	int i;
//};
//struct S4
//{
//	char c1;   // c1(1)[7]s3(16)d(4)   28����8�ı��� ����32
//	struct S3 s3;
//	double d;
//};
//#pragma pack()//ȡ�����õ�Ĭ�϶���������ԭ��Ĭ��
//#progma pack(1)//����Ĭ�϶�����Ϊ8
//int main()
//{
//	printf("%d\n", sizeof(struct S1));
//	printf("%d\n", sizeof(struct S2));
//	printf("%d\n", sizeof(struct S3));
//	printf("%d\n", sizeof(struct S4));
//
//	system("pause");
//}
//�ṹ�崫��
//struct S
//{
//	int data[1000];
//	int num;
//};
//struct S s = { { 1, 2, 3, 4 }, 1000 };
//void print1(struct S s)
//{
//	printf("%d\n", s.num);
//}
//void print2(struct S * ps)
//{
//	printf("%d\n", ps->num);
//}
//int main()
//{
//	print1(s); //���ṹ��
//	print2(&s);//����ַ
//	system("pause");
//}
// λ��
struct A
{
	int _a : 2;
	int _b : 5;
	int _c : 10;
	int _d : 30;
};
int main()
{
	printf("%d\n", sizeof(struct A));
	system("pause");
}