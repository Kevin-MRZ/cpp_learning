#include <iostream>

#include "Log.h"

static Log myLog(1, "log.log"); // static���ں������⣬ʵ��д�����ݣ�hello hakuno

void test1()
{
	// ��ȡ�ļ�ָ��ͷ��д���ļ�������ʵ���ڻ����У���δ����д�뵽�ļ���
	//static Log myLog(1, "log.log"); // static ������main���������������ȹ���������������
	myLog.logInfo("hello ");
}

void test2()
{
	// ��ȡ�ļ�ָ��ͷ����test1��ȡ���ļ�ָ��ͷ��ͬ��������hello��hakuno���ǡ�
	//static Log myLog(2, "log.log");
	myLog.logInfo("hakuno ");
}

int main()
{
	test1();
	test2();
	// Choose answer��
	//		hello			�ֲ�myLog	
	//		hakuno			�ֲ�myLog + flush
	//		hello hakuno	ȫ��myLog + flush
	//		hakuno hello	�޴������
	std::cout << "\nBye Main " << std::endl;
}