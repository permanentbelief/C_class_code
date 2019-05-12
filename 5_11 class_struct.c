#define _CRT_SECURE_NO_WARNINGS 1 
#include <stdio.h>
#include <assert.h>
//memset的实现 为什么不能用这种方式实现
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
// memcpy 的正确使用方法
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
//mem_memmove 的实现
//void* my_memmove(void *str, const void * src, size_t size)
//{
//	assert(str&&src);
//	char* ch_str = (char*)str;
//	const char* ch_src = (const char*)src;
//	if (ch_src < ch_str && ch_str < ch_src + size)
//	{
//		//从后向前 拷贝
//		for (int i = size-1; i >= 0; i--)
//		{
//			ch_str[i] = ch_src[i];
//		}
//	}
//	else
//	{ 
//		// 从前往后拷贝
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
//	char _tel[15];//声明
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
// 匿名
//struct
//{
//	int a;
//	char b;
//	float c;
//}x; //只能用这里的x变量
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

//内存对齐
// 内存对其规则
//1. 第一个成员在于结构体偏移量为0的地址处
//2  其它成员变量要对齐到某个数字（对齐数）的整数倍地址处
//对齐数= 编译器默认的对齐数 与 该成员大小的较小值。 VS 中默认为8
//3. 结构体总大小为最大对齐数（每个成员都有一个对齐数）的整数倍
//4. 如果嵌套了结构体的情况，嵌套的结构体对齐到自己的最大对齐数的整数倍处，
//结构体的整体大小就是所有最大对齐数（含嵌套结构体的对齐数）的整数倍。
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
//	char c1;  // c1(1)c2(1)[2]ci(4)  8是最大对齐数4的倍数 所以为8
//	char c2;
//	int i;
//};
//struct S3
//{
//	double d;  //d(8)c(1)[3]i(4) //16 是最大对齐数 8的倍数
//	char c;
//	int i;
//};
//struct S4
//{
//	char c1;   // c1(1)[7]s3(16)d(4)   28不是8的倍数 扩大到32
//	struct S3 s3;
//	double d;
//};
//#pragma pack()//取消设置的默认对齐数，还原成默认
//#progma pack(1)//设置默认对齐数为8
//int main()
//{
//	printf("%d\n", sizeof(struct S1));
//	printf("%d\n", sizeof(struct S2));
//	printf("%d\n", sizeof(struct S3));
//	printf("%d\n", sizeof(struct S4));
//
//	system("pause");
//}
//结构体传参
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
//	print1(s); //传结构体
//	print2(&s);//传地址
//	system("pause");
//}
// 位段
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