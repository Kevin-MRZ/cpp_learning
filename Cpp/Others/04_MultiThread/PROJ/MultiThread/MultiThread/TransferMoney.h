/*
* ת�ˣ�
*/

#pragma once

#include <iostream>
#include <thread>
#include <mutex>
#include <future>
#include <cstdlib>

struct BankAccount
{
	BankAccount(int b) : Balance(b) {}
	int Balance;
	std::mutex Mutex;
};

void transferMoney(BankAccount& a, BankAccount& b, int money)
{
	if (&a == &b)
		return;	// ������߳��£�a==b��ɵ�������

	std::lock(a.Mutex, b.Mutex /*...*/);// �����������ض�˳����ȫ�������ټ������¡�
	std::lock_guard<std::mutex> lockA(a.Mutex, std::adopt_lock); // ��������ֻ����������������
	std::lock_guard<std::mutex> lockB(b.Mutex, std::adopt_lock);
	if (a.Balance < money) return;
	a.Balance -= money;
	b.Balance += money;

	//if (&(a.Mutex) < &(b.Mutex))// ������߳�����ɵ�������
	//{
	//	std::lock_guard<std::mutex> lockA(a.Mutex);
	//	std::lock_guard<std::mutex> lockB(b.Mutex);
	//	if (a.Balance < money) return;
	//	a.Balance -= money;
	//	b.Balance += money;
	//}
	//else
	//{
	//	std::lock_guard<std::mutex> lockA(b.Mutex);
	//	std::lock_guard<std::mutex> lockB(a.Mutex);
	//	if (a.Balance < money) return;
	//	a.Balance -= money;
	//	b.Balance += money;
	//}
	std::cout << a.Balance << " " << b.Balance << std::endl;
}

void TransferMoneyTest()
{
	BankAccount teemo(500);
	BankAccount yasuo(500);

	// ���߳��£���a==b�������������
	transferMoney(teemo, teemo, 75);

	// ���߳��£�thread 1 �� thread 2 ͬʱ�����������������
	//transferMoney(teemo, yasuo, 15);
	std::thread thread1([&] { transferMoney(teemo, yasuo, 15); });
	//transferMoney(yasuo, teemo, 15);
	std::thread thread2([&] { transferMoney(yasuo, teemo, 15); });

	thread1.join();
	thread2.join();
}