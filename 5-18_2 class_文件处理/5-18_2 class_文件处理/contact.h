#define _CRT_SECURE_NO_WARNINGS 1 
#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

typedef struct Contact // 通讯录里一个人的信息 并且重命名结构体为Contact
{
	char _name[24];
	char _tel[16];
	char _address[64];
	int  _age;
}Contact;
// 通讯录
typedef struct ContactBook // 通讯录里的信息
{
	//Contact _con_array[500];
	Contact* _con_array;    //不知道先开几个， 动态增长
	 //顺序表 数据结构 数组增长
	size_t _size;  //联系人个数
	size_t _capacity; //容量
}ContactBook;

void ContactBookInit(ContactBook* pbook);//初始化通讯录
void ContactBookDestory(ContactBook* pbook);// 通讯录释放动态开辟的空间
void ContactBookAppend(ContactBook* pbook , Contact* con); //添加人到通讯录
void ContactBookDelete(ContactBook* pbook,const char* name);//删除通讯录里的信息
Contact* ContactBookFind(ContactBook* pbook, const char * name);//查找通讯录里的联系人
void ContactBookSave(ContactBook* pbook, const char* file);// 存储数据
void ContactBookLoad(ContactBook* pbook, const char* file);// 数据
void ContactBookprint(ContactBook* pbook);//打印通讯录里面的信息
