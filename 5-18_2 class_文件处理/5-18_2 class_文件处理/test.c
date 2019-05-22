#define _CRT_SECURE_NO_WARNINGS 1 
#include <stdio.h>
#include "contact.h"
int main()
{
	ContactBook  cb;//定义了一个通讯录
	ContactBookInit(&cb);//初始化通讯录
	Contact con1;// 定义一个通讯联系人
	strcpy(con1._name, "peter");//通讯人 ----  姓名
	strcpy(con1._address, "西安未央区浐灞半岛");//通讯人 --- 地址
	strcpy(con1._tel, "18241321212");//  通讯人 --- 电话号码
	con1._age = 18;//  通讯人 --- 年龄
	ContactBookAppend(&cb, &con1); // 将 通讯人添加到 通讯录
	//ContactBookprint(&cb);// 打印 通讯录 内容

	// 删除通讯录里的内容
	//ContactBookDelete( &cb,"peter");
	//打印
	//ContactBookprint(&cb);

	Contact con2;//定义第二个联系人
	strcpy(con2._name, "shuhzuoyue");//通讯人 ----  姓名
	strcpy(con2._address, "西安未央区浐灞半岛");//通讯人 --- 地址
	strcpy(con2._tel, "13663898981");//  通讯人 --- 电话号码
	con2._age = 34;
	ContactBookAppend(&cb, &con2);// 将第二个联系人加入通讯录
	

	//删除通讯录里的信息
	ContactBookDelete( &cb,"peter");

	printf("%s\n", ContactBookFind(&cb, "peter"));

	ContactBookprint(&cb);

	system("pause");

}