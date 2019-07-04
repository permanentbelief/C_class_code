#define _CRT_SECURE_NO_WARNINGS 1 
#include <stdio.h>
#include <assert.h>
char* my_strcpy(char * dst, const char* src)
{
	assert(dst&&src);
	char * dt = dst;
	while (*dst++ = *src++);
	//*dst = '\0';
	return dt;
}
char *my_strcat(char * dst, const char* src)
{
	assert(dst&&src);
	char *dt = dst;
	while (*dst++);
	--dst;
	while (*dst++ = *src++);
	//*dst = '\0';
	return dt;
}
char * my_strstr(const char *str1, const char * str2)//str1是不是str2的子串
{
	assert(str1&&str2);
	const char * match = str1;
	const char * sub = str2;
	while (*str1)
	{
		while (*match == *sub && *sub)
		{
			++match;
			++sub;
		}
		if (*sub == '\0')
		{
			return str1;
		}
		else
		{
			str1++;
		}
	}


	
}
int  my_strcmp(const char * str1, const char * str2)
{
	assert(str1&&str2);
	while (*str1&&*str2)
	{
		if (*(unsigned char*)str1 > *(unsigned char*)str2)
		{
			return 1;
		}
		else if (*(unsigned char*)str1 < *(unsigned char*)str2)
		{
			return -1;
		}
		else
		{
			str1++;
			str2++;
		}
	}
	if (*str1 != '\0')
	{
		return 1;
	}
	else if (*str2 != '\0')
	{
		return -1;
	}
	else
	{
		return 0;
	}
	
}
void * memcpy(void* dst, const void* src, size_t n)
{
	assert(dst&&src);
	char* dt = (char*)dst;
	const char* sc = (char*)src;
	for (size_t i = 0; i < n; i++)
	{
		dt[i] = sc[i];
	}
	return dst;
	
}
void *memmove(void * dst, const void* src, size_t size)
{
	assert(dst&&src);
	char* dt = (char*)dst;
	const char *sc = (char*)src;
	if (sc < dt && dt < sc + size)//从后向前拷贝
	{
		for (int i = size - 1; i >= 0; i--)
		{
			dt[i] = sc[i];
		}
	}
	else
	{
		for (int i = 0; i < (int)size ; i++)
		{
			dt[i] = sc[i];
		}
	}
	return dst;

}