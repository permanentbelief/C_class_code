#define _CRT_SECURE_NO_WARNINGS 1 
#include <stdio.h>
#include <string.h>
#include <assert.h>
//��Ŀһ
//int main()
//{
//	int aa[2][5] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int *ptr1 = (int*)(&aa + 1);//&aa������aa������ĵ�ַ +1�ӵ���һ������Ĵ�С���ӵ�10����һλ
//	int *ptr2 = (int*)(*(aa + 1));//aa����Ԫ�صĵ�ַ,��һ�С�+1 ��һ���� ������ݵĴ�С
//	printf("%d,%d", *(ptr1 - 1), *(ptr2 - 1));//10 
//	system("pause");
//	return 0;
//	//����ָ�� (*(aa+1)) aa������ָ�� ������Ϊһ��������Ԫ�ص�ֵ����ǿתΪint*
//  !!!!!!!!!!!!!!!!!!!!!!!!�Ӳ�������ν����
//}
//��Ŀ����
//int main()
//{
//	char* a[] = { "work", "at", "alibaba" };
//	char**pa = a;
//	pa++;
//	printf("%s\n", *pa);
//	system("pause");
//}
//��Ŀ��
int main()
{
	char*c[] = { "enter", "new", "point", "first" };
	char**cp[] = { c + 3,  c + 2, c + 1, c };
	char***cpp = cp;
	printf("%s\n", **++cpp);
	printf("%s\n", *--*++cpp + 3);
	printf("%s\n", *cpp[-2] + 3);
	printf("%s\n", cpp[-1][-1] + 1);
	system("pause");
}
//int main()
//{
//	char* str1 = "hello";
//	printf("%d\n", strlen(str1));//5//�ִ��ˣ���'\0'����������'/0'
//	printf("%d\n", sizeof(str1));//4
//	char str2[] = "hello";
//	printf("%d\n", strlen(str2));//5
//	printf("%d\n", sizeof(str2));//���⣬sizeof(������)��ʾ��������Ĵ�С���Ҽ���'\0��
//	char str3[] = "abcde\0gh\0";
//	printf("%d\n", strlen(str3));//5 ��ȡ��\0����
//	printf("%d\n", sizeof(str3));//10 �������һ��'\0��
//	char str4[] = "abcde\\0gh\\\0";
//	printf("%d\n", strlen(str4));//10 //����\0����\\��ת���ַ����һ��
//	printf("%d\n", sizeof(str4));//12
//	char str5[] = "abcde\\0gh\t\n\r";
//	printf("%d\n", strlen(str5));//12
//	printf("%d\n", sizeof(str5));//13
//
//
//	system("pause");
//}
//����һ
//int my_strlen(const char* str)
//{
//	assert(str);
//	size_t count = 0;
//	while (*str != '\0')
//	{
//		count++;
//		str++;
//	}
//	return count;
//}
//������
//int my_strlen(const char*str)
//{
//	if (*str == '\0')
//		return 0;
//	return 1 + my_strlen(++str);
//
//}
//��������
//int my_strlen(const char * str)
//{
//	assert(str);
//	const char* end = str;
//	while (*++end);//1.���ȼ�++ > * 2.�����end++�����ȡһλ��end+1,���ص�end�ж�*end�Ƿ�Ϊ'
//	//\0 ,��Ϊ'\0����ִ������while������ʱ��end�Ѿ���\0���ȡһλ
//	return end - str;
//}
//int main()
//{
//	printf("%d", my_strlen("adada"));
//	system("pause");
//}
//����һ
//char * my_strcpy(char* dst, const char * src)
//{
//	assert(dst&&src);
//	char * ret = dst;
//	while (*dst++ = *src++);
//	return ret;
//}
//������ ��ô���� ����������
//char* my_strcpy(char*dst, const char *src)
//{
//	assert(dst && src);
//	char * ret = dst;
//	while (*src != '\0')
//	{
//		*dst = *src;
//		++src;
//		++dst;
//	}
//	*dst = *src;
//	return ret;
//}
//int main()
//{
//	char str1[] = "";
//	char str2[] = "bir";
//	printf("%s", my_strcpy(str1, str2));
//	system("pause");
//}
//char * my_strcat(char *dst, const char*src)
//{
//	assert(dst && src);
//	char * ret = dst;
//	while (*dst++ != '\0');
//	--dst;
//	while (*dst++ = *src++);
//	return ret;
//}
//������
//char *my_strcat(char *dst, const char*src)
//{
//	assert(dst&&src);
//	
//	//char * ret = dst;
//	size_t count = 0;
//	while (dst[count])
//	{
//		count++;
//	
//	}
//	dst += count;//����dst��ʲô����һ��ֵʲô��˼��
//	while (*dst++ = *src++);
//
//	return dst;
//}
//int main()
//{
//	/*char  str1[15] = "abcd";
//	char  str2[15] = "efg";*/
//	char a1[15] = "hello";
//	my_strcat(a1, "world");
//	printf("%s",a1 );
//	system("pause");
//}
//int my_strcmp(const char*str1, const char*str2)
//{
//	assert(str1&&str2);
//	while (*str1 != '\0'&&*str2 != '\0')
//	{
//		if (*str1 > *str2)
//		{
//			return 1;
//		}
//		if (*str1 < *str2)
//		{
//			return -1;
//		}
//		else
//		{
//			str1++;
//			str2++;
//		}
//	}
//	if (*str1 == '\0'&& *str2 !='\0')
//	{
//		return -1;
//	}
//	if (*str2 == '\0'&& *str1 != '\0')
//	{
//		return 1;
//	}
//	else
//	{
//		return 0;
//	}
//
//}
//int main()
//{
//	char arr1[] = "abd";
//	char arr2[] = "abc";
//	printf("%d", my_strcmp(arr1, arr2));
//	system("pause");
//}