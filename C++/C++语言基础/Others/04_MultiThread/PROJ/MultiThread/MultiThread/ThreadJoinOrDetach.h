#pragma once

#include <thread>

class Obj
{
public:
	Obj() { std::cout << "hello" << std::endl; }
	~Obj() { std::cout << "hakuno" << std::endl; }
};

class ThreadGuard
{
public:
	ThreadGuard(std::thread& t) : m_thread(t) {}
	~ThreadGuard() 
	{
		if (m_thread.joinable())
			m_thread.join();
	}

private:
	std::thread& m_thread;
};

void joinWorker() {}

void detachWorker()
{
	Obj obj;
	std::this_thread::sleep_for(std::chrono::seconds(1)); // �����̽�����obj����δִ�С�
}

void ThreadJoinOrDetach()
{
	Obj obj;

	std::thread j(joinWorker);
	ThreadGuard guard(j);

	std::thread d(detachWorker);
	d.detach(); // �߳�������ɺ��Զ����ա����޷�join()��

	//if (j.joinable()) 
	//	j.join(); // abort(errorcode); ʹ��abort��ֹ����

	if (d.joinable())
		d.join(); 
}