#pragma once

#include <iostream>

class Object
{
public:
	Object() { std::cout << "class Object ����" << std::endl; }
	~Object() { std::cout << "class Object ����" << std::endl; }
	int getValue() { return m_Value; }
private:
	int m_Value = 1;
};