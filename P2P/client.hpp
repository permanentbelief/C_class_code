#pragma once
#include <thread>
#include <boost/filesystem.hpp>
#include  "util.hpp"
#include "httplib.h"

#define P2P_PORT 9000
#define MAX_IPBUFFER 16
#define MAX_RANGE (100*1024*1024) 
#define SHARED_PATH "./Shared"
#define DOWNLOAD_PATH "./Download/"

class Host
{
public:
	uint32_t _ip_addr; //Ҫ��Ե�������IP��ַ
	bool _pair_ret;  //���ڴ����Խ�����ɹ�����true,ʧ�ܷ���false
};

class Client
{
public:
	bool Start()
	{
		//�ͻ��˳�����Ҫѭ�����У���Ϊ�����ļ���ֹ������һ��
		while (1)
		{
			GetOnlineHost();
		}
		return true;
	}
	//������Ե��߳���ں���
	void HostPair(Host* host)
	{
		//1����֯httpЭ���ʽ����������
		//2���һ��tcp�Ŀͻ��ˣ������ݷ���
		//3���ȴ��������Ļظ��������н���
		host->_pair_ret = false;
		char buf[MAX_IPBUFFER] = { 0 };
		inet_ntop(AF_INET, &host->_ip_addr, buf, MAX_IPBUFFER);
		httplib::Client cli(buf, P2P_PORT);
		auto rsp = cli.Get("/hostpair");
		if (rsp && rsp->status == 200)  //�ж�����Ʋ�Խ��
		{
			host->_pair_ret = true;
		}
		return;
	}
	
	bool GetOnlineHost()
	{
		char ch='Y';  //�Ƿ�����ƥ�䣬Ĭ���ǽ���ƥ�䣬���Ѿ�ƥ�䣬online������Ϊ�գ������û�ѡ��
		if (!_online_host.empty())
		{
			std::cout << "�Ƿ����²鿴��������?��Y/N��";
			fflush(stdout);
			std::cin >> ch;
		}
		if (ch == 'Y')
		{
			std::cout << "��ʼ����ƥ��......\n";
			//1����ȡ������Ϣ�������õ������������е�IP��ַ�б�
			std::vector<Adapter> list;
			AdapterUtil::GetAllAdapter(&list);
			std::vector<Host> host_list;
			for (int i = 0; i < list.size(); i++) //�õ����е�����ip�б�
			{
				uint32_t ip = list[i]._ip_addr;
				uint32_t mask = list[i]._mask_addr;
				//���������
				uint32_t net = (ntohl(ip & mask));
				//�������������
				uint32_t max_host = (~ntohl(mask));
				for (int j = 1; (int32_t)j < max_host; j++)
				{
					uint32_t host_ip = net + j;//�������IP�ļ���Ӧ��ʹ�������ֽ��������ź�������
					Host host;
					host._ip_addr = htonl(host_ip);  //����������ֽ����IP��ַת���������ֽ���
					host._pair_ret = false;
					host_list.push_back(host);
				}
			}
			//��host_list�е����������߳̽������
			std::vector<std::thread*> thr_list(host_list.size());
			for (int i = 0; i < host_list.size(); i++)
			{
				thr_list[i] = new std::thread(&Client::HostPair, this, &host_list[i]);
			}
			std::cout << "�������������,���Ժ�......\n" ;
			//�ȴ������س����������ɣ��ж���Խ����������������ӵ�online_host��
			for (int i = 0; i < host_list.size(); i++)
			{
				thr_list[i]->join();
				if (host_list[i]._pair_ret == true)
				{
					_online_host.push_back(host_list[i]);
				}
				delete thr_list[i];
			}
		}
		//����������������ӡ���������û�ѡ��
		for (int i = 0; i < _online_host.size(); i++)
		{
			char buf[MAX_IPBUFFER] = { 0 };
			inet_ntop(AF_INET, &_online_host[i]._ip_addr, buf, MAX_IPBUFFER);
			std::cout << "\t" << buf << std::endl;
		}
		// 3�����������õ���Ӧ�����Ӧ����λ������������IP��ӵ�_online_host�б���
		// 4����ӡ���������б����û�ѡ��
		std::cout << "��ѡ�������������ȡ�����ļ��б�";
		fflush(stdout);
		std::string select_ip;
		std::cin >> select_ip;
		GetShareList(select_ip);  //�û�ѡ�������󣬵��û�ȡ�ļ��б�ӿ�
		return true;
	}
	
