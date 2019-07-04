#define _CRT_SECURE_NO_WARNINGS 1 
#include <stdio.h>
#include <assert.h>
#include <string.h>
char *my_strncpy( char * dst, const char * src, size_t count)
{
	assert(dst&&src);
	char * dt = dst;
	while (*src && count--)
	{
		*dst = *src;
		dst++;
		src++;
	}
	*dst = '\0';
	return dt;
}
char * my_strncat( char * dst, const char * src, size_t count)
{
	assert(dst&&src);
	char * dt = dst;
	while (*dst)
		dst++;
	while (count--&&*src)
	{
		*dst = *src;
		dst++;
		src++;
	}
	*dst == '\0';
	return dt;
}
int my_strncmp(const char * dst, const char * src, size_t count)
{
	assert(dst&&src);
	int n = count;		//无符号整型转换成整型， 整型提升无影响  
	while ((--n)&&*(unsigned char*)src&&*(unsigned char*)dst)//count = 3 2 1 这里注意，不能这样写，size_t类型无符号整型，-1时是正数最大值
	{
		if (*(unsigned char*)dst > *(unsigned char*)src)
		{
			return 1;
		}
		else if (*(unsigned char*)dst < *(unsigned char*)src)
		{
			return -1;
		}
		else
		{
			dst++;
			src++;
			
		}

	}
	if (n == 0)
	{
		if (*dst != '\0'&&*src == '\0')
		{
			return 1;
		}
		else if (*dst == '\0'&&*src != '\0')
		{
			return -1;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		if (*dst != '\0')
		{
			return 1;
		}
		if (*src != '\0')
		{
			return -1;
		}
		else
		{
			return 0;
		}
	}
	
}
int main()
{
	char arr1[100] = "damn shaddy";
	char arr2[100] = "Comon";
	//printf("%s\n", my_strncpy(arr1, arr2, 4));
	printf("%s\n", my_strncat(arr1, arr2, 3));
	char arr3[] = "abcdefg";
	char arr4[] = "abcdefghigjk";
	//printf("%d\n", strncmp(arr3, arr4, 4));
	//printf("%d\n", my_strncmp(arr3, arr4, 4));
	//printf("%d\n", strncmp(arr3, arr4, 3));
	printf("%d\n", my_strncmp(arr3, arr4, 100));

//	printf("%d\n", my_strncmp(arr3, arr4, 3));


	system("pause");
}