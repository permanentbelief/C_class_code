#define _CRT_SECURE_NO_WARNINGS 1 
#include <stdio.h>
#include "contact.h"
int main()
{
	ContactBook  cb;//������һ��ͨѶ¼
	ContactBookInit(&cb);//��ʼ��ͨѶ¼
	Contact con1;// ����һ��ͨѶ��ϵ��
	strcpy(con1._name, "peter");//ͨѶ�� ----  ����
	strcpy(con1._address, "����δ������屰뵺");//ͨѶ�� --- ��ַ
	strcpy(con1._tel, "18241321212");//  ͨѶ�� --- �绰����
	con1._age = 18;//  ͨѶ�� --- ����
	ContactBookAppend(&cb, &con1); // �� ͨѶ����ӵ� ͨѶ¼
	//ContactBookprint(&cb);// ��ӡ ͨѶ¼ ����

	// ɾ��ͨѶ¼�������
	//ContactBookDelete( &cb,"peter");
	//��ӡ
	//ContactBookprint(&cb);

	Contact con2;//����ڶ�����ϵ��
	strcpy(con2._name, "shuhzuoyue");//ͨѶ�� ----  ����
	strcpy(con2._address, "����δ������屰뵺");//ͨѶ�� --- ��ַ
	strcpy(con2._tel, "13663898981");//  ͨѶ�� --- �绰����
	con2._age = 34;
	ContactBookAppend(&cb, &con2);// ���ڶ�����ϵ�˼���ͨѶ¼
	

	//ɾ��ͨѶ¼�����Ϣ
	ContactBookDelete( &cb,"peter");

	printf("%s\n", ContactBookFind(&cb, "peter"));

	ContactBookprint(&cb);

	system("pause");

}