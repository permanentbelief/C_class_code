#define _CRT_SECURE_NO_WARNINGS 1 
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
//strlen
//size_t my_strlen(const char* str)
//{
//	assert(str);
	//方法一
	/*int count = 0;
	while (*str)
	{
		count++;
		str++;
	}
	return count;*/
	//方法二 两指针相减的差为元素个数
	//str++这里str先进行++运算，返回值还是str，++str的返回值是str+1;
	//char* begin = str; //
	//while (*++str); //注意这里！！！如果是str++则会访问越界，访问到'\0’的下一位，
	////++str正好访问到'\0’的那一个位置，通过监视窗口可以看出
	//return  (str - begin);
	//方法三 递归
//	if (str == '\0')
//	{
//		return 0;
//	}
//	else
//	{
//		return 1 + strlen(str+1); //wode
//	}
//
//}
//strcpy
//char *my_strcpy(char* dst, const char*src)
//{
	//方法一
	//assert(src&&dst);
	//char * dt = dst;
	//while (*dst++ = *src++);
	//return dt;
	//方法er
	//char * dt = dst;
	//while (*src)   //                 1 2 3 4
	//{              //                 
	//	*dst = *src;
	//	dst++;
	//	src++;
	//}
	//*dst = '\0';
	//return dt;
//}
//strcat
//char* my_strcat(char *dst, const char* src)
//{
//	//方法一：
//	//assert(dst&&src);
//	//char* dt = dst;
//	//while (*++dst);//注意这里不能用*dst++,这里的dst会指向'\0’的下一位，也是'\0’，但后面的字符串加不上去
//	//while (*dst++ = *src++);
//	//return dt;
//	//方法二  不创建指针变量！！
//	assert(dst&&src);
//	size_t count = 0;
//	while (dst[++count]); //                     1 1 2 3    必须为 ++count 
//	while (dst[count++] = *src++);  //   返回值  0 1 2 3 还未到'\0’还得再往后读一位，到'\0'的下一位
//	return dst;                     //   真实值  1 2 3 4 到'\0’
//} 
//strstr
//char * my_strstr(char *dst, const char*src) //判断是否为子串
//{
//	assert(dst&&src);
//	char* dt = dst;
//	char *sc = src;
//	while (*sc)
//	{
//		if (*sc == *dt)
//		{
//			sc++;
//			dt++;
//		}
//		else
//		{
//			dt = dst;
//		}
//      	
//	}
//	if ()
//}
int my_strcmp(const char *str1, const char *str2)
//{
//	assert(str1&&str2);
//	while (*str1&&*str2)
//	{
//		if (*str1 > *str2)
//		{
//			return 1;
//		}
//		else if (*str1 < *str2)
//		{
//			return -1;
//		}
//		else
//		{
//			str1++;
//			str2++;
//		}
//	}
//	if (str1 != NULL)
//	{
//		return 1;
//	}
//	else if (str2 != NULL)
//	{
//		return -1;
//	}
//	else
//	{
//		return 0;
//	}
//}
//{
//	assert(str1&&str2);
//	int ret = 0;
//	while (!(ret = *str1 - *str2) && *str2 )
//	{
//		++str1;
//		++str2;
//	}
//	if (ret > 0)
//	{
//		return 1;
//	}
//	else if (ret < 0)
//	{
//		return -1;
//	}
//	else
//	{
//		return 0;
//	}
//}
//memcpy
//void* my_memcpy(void *  dst, const void*src, size_t size)
//{
//	assert(dst&&src);
//	 char* dt = (const char*)dst;
//	const char* sc = (const char*)src;
//	for (size_t i = 0; i < size; i++)
//	{
//		dt[i] = sc[i];
//	}
//	return dst;
//}
//memmove


//strncpy
//char * my_strncpy( char* dst, const char* src,size_t size)
//{                                                 // 3
//	assert(dst&&src);
//	char* dt = dst;
//	while (size--&&src ) 
//	{
//		*dst = *src;
//		dst++;
//		src++;
//	}
//	*dst = '\0';
//	return dt;
//
//}
//strncat
//char* my_strncat(char* dst, const char* src, size_t size)
//{
//	assert(dst&&src);
//	char *dt = dst;
//	while (*dst)//这样子写有点问题，如果第一个就是'\0’的话，就直接跳过去了
//	{
//		dst++;
//	}
//	while (size--&& *src )//1.若src先到最后，
//	{
//		*dst++ = *src++;
//		
//	}
//	*dst = '\0';
//	return dt;
//}
//strncmp
//int my_strncmp(const char * str1, const char* str2, size_t size)
//{
//	assert(str1&&str2);
//	while (size--&&*str2)
//	{
//		if (*str1 > *str2)
//		{
//			return 1;
//		}
//		else if (*str1 < *str2)
//		{
//			return -1;
//		}
//		else
//		{
//			str1++;
//			str2++;
//		}
//	}
//	if (*str2 != '\0')
//	{
//		return 0;
//	}
//	else
//	{
//		return 1;
//	}
//}
int main()
{
	//char arr[] = "dad";
	/*printf("%d\n", strlen(arr));
	 printf("%d", my_strlen(arr));*/
	//char arr1[100] = "fdadlwwwwwwww";
	//printf("%s\n", my_strcpy(arr1, arr));
	//printf("%s\n", strcpy(arr1, arr));
	//printf("%s\n", my_strcat(arr1, arr));
	//printf("%s\n", my_memcpy(arr1, arr,3));
	char arr3[100] = "hello";
	char arr4[] = "hellodada"; //不可以这样比
	//printf("%d\n", my_strcmp(arr3,arr4));
	printf("%s\n", my_strncpy(arr3,arr4,7));

	//char arr6[100] = "asdadwoyaodila  ";
	//char arr7[] = "daw=";
	//printf("%s\n", my_strncat(arr6, arr7,2));

	//printf("%s\n", my_strncpy(arr6, arr7, 8));



	system("pause");
}