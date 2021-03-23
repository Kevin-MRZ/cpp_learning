#include "Log.h"

#include <iostream>
#include <cstdlib>
#include <fstream>

Log::Log(int id, const std::string& filename) : m_id(id)
{
	std::cout << "Creat " << m_id << std::endl;
	m_f.open(filename.c_str(), std::fstream::out);
}

Log::~Log()
{
	std::cout << "Bye " << m_id << std::endl;
	//m_f.close();
}

void Log::logInfo(const std::string& info)
{
	std::cout << info;
	m_f << info;
	m_f.flush();
	// myLogΪȫ�ֱ�����
	// myLogΪ�ֲ�������flush����д�루����hello������Ϊhakuno������������˳��д��(����hakuno������Ϊhello)��
}