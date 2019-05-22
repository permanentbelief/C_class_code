#define _CRT_SECURE_NO_WARNINGS 1 
#include "contact.h"

void ContactBookInit(ContactBook* cb)//��ʼ��ͨѶ��
{
	assert(cb);
	cb->_con_array = (Contact*)malloc(sizeof(Contact)*8);//ͨ��malloac������̬����8��ͨѶ����Ϣ
	if (cb->_con_array == NULL)//���Ϊ�գ���ʼ��ʧ��
	{
		printf("Init error"); 
		exit(-1);
	}
	cb->_size = 0;                 //���Ѵ�ĵ��� ��ʼ��Ϊ 0
	cb->_capacity = 8;             //���� ��̬�������� 8 ���ռ��С
}

void ContactBookAppend(ContactBook* pbook, Contact* pcon)
//׷����ϵ�� pcon������ϵ�ˣ� pbook��ͨѶ¼��ָ��
//!!!!!!!!!!!!!!!!!!����ע�� ׷�� ����size��λ���� 
{
	assert(pbook&&pcon);
	
	if (pbook->_size >= pbook->_capacity)//�����ϵ�˵�����_size > ͨѶ¼�����µ�����_capacity
	{
		pbook->_capacity *= 2; // ��������2��
	// ͨѶ¼�ж���Ľṹ��ָ��_con_array
	 Contact* newarray = (Contact*)realloc(pbook->_con_array, sizeof(Contact)*pbook->_capacity);// reallocԭ��ַ����
		if (newarray == NULL)// realloc������newarray �� Ϊʲô ���п���Ϊ��ָ��
		{
			printf("relloc error");
			exit(-1);
		}
		pbook->_con_array = newarray;// ���¿��ٵ�nearray ���� ��Contact* _con_array)�����)_con_array
	}
	//ͨѶ����Ϣ
	//�ҵ�һ��д�� �������־����ԣ�
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
void ContactBookDestory(ContactBook* cb)// �ͷſռ�
{
	assert(cb);
	free(cb->_con_array);
	cb->_con_array = NULL;//�ͷŶ�̬�Ŀռ� ��Ϊ��
	cb->_size = 0;
	cb->_capacity = 8;
}
void ContactBookprint(ContactBook* pbook)//��ӡͨѶ¼��ÿ�˵���Ϣ
{
	for (size_t i = 0; i < pbook->_size; i++)
	{
		printf("-----------------------------------------\n");
		printf("������%s\n", pbook->_con_array[i]._name);
		printf("�绰��%s\n", pbook->_con_array[i]._tel);
		printf("��ַ��%s\n", pbook->_con_array[i]._address);
		printf("���䣺%d\n", pbook->_con_array[i]._age);
		printf("-----------------------------------------\n");

	}
}
Contact* ContactBookFind(ContactBook* pbook, const char * name)//����ͨѶ¼�����ϵ��
{
	assert(pbook&&name);
	size_t i = 0;
	//Contact* find_con_array;
	for (i = 0; i < pbook->_size; i++)
	{
		if (strcmp((pbook->_con_array[i]._name), name) == 0)
		{
			return  pbook->_con_array; //������ôʵ�� Ӧ�÷�������ΪContact*��������pbook��Con
		}                             
	}
	return NULL;
}
void ContactBookDelete(ContactBook* pbook, const char* name)//ɾ��ͨѶ¼�����Ϣ
{
	// ����˼·���ҵ�Ҫɾ�����Ǹ��˵���ͨѶ¼���λ�ã�Ȼ��������Ϣȫ����ǰ��һ����λ
	assert(pbook&&name);
	size_t i = 0;//ѭ������
	size_t k = 0;//������ʱ��������ס������ͬʱ����ʱ������ͨѶ¼���λ��
	if (ContactBookFind(pbook, name) == NULL)
	{
		printf("ͨѶ¼�����δ�鵽������ɾ���ɹ�");
		exit(-1);
	}
	else
	{
		for (i = 0; i < pbook->_size; i++)
		{
			if (strcmp(pbook->_con_array[i]._name, name) == 0)
				k = i;                                   //�ҳ�ͨѶ¼���ĸ�λ����Ҫɾ����
		}
		for (i = k; i < pbook->_size; i++)//�������Ϣ��ǰ����
		{
			strcpy(pbook->_con_array[i]._name, pbook->_con_array[i + 1]._name);
			strcpy(pbook->_con_array[i]._tel,  pbook->_con_array[i + 1]._tel);
			strcpy(pbook->_con_array[i]._address, pbook->_con_array[i + 1]._address);
			pbook->_con_array[i]._age = pbook->_con_array[i + 1]._age;

		}
		pbook->_size--;//��Ϊɾ����һ�������Ա����Ĵ洢��Χ��1��
	}
}
void ContactBookSave(ContactBook* pbook, const char* file)
{
	FILE* fp = fopen(file, "wb");//��������ʽ��д
	if (fp == NULL)
	{
		printf("���ļ�ʧ��");
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
		printf("���ļ�ʧ��\n");
		exit(-1);
	}
	Contact con;
	while (fread(&con, sizeof(Contact),1,fp) == 1)
	{
		ContactBookAppend(pbook, &con);
	}

	fclose(fp);
}