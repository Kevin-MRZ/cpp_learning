#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

/*
--------------------------------------------------
类模板分文件编写问题：
	类模板函数成员并非初始时创建，导致链接阶段无法
	查找到类模板成员函数实现（链接失败）。
	
解决方法：
	类模板不编写.cpp实现文件，类模板及成员函数实现
	都在.h文件中（主程序引入头文件）。

--------------------------------------------------
*/