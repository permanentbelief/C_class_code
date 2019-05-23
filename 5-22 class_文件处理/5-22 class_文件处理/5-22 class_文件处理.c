#define _CRT_SECURE_NO_WARNINGS 1 
#include <stdio.h>
//int main()
//{
//	FILE * fin = fopen("input.c", "w");
//	fputc('X', fin);
//	fflush(fin);
//	fputs("\nhello", fin);
//	while (1) ;
//	fclose(fin);
//	system("pause");
//	return 0;
//}
//int main()
//{
//	FILE* fin = fopen("input.c", "w");
//	fprintf(fin, "语文：%d\n数学：%d\n英语：%d\n排名:%d \n", 98, 99, 100, 1);
//	char *s = "书卓越";
//	//fprintf(fin, "%s I love you", s);
//	fclose(fin);
//	system("pause");
//}
//
//int main()
//{
//	FILE * fout = fopen("input.c", "r");
//	int a, b, c, d;
//	fscanf(fout, "语文：%d\n数学：%d\n英语：%d\n排名:%d", &a, &b, &c, &d);
//	printf("%d %d %d %d", a, b, c, d);
//	fclose(fout);
//	system("pause");
//}
//int main()
//{
//	FILE* fp = fopen("我没吃过.txt", "w");
//	fputs( "我没吃过",fp);
//	fclose(fp);
//	system("pause");
//}
//struct TelInfo
//{
//	char _tel[16];
//	char _name[24];
//	int _age;
//};
//int main()
//{
//	struct TelInfo info;
//	strcpy(info._name, "peter");
//	strcpy(info._tel, "13123131231");
//	info._age = 18;
//
//	//二进制读写
//	FILE* fout_bin = fopen("input_bin.c", "wb");
//	fwrite(&info, sizeof(info), 1, fout_bin);
//	fclose(fout_bin);
//
//
//	
//	struct TelInfo other;
//	FILE* fin_bin = fopen("input_bin.c", "rb");
//	fread(&other, sizeof(other) , 1, fin_bin);
//	fclose(fin_bin);
//	printf("%s,%s,%d\n", other._name, other._tel, other._age);
//
//	system("pause");
//}

//#include <assert.h>
//#include <string.h>
//struct TelInfo
//{
//	char _tel[16];
//	char _name[24];
//	int _age;
//};
//// 将数字转化成字符串
//char * my_itoa(int num, char* buff)
//{
//	assert(buff);
//	//123
//	int flag = 0;
//	if (num < 0)
//	{
//		flag = 1;
//		num = 0 - num;
//	}
//	int i = 0;
//	while (num > 0)
//	{
//		buff[i] = num % 10 + '0';
//		num /= 10;
//		++i;
//	}
//	
//	if (flag == 1)
//	{
//		buff[i++] = '-';
//	}
//	int begin = 0;
//	int end = i - 1;
//	while (begin < end)
//	{
//		int temp = 0;
//		temp = buff[begin];
//		buff[begin] = buff[end];
//		buff[end] = temp;
//		begin++;
//		end--;
//	}
//	buff[i] = '\0';
//	return buff;
//}
//int main()
//{
//	struct TelInfo info;
//	strcpy(info._name, "皮特");
//	strcpy(info._tel, "1221213124");
//	info._age = 18;
//
////文本读写
//	FILE* fout_txt = fopen("input_text.c", "w");
//	fputs(info._name, fout_txt);
//	fputc('\n', fout_txt);
//
//	fputs(info._tel, fout_txt);
//	fputc('\n', fout_txt);
//
//	//fputs(info._age, fout_txt);
//	char buff[10];
//	printf("%s", my_itoa(info._age, buff));
//	fputs(my_itoa(info._age, buff), fout_txt);
//	fputc('\n', fout_txt);
//
//	fclose(fout_txt);
//
//	struct TelInfo other;
//	FILE* fin_bin = fopen("input_text.c", "r");
//	fclose(fin_bin);
//	printf("%s %s %d\n", other._name, other._tel, other._age);
//	
//	system("pause");
//}


// 文本读写 + my_itoa实现   整形转化为字符串
#include <stdio.h>
#include <assert.h>
#include <string.h>
struct TelInfo
{
	char _tel[6];
	char _name[24];
	int _age;
};
// itoa 数字转化为字符串的实现
//char *my_itoa(int num, char* arr)
//{
//	assert(arr);
//	int i = 0;
//	int flag = 0;
//	if (num < 0)
//	{
//		flag = 1;
//		num = 0 - num;
//	}
//	while (num > 0)
//	{
//		arr[i] = num % 10 +'0';
//		num /= 10;
//		i++;
//	}
//	if (flag == 1)
//	{
//		arr[i++] = '-';
//	}
//	int start = 0;
//	int end = i - 1;
//	while (start < end)
//	{
//		int temp = arr[start];
//		arr[start] = arr[end];
//		arr[end] = temp;
//		end--;
//		start++;
//
//	}
//	arr[i] = '\0';
//	return arr;
//}
// 字符串转化为数字的实现
// 
//void my_atoi( char*arr)
//{
//	assert(arr);
//	int i = 0;
//	int count = 0;
//	char arr1[100] = { 0 };
//	int j = 0;
//	int n = 0;
//	/*while (arr)
//	{
//		i++;
//	}*/
//	//等价于
//	while (arr[count++]);
//	for (i = 0; i < count; i++)
//	{
//		
//		if (arr[i] >= 48 && arr[i] <= 57)
//		{
//			arr1[j] = arr[i] - '0';
//			j++;
//			n++;
//		}
//	}
//	arr1[j] = '\0';
//	for (i = 0; i < n; i++)
//	{
//		printf("%d", arr1[i]);
//	}
//
//	
//}
//int main()
//{
//	struct TelInfo info;
//	strcpy(info._name, "皮特");
//	strcpy(info._tel, "1856565616");
//	info._age = 18;
//	//文本方式duxie
//	FILE* fout_text = fopen("input_text.c", "w");
//	fputs(info._name, fout_text);
//	fputc('\n', fout_text);
//
//	fputs(info._tel, fout_text);
//	fputc('\n', fout_text);
//
	/*char age_buff[12];
	my_itoa(info._age, age_buff);
	fputs(age_buff, fout_text);
	fputc('\n', fout_text);*/

	/*fclose(fout_text);
	struct TelInfo other;
	FILE* fin_bin = fopen("input_text.c", "r");
	fclose(fin_bin);
	printf("%s,%s,%d\n", other._name, other._tel, other._age);
	system("pause");*/
	/*char buff[10];
	printf("%s", my_itoa(-78888, buff));*/
	/*my_atoi("lda1989");*/
//	system("pause");
//}
int main()
{
	FILE *fin = fopen("input.c", "w");
	fputs("world", fin);
	fseek(fin, 4, SEEK_SET);
	fputs("hello", fin);



	fclose(fin);
	system("pause");
}