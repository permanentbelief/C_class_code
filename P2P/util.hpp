#pragma once
#include <stdio.h>
#ifdef _WIN32
//windowsͷ�ļ�
#include <iostream>
#include <WS2tcpip.h>
#include <fstream>
#include <sstream>
#include <boost/filesystem.hpp>
#include <vector>
#include <Iphlpapi.h>  //��ȡ������Ϣ�ӿڵ�ͷ�ļ�
#pragma comment(lib,"Iphlpapi.lib")  //��ȡ������Ϣ�ӿڵĿ��ļ�����
#pragma comment(lib,"ws2_32.lib")  //windows�µ�socket��

#else
//linuxͷ�ļ�
#endif

class StringUtil
{
public:
	static int64_t Str2Dig(const std::string &num)
	{
		std::stringstream tmp;
		tmp << num;
		int64_t res;
		tmp >> res;
		return res;

	}
};


class FileUtil
{
public:
	static int64_t GetFileSize(const std::string &name)
	{
		return boost::filesystem::file_size(name);
	}
	static bool Write(const std::string &name, const std::string &body, int64_t offset=0)
	{
		FILE *fp = NULL;
		fopen_s(&fp, name.c_str(), "wb+");
		if (fp == NULL)
		{
			std::cerr << "���ļ�ʧ��\n";
			return false;
		}
		fseek(fp, offset, SEEK_SET);
		int ret = fwrite(body.c_str(), 1, body.size(), fp);
		if (ret != body.size())
		{
			std::cerr<< "���ļ�д������ʧ��\n";
			fclose(fp);
			return false;
		}
		fclose(fp);
		return true;
		//std::cout << "д���ļ�����:" << name << "size:" << body.size << "\n";
		//std::ofstream ofs(name);
		//if (ofs.is_open() == false)
		//{
		//	std::cerr << "���ļ�ʧ��\n";
		//	return false;
		//}
		//ofs.seekp(offset, std::ios::beg);  //��дλ�õ�ת��������ļ���ʼλ�ÿ�ʼƫ��offset
		//ofs.write(&body[0], body.size());
		//if (ofs.good() == false)
		//{
		//	std::cerr << "���ļ�д��ʧ��\n";
		//	ofs.close();
		//	return false;
		//}
		//ofs.close();
		//return true;
	}
	//ָ�������ʾ����һ������Ͳ���
	//const & ��ʾ����һ�������Ͳ���
	static bool Read(const std::string &name, std::string *body)
	{
		int64_t filesize = boost::filesystem::file_size(name);
		body->resize(filesize);
		std::cout << "��ȡ�ļ����ݣ�" << name << "size:" << filesize << "\n";
		FILE *fp = NULL;
		fopen_s(&fp,name.c_str(), "rb+");
		if (fp == NULL)
		{
			std::cerr << "���ļ�ʧ��\n";
			return false;
		}
		int ret = fread(&(*body)[0], 1, filesize, fp);
		if (ret != filesize)
		{
			std::cerr << "���ļ���ȡ����ʧ��\n";
			fclose(fp);
			return false;
		}
		fclose(fp);
		return true;
		
		/*
		std::ifstream ifs(name);
		if (ifs.is_open == false)
		{
			std::cerr << "���ļ�ʧ��\n";
			return false;
		}
    	
		//std::cout << "Ҫ��ȡ���ļ���С" << name << ":" << filesize << std::endl;
		ifs.read(&(*body)[0], filesize);
		if (ifs.good() == false)
		{
			std::cerr << "��ȡ�ļ�����ʧ��\n";
			ifs.close();
			return false;
		}
		ifs.close();
		return true;*/
	}
	static bool ReadRange(const std::string &name, std::string *body, int64_t len, int64_t offset)
	{
		body->resize(len);
		FILE *fp = NULL;
		fopen_s(&fp, name.c_str(), "rb+");
		if(fp==NULL)
		{
			std::cerr << "���ļ���ȡ����ʧ��\n";
			return false;
		}
		fseek(fp, offset, SEEK_SET);
		int ret = fread(&(*body)[0], 1, len, fp);
		if (ret != len)
		{
			std::cerr << "���ļ���ȡ����ʧ��\n";
			fclose(fp);
			return false;
		}
		fclose(fp);
		return true; 
	}
};


class Adapter
{
public:
	uint32_t _ip_addr;  //�����ϵ�IP��ַ
	uint32_t _mask_addr;  //�����ϵ���������
};

class AdapterUtil
{
public:
#ifdef _WIN32
	//windows�»�ȡ��������Ϣʵ��
	static bool GetAllAdapter(std::vector<Adapter> *list)
	{
		PIP_ADAPTER_INFO p_adapters = new IP_ADAPTER_INFO();
		
		//GetAdaptersInfo win�»�ȡ������Ϣ�Ľӿ�--������Ϣ�����ж��
		//��ȡ������Ϣ�п��ܻ�ʧ�ܣ���Ϊ�ռ䲻�㣬�����һ������Ͳ���
		uint64_t all_adapter_size = sizeof(IP_ADAPTER_INFO);
		int ret = GetAdaptersInfo(p_adapters, (PULONG)&all_adapter_size);
		if (ret == ERROR_BUFFER_OVERFLOW) //��������ʾ�������ռ䲻��
		{
			//���¸�ָ������ռ�
			delete p_adapters;
			p_adapters = (PIP_ADAPTER_INFO)new BYTE[all_adapter_size];
			//���»�ȡ������Ϣ
			GetAdaptersInfo(p_adapters, (PULONG)&all_adapter_size);
		}

		while (p_adapters)
		{
			std::cout << "�������ƣ�" << p_adapters->AdapterName << std::endl;
			std::cout << "����������" << p_adapters->Description << std::endl;
			std::cout<<"IP��ַ��"<<p_adapters->IpAddressList.IpAddress.String<<std::endl;
			std::cout << "�������룺" << p_adapters->IpAddressList.IpMask.String << std::endl;
			std::cout << std::endl;
			p_adapters = p_adapters->Next;
		}
		return true;
	}
#else
//linux�»�ȡ������Ϣʵ��
bool GetAllAdapter(std::vector<Adapter>*list)
{
	return true;
}
#endif
};
