#define _CRT_SECURE_NO_WARNINGS 1 
#include <stdio.h>

void func(int ***pppa, int **ppb) 
{
	**pppa = *ppb;
	
}
int main()
{
	int a = 3;
	int b = 4;
	int *pa = &a;
	int *pb = &b;
	int **ppa = &pa;
	int **ppb = &pb;
	func(&ppa, &pb);
	printf("%d\n", **ppa);
	system("pause");
}