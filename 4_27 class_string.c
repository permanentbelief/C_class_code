#define _CRT_SECURE_NO_WARNINGS 1 
#include <stdio.h>
#include <string.h>
#include <assert.h>
//题目一
//int main()
//{
//	int aa[2][5] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int *ptr1 = (int*)(&aa + 1);//&aa在这里aa是数组的地址 +1加的是一个数组的大小，加到10后面一位
//	int *ptr2 = (int*)(*(aa + 1));//aa是首元素的地址,第一行。+1 加一个行 五个数据的大小
//	printf("%d,%d", *(ptr1 - 1), *(ptr2 - 1));//10 
//	system("pause");
//	return 0;
//	//数组指针 (*(aa+1)) aa是数组指针 解引用为一个数组首元素的值，在强转为int*
//  !!!!!!!!!!!!!!!!!!!!!!!!加不加无所谓吗不是
//}
//题目二·
//int main()
//{
//	char* a[] = { "work", "at", "alibaba" };
//	char**pa = a;
//	pa++;
//	printf("%s\n", *pa);
//	system("pause");
//}
//题目三
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
//	printf("%d\n", strlen(str1));//5//又错了，到'\0'结束，不计'/0'
//	printf("%d\n", sizeof(str1));//4
//	char str2[] = "hello";
//	printf("%d\n", strlen(str2));//5
//	printf("%d\n", sizeof(str2));//特殊，sizeof(数组名)表示整个数组的大小，且计算'\0’
//	char str3[] = "abcde\0gh\0";
//	printf("%d\n", strlen(str3));//5 读取到\0结束
//	printf("%d\n", sizeof(str3));//10 算上最后一个'\0’
//	char str4[] = "abcde\\0gh\\\0";
//	printf("%d\n", strlen(str4));//10 //不算\0而且\\算转义字符输出一个
//	printf("%d\n", sizeof(str4));//12
//	char str5[] = "abcde\\0gh\t\n\r";
//	printf("%d\n", strlen(str5));//12
//	printf("%d\n", sizeof(str5));//13
//
//
//	system("pause");
//}
//方法一
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
//方法二
//int my_strlen(const char*str)
//{
//	if (*str == '\0')
//		return 0;
//	return 1 + my_strlen(++str);
//
//}
//方法三：
//int my_strlen(const char * str)
//{
//	assert(str);
//	const char* end = str;
//	while (*++end);//1.优先级++ > * 2.如果是end++往后读取一位到end+1,返回的end判断*end是否为'
//	//\0 ,若为'\0’则不执行跳出while，但此时的end已经向\0后读取一位
//	return end - str;
//}
//int main()
//{
//	printf("%d", my_strlen("adada"));
//	system("pause");
//}
//方法一
//char * my_strcpy(char* dst, const char * src)
//{
//	assert(dst&&src);
//	char * ret = dst;
//	while (*dst++ = *src++);
//	return ret;
//}
//方法二 怎么不行 ！！！！！
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
//方法二
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
//	dst += count;//这里dst是什么？加一个值什么意思？
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