#define _CRT_SECURE_NO_WARNINGS 
//1 .һ��������ֻ�����������ǳ���һ�Σ�
//�����������ֶ����������Ρ�
//�ҳ�������ֻ����һ�ε����֣����ʵ�֡�
//#include <stdio.h>
//#include <string.h>
//void find(char* str , int sz)
//{
//	int i = 0;
//	int t = 0;
//	int x = 0;
//	int y = 0;
//	int tt = 0;
//	for (i = 0; i < sz; i++)
//	{
//		t ^= str[i];
//	}
//	for (i = 32; i > 0; i--)
//	{
//		if ((t >> i) & 1 == 1){
//			tt = i;
//		}
//	}
//	for (i = 0; i < sz; i++)
//	{
//		if ((str[i] >> tt) == 1)
//		{
//			x ^= str[i];
//		}
//		else
//		{
//			y ^= str[i];
//		}
//	}
//	printf("%d,%d", x, y);
//}
//int main()
//{
//	char str[] = { 1, 1, 2, 2, 3, 4 };
//	int sz = sizeof(str) / sizeof(str[0]);
//	find(str,sz);
//	system("pause");
//
//}
// ģ��ʵ��strstr �Ͽε�ʱ��û������������
//#include <stdio.h>
//char* my_strstr(char* dest, char* src)
//{
//	//assert(dest&&src);
//	
//	while (*dest)
//	{
//		char* dst = dest;
//		char* sc = src;
//		while( *sc && *dst && *dst == *sc)
//		{
//			sc++;
//			dst++;
//		}
//		if (*sc == '\0')
//			return dest;
//		++dest;
//	}
//	return NULL;
//}
//int main()
//{
//	char dest[100];
//	char src[100];
//	scanf("%s", dest);
//	scanf("%s", src);
//	if (my_strstr(dest, src) != NULL)
//	{
//		printf("OK\n");
//	}
//	else
//	{
//		printf("ERROR\n");
//	}
//	system("pause");
//}
//���Ͼ��� 
//��һ����ά����.
//�����ÿ�д������ǵ����ģ�ÿ�д��ϵ����ǵ�����.
//�������������в���һ�������Ƿ���ڡ�
//ʱ�临�Ӷ�С��O(N);
#define N 3
#include <stdio.h>
//�����Ͻǿ�ʼ��
//int find(int arr[N][N], int row, int col, int key)
//{
//	int x = 0;// 0
//	int y = col- 1;// 2 ����(0,2)
//	//�ٽ��
//	while (y >= 0 && x <= row-1)
//	{
//		if (key == arr[x][y])
//		{
//			return 1;
//		}
//		if (key < arr[x][y])
//		{
//			//�������
//			y--;
//		}
//		if (key > arr[x][y])
//		{
//			//���²���
//			x++;
//		}
//	}
//	return -1;
//}
//�����½ǿ�ʼ��
//int find(int arr[N][N], int row, int col, int key)
//{
//	int x = 0;
//	int y = col - 1;
//	while (x < row && y >= 0)
//	{
//		if (arr[x][y] == key)
//		{
//			return 1;
//
//		}
//		if (arr[x][y] > key)
//		{
//			y--;
//		}
//		if (arr[x][y] < key)
//		{
//			x++;
//		}
//	
//	}
//	return -1;
//}
//�ݹ鷽��
//int find(int arr[][N], int row, int col, int key, int x, int y)
//{
//	
//	//���½ǿ�ʼ ,��main�����и�x y ��ֵ
//	if (x >= row || y < 0)
//		return -1;
//		if (arr[x][y] == key)
//		{
//			return 1;
//		}
//		else if (arr[x][y]>key)
//		{
//			return find(arr, row, col, key, x, y - 1);
//		}
//		else 
//		{
//			return find(arr, row, col, key, x + 1, y);
//
//		}
//	
//	
//}
//
//int main()
//{
//	int arr[N][N] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
//	int a = 0;
//	scanf("%d", &a);
//	
//	int ret = find(arr, N, N, a ,0,N-1);
//	if (ret == -1)
//	{
//		printf("û�ҵ�");
//	}
//	else
//	{
//		printf("�ҵ���");
//	}
//	system("pause");
//}
//1.ʵ��һ�����������������ַ����е�k���ַ���
//ABCD����һ���ַ��õ�BCDA
//ABCD���������ַ��õ�CDAB
// ����һ
//void left_move_1(char* arr)
//{
//
//	char *start = arr;
//	char tmp = *arr;
//	while (*(arr + 1))
//	{
//		*arr = *(arr + 1);
//		arr++;
//	}
//	*arr = tmp;
//	printf("%s",start);
//
//}
//char* left_move(char* arr, int k)
//{
//	while (k--)
//	{
//		left_move_1(arr);
//		
//	}
//	//printf("%s", arr);
//	return arr;
//}
//int main()
//{
//	char arr[] = "ABCDEFG";
//	int k = 0;
//	//scanf("%d", &k);
//	left_move_1(arr);
//	//printf("%s", left_move_1(arr));
//	//left_move(arr, k);
//	//printf("%s", left_move(arr,k));
//	system("pause");
//}
//������
//����תһ���ַ�Ϊ�� ABCD
//       A BCD  ǰk��k��������1�����ַ���ת
//		 A DCB  ������ַ���ת
//		 BCDA   ȫ����һ����ת
// ���ú���
//void swap(char* str , int n)
//{
//	int i = 0;
//	int temp = 0;
//	/*for (i = 0; i <( n / 2); i++)
//	{
//		int temp = str[i];
//		str[i] = str[n - i - 1];
//		str[n - i - 1] = temp;
//	}*/
//	int left = 0;
//	int right = n-1;
//	while (left <= right)
//	{
//		temp = str[left];
//		str[left] = str[right];
//		str[right] = temp;
//		left++;
//		right--;
//	}
//	for (i = 0; i < n; i++)
//	{
//		printf("%c ", str[i]);
//	}
//}
//int main()
//{
//	char arr[] = "abcd";
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	swap(arr, sz);
//	//printf("\n %d", sz);
//	system("pause");
//}
//void swap(char* start, char* end)
//{
//	
//	while (start < end)//!!!
//	{
//		char temp = *start;
//		*start = *end;
//		*end = temp;
//		++start;
//		--end;
//	}
//}
//
//void left_move2(char *str, int k)
//{
//	int len = strlen(str);
//	k %= len;
//	//��һ�� 0~k-1
//	swap(str, str + k - 1);
//	//�ڶ��� k~len-1
//	swap(str + k, str + len - 1);
//	//������ 0~len-1
//	swap(str, str + len - 1);
//}
//void right_move(char* str, int k)
//{
//	int len = strlen(str);
//	left_move2(str, len - k);//����k ���� ����len-k
//}
//int main()
//{
//	char str[100] = { 0 };
//	scanf("%s", str);
//	int k = 0;
//	scanf("%d", &k);
//	left_move2(str, k);
//	printf("%s", str);
//	right_move(str, k);
//	system("pause");
//}
#include <assert.h>
// ����һ
//char* my_strcat( char* dest, char*src)
//{
//	assert(dest, src);
//	char *ret = dest;
//	while (*++dest);
//	--dest;
//	while ( *src &&(*dest++ = *src++));
//	*dest = '\0';
//
//
//	return ret;
//}
// ������
//char* strcat(char * dst, char* src)
//{
//	char* ret = dst;
//	while (*dst)
//		++dst;
//	while (*dst++ = *src++);
//	return ret;
//}
// strncat��ʵ��
//char* my_strncat(char * dst, const char * src, size_t n)
//{
//	assert(dst&& src);
//	char* ret = dst;
//	while (*dst++);
//	--dst;
//	while (n--&& *src)
//	{
//		*dst++ = *src++;
//	}
//		*dst = '\0';
//	
//	
//	return ret;
//}
//int main()
//{
//	char arr1[30] = "��,";
//	char arr2[] = "�����������õ�һ�죡";
//	printf("%s", my_strncat(arr1, arr2,strlen(arr2)));
//	system("pause");
//}
// strncpy��ʵ��
//char* my_strncpy(char* src, const char* dst, size_t n )
//{
//	assert(src && dst);
//	char * ret = src;
//	while (n--)
//	{
//		*src++ = *dst++;
//	}
//	*src = '\0';
//	return ret;
//}

int main()
{
	char arr1[] = "zhu zhuo yue";
	char arr2[] = "de ba ba";
	printf("%s", my_strncpy(arr1, arr2, 4));
	system("pause");

}