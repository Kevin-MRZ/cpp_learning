#pragma once

#include <iostream>
#include <thread>
#include <chrono>
#include <future>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <atomic>
#include <mutex>

/*
================================================================================
��������쳣��
	1.���̵߳���������
	2.ԭ�Ӳ������͡�
	3.mutex��������
	4.lock_guard�ࡣ
================================================================================
*/

// Lock ģ���ࣺ�Զ��Ӽ���������쳣��ɵ�Ӱ�졣STL�ṩstd::lock_guard
/*
	template<typename T>
	class Lock
	{
	public:
		Lock(T& mutex) :m_mutex(mutex) { m_mutex.lock(); }
		~Lock() { m_mutex.unlock(); }
	private:
		T& m_mutex;
	};
*/

class Counter
{
public:
	Counter() : m_count(0), m_totalResource(0) {}
	~Counter() {}
	int getCount()
	{
		std::lock_guard<std::mutex> lock(m_mutex);
		return m_count;
	}
	int getAverageResource()
	{
		std::lock_guard<std::mutex> lock(m_mutex);
		if (m_count == 0)
			return 1;
		auto r = m_totalResource / m_count;
		return r;
	}
	void addCount() { ++m_count; }
	void addResource() { m_totalResource++; }
	void addCountAndResource()
	{
		std::lock_guard<std::mutex> lock(m_mutex);
		addCount();
		addResource();
	}

private:
	int m_count;
	int m_totalResource;
	//std::atomic<int> m_count; // ԭ���͵�m_count��
	//std::atomic<int> m_totalResource;
	std::mutex m_mutex;
};

int work(int a)
{
	// do something
	return a + a;
}

//void debugPrintInfo(Counter& c)
//{
//	std::mutex m_mutex;
//	std::lock_guard<std::mutex> lock(m_mutex);
//	std::cout << c.aveResource() << std::endl;
//}

void doSomeThing()
{
	if (rand() % 10 == 0)
		throw 1;
}

template<class Iter>
void realWork(Counter& c, double& totalValue, Iter b, Iter e)
{
	for (; b != e; ++b)
	{
		try
		{
			totalValue += work(*b);
			c.addCountAndResource();
			//doSomeThing(); // �׳��쳣��
		}
		catch (const std::exception&)
		{
		}
	}
}

bool printStep(Counter& c, int maxCount)
{
	auto count = c.getCount();
	if (count == maxCount)
	{
		std::cout << "Finished, right count is " << count << std::endl;
		return true;
	}
	return false;
}

void SharedVariable()
{
	std::vector<int> vec;
	for (int i = 0; i < 1000000; i++)
		vec.push_back(rand() % 100);


	//// ���̼߳���
	//auto nowc1 = clock();
	//Counter counterST;
	//double totalValueST = 0.0;
	//for (auto& v : vec)
	//{
	//	totalValueST += work(v);
	//	counterST.addCount();
	//}
	//auto finishc1 = clock();
	//std::cout << "totalCount by singlethread: " << counterST.getCount()  << " totalValue by singlethread: " << totalValueST << " Spend time: " << finishc1 - nowc1 << std::endl;
	//
	// ���̼߳���
	auto nowc2 = clock();
	double totalValueMT = 0.0;

	Counter counterMT;

	//std::thread printCount([&counterMT] { while (!printStep(counterMT, 1000000)); }); // ��̨�̣߳���鵱ǰcount
	std::thread printCount
	(
		[&counterMT]
		{
			bool Flag = false;
			while (!Flag)
			{
				std::mutex m_mutex;
				m_mutex.lock();
				Flag = printStep(counterMT, 1000000);
				m_mutex.unlock();
			}
		}
		); // ��̨�̣߳���鵱ǰcount

	auto iterBegin = vec.begin();
	auto iterEnd = vec.end();
	auto iter1 = vec.begin() + (vec.size() / 3);
	auto iter2 = vec.begin() + (vec.size() / 3) * 2;

	std::thread b([&counterMT, &totalValueMT, iter1, iter2] { realWork(counterMT, totalValueMT, iter1, iter2); });
	std::thread c([&counterMT, &totalValueMT, iter2, iterEnd] { realWork(counterMT, totalValueMT, iter2, iterEnd); });
	realWork(counterMT, totalValueMT, iterBegin, iter1);

	b.join();
	c.join();
	auto realTotalValue = totalValueMT;
	auto realTotalCount = counterMT.getCount();
	auto finishc2 = clock();
	std::cout << "totalCount by multithread: " << realTotalCount << "\ntotalValue by multithread: " << realTotalValue << "\nSpend time: " << finishc2 - nowc2 << std::endl;
	printCount.join();
}


template<typename T>
class Lock
{
public:
	Lock(T& m) : m_mutex(m) { m_mutex.lock(); }
	~Lock() { m_mutex.unlock(); }
private:
	T& m_mutex;
};