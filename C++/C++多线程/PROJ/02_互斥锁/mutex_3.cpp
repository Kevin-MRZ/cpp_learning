/*
    文件：mutex_3.cpp
    功能：通过lock_guard与unique_lock保护共享资源

    编译：g++ -Wall -g -std=c++11 -pthread mutex_3.cpp -o mutex_3
*/

#include <iostream> 
#include <thread>
#include <mutex>
#include <chrono>

std::chrono::milliseconds interval(100);

std::timed_mutex tmutex;
// 多线程共享的全局变量，多线程操作，使用mutex保护
int job_shared = 0; 
// 单线程独占的全局变量，无需mutex保护
int job_exclusive = 0;

void job_1()
{
    std::lock_guard<std::timed_mutex> lockg(tmutex);
    // 持锁等待
    std::this_thread::sleep_for(5 * interval);  
    ++job_shared;
    std::cout << "job_1 shared (" << job_shared << ")\n";
}

void job_2()
{
    while (true) 
    {    
        // 无限循环，尝试获得锁（策略：暂不锁定）
        std::unique_lock<std::timed_mutex> ulock(tmutex, std::defer_lock);
        if (ulock.try_lock_for(3 * interval)) 
        {     
            // 尝试获得锁成功则修改'job_shared'
            ++job_shared;
            std::cout << "job_2 shared (" << job_shared << ")\n";
            return;
        }
        else 
        {      
            // 尝试获得锁失败则修改'job_exclusive'
            ++job_exclusive;
            std::cout << "job_2 exclusive (" << job_exclusive << ")\n";
            std::this_thread::sleep_for(interval);
        }
    }
}

int main()
{
    std::thread thread_1(job_1);
    std::thread thread_2(job_2);

    thread_1.join();
    thread_2.join();

#ifdef WIN32
    system("pause");
#endif

    return 0;
}