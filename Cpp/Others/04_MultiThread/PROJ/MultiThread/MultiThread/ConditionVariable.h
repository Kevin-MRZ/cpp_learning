#pragma once

#include <iostream>
#include <atomic>
#include <chrono>
#include <thread>
#include <mutex>
#include <string>
#include <cstdlib>
#include <list>
#include <vector>
#include <ctime>
#include <cstring>
#include <condition_variable>

class Message
{
public:
	Message(std::string d = std::string()) : m_data(std::move(d)) {}
	~Message() {}
	const std::string& data() const { return m_data; }
private:
	std::string m_data;
};

std::atomic<int> totalSize{ 0 };

std::mutex mutex;

std::condition_variable cv;
std::atomic<bool> ready{ false };
bool quit{ false };
std::list<Message> globalList;

void worker(int i)
{
	while (!ready) {}
	Message msg;
	while (!quit)
	{
		std::unique_lock<std::mutex> lock(mutex);
		cv.wait(lock, [] { return quit || !globalList.empty(); }); // �ͷ�lock������������ �˳� �� �ǿ� �� ���»�ȡ������������ִ�У���������ȴ���
		if (quit)
		{
			return;
		}
		auto iter = globalList.begin();
		msg = std::move(*iter);
		globalList.erase(iter);
	}
	totalSize += strlen(msg.data().c_str());
}

void ConditionVariable()
{
	//const auto threadCount = 4;
	//std::vector<std::thread> pool;
	//for (int i = 0; i < threadCount; ++i)
	//	pool.emplace_back(worker, i);
	//// ��ǰ�������ߡ�
	//std::this_thread::sleep_for(std::chrono::seconds(15)); 
	//ready = true;

	//for (auto& v : pool)
	//{
	//	if (v.joinable())
	//	{
	//		v.join();
	//	}
	//}

	const auto threadCount = 4;
	for (int i = 0; i < 500000; i++)
		globalList.push_back("this is a test" + std::to_string(i));
	std::vector<std::thread> pool;
	for (int i = 0; i < threadCount; ++i)
		pool.emplace_back(worker, i);
	ready = true;
	for (int i = 0; i < 300000; i++)
	{
		//std::this_thread::sleep_for(std::chrono::milliseconds(1)); // ����ʱ����ࡣ
		std::lock_guard<std::mutex> lock(mutex);
		globalList.push_back(std::string("second"));
		cv.notify_one(); // ����һ���̡߳�
	}

	while (true)
	{
		std::lock_guard<std::mutex> lock(mutex);
		if (globalList.empty())
		{
			quit = true;
			cv.notify_all(); // ����ȫ���̡߳�
			break;
		}
	}
	for (auto& v : pool)
	{
		if (v.joinable())
		{
			v.join();
		}
	}

	std::cout << "Bye" << std::endl;
}