	//��ȡ�ļ��б�
	bool GetShareList(const std::string &host_ip)
	{
	//�����������һ���ļ��б��ȡ����
	//1���ȷ�������
	//2���õ���Ӧ֮�󣬽�������
		httplib::Client cli(host_ip, P2P_PORT);
		auto rsp = cli.Get("/list");
		if (rsp == NULL || rsp->status != 200)
		{
			std::cerr << "��ȡ�ļ��б���Ӧ����\n";
			return false;
		}
		//��ӡ����--��ӡ��������Ӧ���ļ������б��û�ѡ��
		//body:filename1\r\nfilename2...
		std::cout << rsp->body << std::endl;
		std::cout << "\n��ѡ��Ҫ���ص��ļ���" ;
		fflush(stdout);
		std::string filename;
		std::cin >> filename;
		RangeDownload(host_ip, filename);
		return true;
	}
	//�����ļ�
	bool DownloadFile(const std::string &host_ip, const std::string&filename)
	{
		//1\�����˷����ļ���������
		//2\�õ���Ӧ�������Ӧ����е�body���ľ����ļ�����
		//3�������ļ������ļ�����д���ļ��У��ر��ļ�
		std::string req_path = "/download/" + filename;
		httplib::Client cli(host_ip,P2P_PORT);
		//std::cout << "������������ļ���������" <<host_ip<<":"<< req_path << std::endl;
		auto rsp = cli.Get(req_path.c_str());
		if (rsp == NULL || rsp->status != 200)
		{
			std::cout << "�����ļ�����ȡ��Ӧ��Ϣʧ��\n"<<rsp->status<<std::endl;
			return false;
		}
		if (boost::filesystem::exists(DOWNLOAD_PATH))
		{
			boost::filesystem::create_directory(DOWNLOAD_PATH);
		}
		std::string realpath = DOWNLOAD_PATH + '/' + filename;
		if (FileUtil::Write(realpath, rsp->body) == false)
		{
			std::cerr << "�ļ�����ʧ��\n";
			return false;
		}
		std::cout << "�ļ����سɹ���" << std::endl;
		return true;
	}
	bool RangeDownload(const std::string &host_ip, const std::string &name)
	{
		//1������head����ͨ����Ӧ�е�Content-Length��ȡ�ļ���С
		std::string req_path = "/download/" + name;
		httplib::Client cli(host_ip, P2P_PORT);
		auto rsp = cli.Head(req_path.c_str());
		if (rsp == NULL || rsp->status != 200)
		{
			std::cout << "��ȡ�ļ���С��Ϣʧ��\n";
			return false;
		}
		std::string clen = rsp->get_header_value("Content-Length");
		int64_t filesize = StringUtil::Str2Dig(clen);
		//2�������ļ���С���зֿ�
		//int range_count=filesize/MAX_RANGE
		// ���ļ���СС�ڿ��С��ֱ�ӽ�������
		if (filesize < MAX_RANGE)
		{
			std::cout << "�ļ���С��ֱ�������ļ�\n";
			return DownloadFile(host_ip, name);
		}
		// ���ļ���С����������,��ҿ���������ļ���С���Էֿ����Ȼ��+1
		std::cout << "�ļ����󣬷ֿ��������\n";
		int range_count = 0;
		if ((filesize % MAX_RANGE) == 0)
		{
			range_count = filesize / MAX_RANGE;
		}
		else
		{
			range_count = (filesize / MAX_RANGE) + 1;
		}
		int64_t range_start = 0, range_end = 0;
		for (int i = 0; i < range_count; i++)
		{
			range_start = i * MAX_RANGE;
			if (i == (range_count - 1))  //ĩβ�ֿ�
			{
				range_end = filesize - 1;
			}
			else
			{
				range_end = ((i + 1)*MAX_RANGE) - 1;
			}
			std::cout << "�ͻ�������ֿ飺" << range_start << "-" << range_end << std::endl;
			//3����һ����ֿ����ݵõ���Ӧ֮��д���ļ���ָ��λ��
			std::stringstream tmp;
			tmp << "bytes=" << range_start << "-" << range_end;   //��֯һ��rangeͷ��Ϣ������ֵ
			httplib::Headers header;
			header.insert(std::make_pair("Range", tmp.str())); 
			header.insert(httplib::make_range_header({ {range_start,range_end} }));
			httplib::Client cli(host_ip.c_str(), P2P_PORT);
			//httplib::Headers header;
			//header.insert(std::make_pair("Range", tmp.str()));
			auto rsp=cli.Get(req_path.c_str(), header);
			// ���ļ���С��������,��ҿ���������ļ���С���Էֿ����
			if (rsp == NULL || rsp->status != 206)
			{
				std::cout << "��������ʧ��\n";
				return false;
			}
			std::cout << "�ͻ��˷ֿ�д���ļ�"<<range_start<<"-"<<range_end<<std::endl;
			FileUtil::Write(name, rsp->body, range_start);
			std::cout << "�ͻ��˷ֿ�д���ļ� �ɹ�\n"; 
		}
		std::cout << "�ļ����سɹ�\n";
		return true;
	}
private:
	std::vector<Host> _online_host;
};

