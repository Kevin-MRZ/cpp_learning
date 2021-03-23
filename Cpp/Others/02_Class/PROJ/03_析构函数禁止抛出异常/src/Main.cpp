#include <iostream>

class A
{
public:
	A() {}
	//~A() {}
};

class B : public A
{
public:
	B() {}

	// Ĭ�����ɵ���������Ϊ�������������ڵ��ô�չ����
	// ��������ִ��ʱ���ȵ��ó�Ա�����������ٵ�����������������������ʹ�������������³����쳣���š�
	// �����Ҫ�Լ�������ʱ��������������ʵ���ļ���ʵ�֡�
	~B () noexcept(false)
	{
		std::cout << "bye class B" << std::endl;
		throw std::string("error B"); // ����try catch ֻ�ܲ���һ���쳣��ͬʱ���������쳣��core dumped��
	}

private:
	std::string m_value;
};

class GoodB : public B
{
public:
	// �Զ����������� �� ������Ĭ�������������� ������Ϊ noexcept��
	//~EvilB() { throw std::string("error"); } // ��Ч�� ~EvilB() noexcept { throw std::string("error"); }
	~GoodB() noexcept(false) 
	{ 
		throw std::string("error"); 
		delete m_value; // ����쳣�� delete ǰ�� m_value����Զ��ʧ��
	} // ͨ�� noexcept(false) ʹ���������׳��쳣��
	// �˴��쳣���������񣬶���ִ�������������ٲ���
private:
	int* m_value;
};

void test()
{
	try
	{
		GoodB b;
		GoodB c; // ����try catch ֻ�ܲ���һ���쳣 ==> �������������������׳��쳣��
	}
	catch (std::string const& e)  
	{
		std::cout << "catch you evil" << e << std::endl;
	}
}

int main()
{
	test(); // abort() ���������

	return 0;
}

/*
================================================================================
==>����������Ӧ�׳��쳣
--------------------------------------------------------------------------------
ԭ��
	1.���������е��쳣���Ǽ�ʱ������ try catch ����ͬʱ���������쳣��
	2.����쳣�׳���deleteǰ����ʹ��Դ��ʧ��
================================================================================
*/