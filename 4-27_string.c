#define _CRT_SECURE_NO_WARNINGS 1 
#include <stdio.h>
#include <string.h>
//int main()
//{
	//int aa[2][5] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	//int *ptr1 = (int*)(&aa + 1);//取数组的地址
	//int *ptr2 = (int*)(*(aa + 1));//取数组首元素，第一行的地址， 为啥非得解引用
	//printf("%d %d", *(ptr1 - 1), *(ptr2 - 1));
	
	//char *a[] = { "work", "at", "alibaba" }; //指针数组， 存放的是指向字符串的指针，不是字符串
	//char **pa = a;  char*的地址为 char**，直接赋值过去                   char * p，p++ +的是 1  int * p，p++  +的是 4
	//pa++;
	//printf("%s\n", *pa);

	//char *c[] = { "ENTER", "NEW", "POINT", "FIRST" };//字符串并没有存到数组中
	//char **cp[] = { c + 3, c + 2, c + 1, c };
	//char ***cpp = cp;
	//printf("%s\n", **++cpp);//POINT
	//printf("%s\n", *--*++cpp+3);//ER
	//printf("%s\n", *cpp[-2]+3);//ST
	//printf("%s\n", cpp[-1][-1]+1);//EW


	
//size_t my_strlen(const char* str)
//{
//	int count = 0;
//	while (*str)
//	{
//		count++;
//		str++;
//	}
//	return count;
//}
//size_t my_strlen(const char* str)
//{ 
//	//assert(str);
//	const char*end = str;
//	while (*end++);
//	--end;
//	return end - str;
//}
//	
//size_t my_strlen(const char* str)
//{
//	if (*str == '\0')
//	{
//		return 0;
//	}
//	return  my_strlen(str+1) + 1;
//}


//char * my_strcpy(char *dst, const char* src)
//{
//	assert(dst&&src);
//	char *ret = dst;
//	while (*dst++ = *src++);
//	return ret;
//
//}
//char * my_strcpy(char *dst, const char* src)
//{
//	//assert(dst&&src);
//	char *ret = dst;
//	while (*src)
//	{
//		*dst = *src;
//		src++;
//		dst++;
//	}
//	*dst = *src;
//}

//char* my_strcat(char *dst, const char *src)
//{
//	char *ret = dst;
//	while (*dst++);
//	--dst;
//	while (*dst++= *src++);
//	return ret;
//}

//char* my_strcat(char *dst, const char *src)
//{
//	int count = 0;
//	char * ret = dst;
//	while (dst[count++]);
//	dst += count - 1;
//	while (*dst++ = *src++);
//	return ret;
//}
int my_strcmp(const char * str1, const char * str2)
{
	while (*str1&&*str2)
	{
		if (*str1 > *str2)
		{
			return 1;
		}
		if (*str1 < *str2)
		{
			return -1;
		}
		str1++;
		str2++;
	}
	if (*str1 != '\0')
	{
		return 1;
	}
	if (*str2 != '\0')
	{
		return -1;
	}
	else
	{
		return 0;
	}
}
int main()
{
	//char arr1[12] ;
	//printf("%s\n", arr1);
	///my_strcpy(arr1, "hello world");
	//printf("%s", arr1);
	/*char *p = "lllll";
	printf("%d\n", my_strlen(p));*/
	//char arr2[100] = "lihua ";
	//char arr1[100] = "ai chi yu";
	char arr1[] = "li hua";
	char arr2[] = "li huaa";
	printf("%d", my_strcmp(arr2, arr1));

	system("pause");
	return 0;
}