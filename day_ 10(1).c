#define _CRT_SECURE_NO_WARNINGS 1 
#include <stdio.h>

//1.
//写一个函数返回参数二进制中 1 的个数
//比如： 15 0000 1111 4 个 1
//程序原型：
//int count_one_bits(unsigned int value)
//{
//	// 返回 1的位数 
//}
//int count_one_bits(unsigned int value)
//{
//	size_t i = 0;
//	int count = 0;
//	for (i = 0; i < 32; i++)
//	{
//		if (value%2 == 1)
//		{
//			count++;
//		}
//		value= value>>1 ;
//	}
//	return count;
//}
//int main()
//{
//	int a = 0;
//	scanf("%d", &a);
//	printf("%d\n", count_one_bits(a));
//	system("pause");
//}
//2.获取一个数二进制序列中所有的偶数位和奇数位，
//分别输出二进制序列。
//int main()
//{
//	int a = 7;
//	size_t i = 0;
//	int odd[16] = { 0 };
//	int even[16] = { 0 };
//	size_t k = 0;
//	size_t j = 0;
//	for (i = 0; i < 32; i++)
//	{
//		
//		if (i % 2 == 0)
//		{
//
//			odd[k] = a % 2;
//			k++;
//		}
//		if (i % 2 == 1)
//		{
//			even[j] = a % 2;
//			j++;
//		}
//		a = a >> 1;
//	}
//	for (int i =15; i >= 0; i--)
//	{
//		printf("%d ", odd[i]);
//
//	}
//	printf("\n");
//	for (int i = 15; i >= 0; i--)
//	{
//		printf("%d ", even[i]);
//
//	}
//	system("pause");
//}
//3. 输出一个整数的每一位。
//int main()
//{
//	int a = 999;
//	while (a > 0)
//	{
//	 printf("%d ", a % 10);
//	 a = a / 10;
//	}
//	system("pause");
//}
//4.编程实现：
//两个int（32位）整数m和n的二进制表达中，有多少个位(bit)不同？
//输入例子 :
//1999 2299
//输出例子 : 7
int main()
{
	int m = 1999;
	int n = 2299;
	size_t i = 0;
	size_t count = 0;
	for (i = 0; i < 32; i++)
	{
		if ((m >> i) % 2 != (n >> i) % 2)
		{
			count++;
		}
	}
	printf("%d", count);
	system("pause");
}