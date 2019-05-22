#define _CRT_SECURE_NO_WARNINGS 1 
#include "contact.h"

void ContactBookInit(ContactBook* cb)//初始化通讯表
{
	assert(cb);
	cb->_con_array = (Contact*)malloc(sizeof(Contact)*8);//通过malloac函数动态申请8个通讯人信息
	if (cb->_con_array == NULL)//如果为空，初始化失败
	{
		printf("Init error"); 
		exit(-1);
	}
	cb->_size = 0;                 //现已存的的人 初始化为 0
	cb->_capacity = 8;             //容量 动态先申请了 8 个空间大小
}

void ContactBookAppend(ContactBook* pbook, Contact* pcon)
//追加联系人 pcon是新联系人， pbook是通讯录的指针
//!!!!!!!!!!!!!!!!!!这里注意 追加 就是size的位置上 
{
	assert(pbook&&pcon);
	
	if (pbook->_size >= pbook->_capacity)//如果联系人的人数_size > 通讯录可容下的数量_capacity
	{
		pbook->_capacity *= 2; // 先扩充了2倍
	// 通讯录中定义的结构体指针_con_array
	 Contact* newarray = (Contact*)realloc(pbook->_con_array, sizeof(Contact)*pbook->_capacity);// realloc原地址扩充
		if (newarray == NULL)// realloc扩充了newarray 那 为什么 还有可能为空指针
		{
			printf("relloc error");
			exit(-1);
		}
		pbook->_con_array = newarray;// 把新开辟的nearray 赋给 （Contact* _con_array)定义的)_con_array
	}
	//通讯人信息
	//我第一次写的 下面两种均可以！
	/*Contact * obj;
	size_t i = pbook->_size;
	strcpy(obj[i]._name, pcon->_address);
	strcpy(obj[i]._address, pcon->_name);
	strcpy(obj[i]._tel, pcon->_tel);
	obj[i]._age = pcon->_age;*/
	Contact * array = pbook -> _con_array;
	size_t i = pbook->_size;
	strcpy(array[i]._address, pcon->_address);
	strcpy(array[i]._name, pcon->_name);
	strcpy(array[i]._tel, pcon->_tel);
	array[i]._age = pcon->_age;

	pbook->_size++;
}
void ContactBookDestory(ContactBook* cb)// 释放空间
{
	assert(cb);
	free(cb->_con_array);
	cb->_con_array = NULL;//释放动态的空间 置为空
	cb->_size = 0;
	cb->_capacity = 8;
}
void ContactBookprint(ContactBook* pbook)//打印通讯录中每人的信息
{
	for (size_t i = 0; i < pbook->_size; i++)
	{
		printf("-----------------------------------------\n");
		printf("姓名：%s\n", pbook->_con_array[i]._name);
		printf("电话：%s\n", pbook->_con_array[i]._tel);
		printf("地址：%s\n", pbook->_con_array[i]._address);
		printf("年龄：%d\n", pbook->_con_array[i]._age);
		printf("-----------------------------------------\n");

	}
}
Contact* ContactBookFind(ContactBook* pbook, const char * name)//查找通讯录里的联系人
{
	assert(pbook&&name);
	size_t i = 0;
	//Contact* find_con_array;
	for (i = 0; i < pbook->_size; i++)
	{
		if (strcmp((pbook->_con_array[i]._name), name) == 0)
		{
			return  pbook->_con_array; //这里怎么实现 应该返回类型为Contact*，这里是pbook是Con
		}                             
	}
	return NULL;
}
void ContactBookDelete(ContactBook* pbook, const char* name)//删除通讯录里的信息
{
	// 总体思路：找到要删除的那个人的在通讯录里的位置，然后后面的信息全部往前置一个单位
	assert(pbook&&name);
	size_t i = 0;//循环变量
	size_t k = 0;//创造临时变量，记住名字相同时，此时的人在通讯录里的位置
	if (ContactBookFind(pbook, name) == NULL)
	{
		printf("通讯录里此人未查到，不能删除成功");
		exit(-1);
	}
	else
	{
		for (i = 0; i < pbook->_size; i++)
		{
			if (strcmp(pbook->_con_array[i]._name, name) == 0)
				k = i;                                   //找出通讯录里哪个位置是要删除的
		}
		for (i = k; i < pbook->_size; i++)//后面的信息向前覆盖
		{
			strcpy(pbook->_con_array[i]._name, pbook->_con_array[i + 1]._name);
			strcpy(pbook->_con_array[i]._tel,  pbook->_con_array[i + 1]._tel);
			strcpy(pbook->_con_array[i]._address, pbook->_con_array[i + 1]._address);
			pbook->_con_array[i]._age = pbook->_con_array[i + 1]._age;

		}
		pbook->_size--;//因为删除了一个，所以本来的存储范围减1；
	}
}
void ContactBookSave(ContactBook* pbook, const char* file)
{
	FILE* fp = fopen(file, "wb");//二进制形式读写
	if (fp == NULL)
	{
		printf("打开文件失败");
		exit(-1);
	}
	Contact* array = pbook->_con_array;
	for (size_t i = 0; i < pbook->_size; ++i)
	{
		fwrite(&array[i], sizeof(Contact), 1, fp);
	}
	fclose(fp);
}
void ContactBookLoad(ContactBook* pbook, const char* file)
{
	FILE * fp = fopen(file, "rb");
	if (fp == NULL)
	{
		printf("打开文件失败\n");
		exit(-1);
	}
	Contact con;
	while (fread(&con, sizeof(Contact),1,fp) == 1)
	{
		ContactBookAppend(pbook, &con);
	}

	fclose(fp);
}