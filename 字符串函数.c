#define _CRT_SECURE_NO_WARNINGS 1 
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
//strlen
//size_t my_strlen(const char* str)
//{
//	assert(str);
	//����һ
	/*int count = 0;
	while (*str)
	{
		count++;
		str++;
	}
	return count;*/
	//������ ��ָ������Ĳ�ΪԪ�ظ���
	//str++����str�Ƚ���++���㣬����ֵ����str��++str�ķ���ֵ��str+1;
	//char* begin = str; //
	//while (*++str); //ע��������������str++������Խ�磬���ʵ�'\0������һλ��
	////++str���÷��ʵ�'\0������һ��λ�ã�ͨ�����Ӵ��ڿ��Կ���
	//return  (str - begin);
	//������ �ݹ�
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
	//����һ
	//assert(src&&dst);
	//char * dt = dst;
	//while (*dst++ = *src++);
	//return dt;
	//����er
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
//	//����һ��
//	//assert(dst&&src);
//	//char* dt = dst;
//	//while (*++dst);//ע�����ﲻ����*dst++,�����dst��ָ��'\0������һλ��Ҳ��'\0������������ַ����Ӳ���ȥ
//	//while (*dst++ = *src++);
//	//return dt;
//	//������  ������ָ���������
//	assert(dst&&src);
//	size_t count = 0;
//	while (dst[++count]); //                     1 1 2 3    ����Ϊ ++count 
//	while (dst[count++] = *src++);  //   ����ֵ  0 1 2 3 ��δ��'\0�������������һλ����'\0'����һλ
//	return dst;                     //   ��ʵֵ  1 2 3 4 ��'\0��
//} 
//strstr
//char * my_strstr(char *dst, const char*src) //�ж��Ƿ�Ϊ�Ӵ�
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
//	while (*dst)//������д�е����⣬�����һ������'\0���Ļ�����ֱ������ȥ��
//	{
//		dst++;
//	}
//	while (size--&& *src )//1.��src�ȵ����
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
	char arr4[] = "hellodada"; //������������
	//printf("%d\n", my_strcmp(arr3,arr4));
	printf("%s\n", my_strncpy(arr3,arr4,7));

	//char arr6[100] = "asdadwoyaodila  ";
	//char arr7[] = "daw=";
	//printf("%s\n", my_strncat(arr6, arr7,2));

	//printf("%s\n", my_strncpy(arr6, arr7, 8));



	system("pause");
}