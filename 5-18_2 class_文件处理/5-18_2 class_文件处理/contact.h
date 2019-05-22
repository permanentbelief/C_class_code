#define _CRT_SECURE_NO_WARNINGS 1 
#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

typedef struct Contact // ͨѶ¼��һ���˵���Ϣ �����������ṹ��ΪContact
{
	char _name[24];
	char _tel[16];
	char _address[64];
	int  _age;
}Contact;
// ͨѶ¼
typedef struct ContactBook // ͨѶ¼�����Ϣ
{
	//Contact _con_array[500];
	Contact* _con_array;    //��֪���ȿ������� ��̬����
	 //˳��� ���ݽṹ ��������
	size_t _size;  //��ϵ�˸���
	size_t _capacity; //����
}ContactBook;

void ContactBookInit(ContactBook* pbook);//��ʼ��ͨѶ¼
void ContactBookDestory(ContactBook* pbook);// ͨѶ¼�ͷŶ�̬���ٵĿռ�
void ContactBookAppend(ContactBook* pbook , Contact* con); //����˵�ͨѶ¼
void ContactBookDelete(ContactBook* pbook,const char* name);//ɾ��ͨѶ¼�����Ϣ
Contact* ContactBookFind(ContactBook* pbook, const char * name);//����ͨѶ¼�����ϵ��
void ContactBookSave(ContactBook* pbook, const char* file);// �洢����
void ContactBookLoad(ContactBook* pbook, const char* file);// ����
void ContactBookprint(ContactBook* pbook);//��ӡͨѶ¼�������Ϣ