class Server
{
public:
	bool Start()
	{
		//�����Կͻ���������ʽ��Ӧ��ϵ��
		_srv.Get("/hostpair", HostPair);
		_srv.Get("/list", ShareList);
		_srv.Get("/download/.*",Download); //������ʽ 
		_srv.listen("0.0.0.0", P2P_PORT);
		return true;
	}
private:
	static void HostPair(const httplib::Request &req, httplib::Response &rsp)
	{
		rsp.status = 200;
		return;
	}
	//��ȡ�����ļ��б�--����������һ������Ŀ¼���������Ŀ¼�µĶ�Ҫ���������
	static void ShareList(const httplib::Request &req, httplib::Response &rsp)
	{
		//1���鿴Ŀ¼�Ƿ���ڣ���Ŀ¼�����ڣ��򴴽�Ŀ¼
		if (boost::filesystem::exists(SHARED_PATH))
		{
			boost::filesystem::create_directory(SHARED_PATH);
		}
		boost::filesystem::directory_iterator begin(SHARED_PATH);  //ʵ����Ŀ¼������
		boost::filesystem::directory_iterator end;  //ʵ����Ŀ¼��������ĩβ
		//��ʼ����Ŀ¼
		for (; begin != end; ++begin)
		{
			if (boost::filesystem::is_directory(begin->status()))
			{
				//��ǰ�汾����ֻ��ȡ��ͨ�ļ�
				continue;
			}
			std::string name = begin->path().filename().string();
			rsp.body += name + "\r\n";
		}
		rsp.status = 200;
		return;
	}
	static void Download(const httplib::Request &req, httplib::Response &rsp)
	{
		//std::cout << "������ܵ��ļ���������" << req.path << std::endl;
			//req_path--�ͻ����������Դ·��
		boost::filesystem::path req_path(req.path);
		std::string name = req_path.filename().string();
		//std::cout << "������յ���ʵ���ļ��������ƣ�" << name << "·����" << SHARED_PATH << std::endl;
		std::string realpath = SHARED_PATH + '/' + name;  //ֻ��ȡ�ļ�����

		//boost::filesystem::exist() �ж��ļ��Ƿ����
		//std::cout << "������յ���ʵ���ļ�����·��" << realpath<<std::endl;
		if (!boost::filesystem::exists(realpath) || boost::filesystem::is_directory(realpath))
		{
			rsp.status = 404;
			return;
		}
		if (req.method == "GET")
		{
			//��ǰ��GET���󣬾���ֱ�����������ļ����������ڲ�һ���ˣ��������˷ֿ鴫���������
			//�ж��Ƿ��Ƿֿ鴫������ݣ���������������Ƿ���Rangeͷ���ֶ�
			if (req.has_header("Range"))
			{
				//�����һ���ֿ鴫��
				//��Ҫ֪���ֿ������Ƕ���
				std::string range_str = req.get_header_value("Range");  //bytes=start-end;
				httplib::Ranges ranges;   //
				httplib::detail::parse_range_header(range_str,ranges);
				int64_t range_start = ranges[0].first;
				int64_t range_end = ranges[0].second;
				int64_t range_len = range_end - range_start + 1;
				std::cout <<realpath<< ":range:" << range_start << "-" << std::endl;
				FileUtil::ReadRange(realpath, &rsp.body, range_len, range_start);
				rsp.status = 206;
				std::cout << "�������Ӧ������ϣ�" << std::endl;
			}
			else
			{
				//û��Range�ֶΣ�����һ���������ļ�����
				if (FileUtil::Read(realpath, &rsp.body) == false);//ʵ���ļ���·��Ӧ���ǹ����
				{
					rsp.status = 500;
					return;
				}
				rsp.status = 200;
			}
		}
		else  //��������HEAD�����--�ͻ���ֻҪͷ����Ҫ����
		{
			int64_t filesize = FileUtil::GetFileSize(realpath);
			rsp.set_header("Content-Length", std::to_string(filesize));  //������Ӧͷ����Ϣ
			rsp.status = 200;
		}
		
		return;
	}
private:
	httplib::Server _srv;
};














