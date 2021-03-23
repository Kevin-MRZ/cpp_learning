#include <iostream>
#include <thread>
#include <chrono>
#include <future>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <ctime>

#include "CaculateByMultithread.h"
#include "ThreadInit.h"
#include "SharedVariable.h"
#include "TransferMoney.h"
#include "ThreadJoinOrDetach.h"
#include "ConditionVariable.h"

/*
================================================================================

https://blog.csdn.net/qq_38231713/category_10001159.html

�����̣߳�std::thread threadName(func);
�߳����ߣ�std::this_thread::sleep_for(std::chrono::milliseconds(10));
��ȡ��ǰ�߳�ID��std::this_thread::get_id();
Ӳ��֧�ֲ�������std::thread::hardware_concurrency();
�̲߳������ݣ�std::thread threadName([=, &c] { add(a, b, c); });
			�� std::thread t4(add, a, b, std::ref(c));

ԭ�Ӳ����������ͣ�std::atomic_int m_count; �����̷߳��ʽ���Դ���	
��������Mutex����std::mutex m_mutex; lock()��unlock()�ɶԳ��֡�
�Խ�����lock_guard��������ֲ�����ʱ���������죩�����ö���������ʱ��������������

��˳�������std::lock(a.Mutex, b.Mutex);// �����������ض�˳����ȫ�������ټ������¡�
�ȴ�������std::lock_guard<std::mutex> lockA(a.Mutex, std::adopt_lock); // ��������ֻ����������������
		 std::lock_guard<std::mutex> lockB(b.Mutex, std::adopt_lock);
�����̣߳�threadName.join();
�߳��Զ����գ�threadName.detach();
�̷߳���ִ�У�std::this_thread::yield(); �൱��Sleep()������CPUʱ��Ƭ�����������߳�ִ�У������̱߳�����
			������Ƶ�����ĳ�������Ƿ������
����������std::condition_variable
���std::condition_variableʹ�ã�std::unique_lock��
condition_variable.wait(lock, ����)���ͷ�lock������������ɺ����»�ȡ����


��ȡʱ�䣺clock();
================================================================================
*/

void helloWorld()
{
	std::cout << "hello world" << std::endl;
}

void TestMultithread()
{
	std::thread t(helloWorld);
	std::cout << "hello main thread" << std::endl;
	t.join();
}

void GetSupportedThreads()
{
	 //Ӳ��֧�ֲ�����
	unsigned int n = std::thread::hardware_concurrency(); // 12
	std::cout << n << " concurrent threads are supported.\n" << std::endl;
}

int main()
{
	//TestMultithread();
	//GetSupportedThreads();

	//CalByMultiThread();
	//ThreadInit();
	//SharedVariable();
	//TransferMoneyTest();
	//ThreadJoinOrDetach();
	ConditionVariable();


	return 0;
}