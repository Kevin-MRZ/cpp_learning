#pragma once

#include <iostream>
#include <thread>
#include <future>

void printString(const std::string& info1, const std::string& info2)
{
	std::cout << "3HAKUNO " << info1 << " " << info2 << std::endl;
}

void printAll(int a, int b, int c)
{
	std::cout << a << " " << b << " " << c << std::endl;
}

void add(int a, int b, int& c)
{
	c = a + b;
}

void ThreadInit()
{
	int a = 3;
	int b = 4;
	int c = 5;

	std::thread t1([=] { printAll(a, b, c); });
	t1.join();
	std::thread t2(printAll, a, b, c);
	t2.join();
	// �̣߳��󶨺��������ݲ�����
	std::thread t3([=, &c] { add(a, b, c); }); // Lambda a��b��ֵ c�����á�
	t3.join();

	std::thread t4(add, a, b, std::ref(c)); // ��Lambda��ȡc�����ã�std::ref() ��������
	t4.join();

	std::string abc("abc");
	std::string def("def");

	std::thread t5([&] { printString(abc, def); }); // Lambda��ʽ
	t5.join();

	std::thread t6(printString, abc, def); // ��Lambda����ֵ��������
	t6.join();

	std::thread t7(printString, std::cref(abc), std::cref(def)); // ��Lambda���������ã�std::cref() const����
	t7.join();
}
