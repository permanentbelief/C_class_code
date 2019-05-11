#define _CRT_SECURE_NO_WARNINGS 1 
#include <stdio.h>
#include <assert.h>
// 第一大类 strlen的三个实现方法 
// fang fa 1
//int my_strlen( const char* str)
//{
//	assert(str);
//	int count = 0;
//	while (*str != '\0')
//	{
//		count++;
//		str++;
//	}
//	return count;
//}
// fang fa 2
//int my_strlen(char * str)
//{
//	if (*str == 0)
//	{
//		return 0;
//	}
//	else
//		return 1 + my_strlen(str + 1);//在这里如果写str++ 会造成死循环
//}
// fang fa 3 利用的是指针的减法表示两指针之间差的数量
//int my_strlen(char * str)
//{
//	char* begin = str;
//	while (*str)
//	{
//		str++;
//	}
//	char* end = str;
//	return end - begin;
//
//}
//int main()
//{
//	char arr[] = "ab";
//	int ret = my_strlen(arr);
//	printf("%d", ret);
//	system("pause");
//}
// strcpy实现的方法
//fang fa 1
//char* my_strcpy(char* str, const char* src)
//{
//	assert(str&&src);
//	char* ret = str;
//	while (*str++ = *src++);
//	return ret;
//	
//}
// fang faf 2
//char* my_strcpy(char* dst, const char* src)
//{
//	assert(src && dst);
//	char * ret = dst;
//	while (*src != '\0')
//	{
//		*dst = *src;
//		++dst;
//		++src;
//	}
//	*dst = *src;
//	return ret;
//}
// my_strcmp 的实现方法
// fang fa 1
//int my_strcmp(const char* str1, const char *str2)
//{
//	assert(str1&&str2);
//	while (*str1&&*str2)
//	{
//		if (*(unsigned char*)str1 > *(unsigned char*)str2)
//		{
//			return 1;
//		}
//		if (*(unsigned char*)str1 < *(unsigned char*)str2)
//		{
//			return -1;
//		}
//		else
//		{
//			str1++;
//			str2++;
//		}
//	}
//	if (*str1 != '\0')
//		return 1;
//	if (*str2 != '\0')
//		return -1;
//	else
//		return 0;
//	
//}
// fang fa 2
//char* my_strcmp(const char* str1, const char* str2)
//{
//	assert(str1&&str2);
//	int ret = 0;
//	while (!(ret = *(unsigned char*)str1 - *(unsigned char*)str2) && *str2)
//		++str1; ++str2;
//	if (ret > 0)
//		return 1;
//	if (ret < 0)
//		return -1;
//	else
//		return 0;
//	
//}
//char* my_strncpy(char * str, const char* src, size_t count)
//{
//	assert(str&&src);
//	char* ret = str;
//	while (count--)
//	{
//		
//		*str++ = *src++;
//		
//	}
//	*(str) = '\0';
//	return ret;
//}
//  //TO DO
//char* my_strncat(char* dst, const char * src, size_t count)
//{
//	assert(dst&&src);
//	char * ret = dst;
//	while (*dst++);
//	--dst;
//	while (count--&&*dst)
//	{
//		*dst++ = *src++;
//	
//
//	}
//	*dst = '\0';
//	return ret;
//}
// strcat的实现
// fang fa 1
//char* my_strcat(char*dst, const char* src)
//{
//	assert(dst&&src);
//	char* ret = dst;
//	int count = 0;
//	while (dst[count])
//		count++;
//	dst = dst + count;
//	while (*dst++ = *src++);
//	
//	return ret;
//}
// fang fa 2
//char* my_strcat(char* dst, const char* src)
//{
//	assert(dst&&src);
//	char * ret = dst;
//	while (*dst++);
//	--dst;
//	while (*dst++ = *src++);
//	return ret;
//}
//int main()
//{
//	char arr1[100] = "abcdefg";
//	char arr2[] = "eded";
//	printf("%s", my_strcat(arr1, arr2));
//	system("pause");
//}

////int my_strncmp(const char* str1, const char* str2, size_t count)
////{
////	assert(str1&&str2);
////	while (count--&&*str1&&*str2)
////	{
////		if (*(unsigned char*)str1 > *(unsigned char*)str2)
////			return 1;
////		if (*(unsigned char*)str1 < *(unsigned char*)str2)
////			return -1;
////		if (*str1 == *str2)
////			str1++; str2++;
////	}
////	return 0;
////}
//
//int main()
//{
//	char arr2[] = "2349799";
//	//printf("%s\n", arr);
//	char arr1[70] = "abcde";
//	char str3[] = "abcde";
//	char str4[] = "abcef";
//	printf("%d", my_strncmp(str3, str4, 4));
//	//printf("%s\n", my_strncat(arr1, arr2, 7));
//	//printf("%s", my_strncpy(arr1, arr2, 3));
//	system("pause");
//}
//char* my_strstr(char* str1, char*str2)
//{
//	assert(str1&&str2);
//	
//	while (*str1)
//	{
//		char* st1 = str1;
//		char* st2 = str2;
//		while (*st1 == *st2&&*st2)
//		{
//			st1++;
//			st2++;
//		}
//		if (*st2 == '\0')
//			return str1;
//		else
//			str1++;
//	}
//	return NULL;
//}
//int main()
//{
//	char arr1[] = "abcdefghigk";
//	char arr2[] = " ";
//	printf("%s", my_strstr(arr1, arr2));
//	system("pause");
//}
// strtok的用法
int main()
{
	char*p1 = "zhangpengwei@bitedu.tech";
	char*p2 = "793479274@qq.com";
	char* sep = strtok(p1, "@.");
	while (sep != NULL)
	{
		printf("%s\n", sep);
		sep = strtok(NULL,)
	}
}