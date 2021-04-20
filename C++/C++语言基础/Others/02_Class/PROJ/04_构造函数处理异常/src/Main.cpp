#pragma once
#include <iostream>
#include <string>

using namespace std;

class A {
public:
	A() { cout << "���� A ����!" << endl; }
	~A() { cout << "���� A ����!" << endl; }
};

class B {
public:
	B() {
		throw exception("���ԣ���B�Ĺ��캯�����׳�һ���쳣"); // �׳��쳣���������Ȩת�Ƶ�class Tester�Ĺ��캯������
		cout << "���� B ����!" << endl;
	};
	~B() { cout << "���� B ����!" << endl; };
};

class Tester {
public:
	Tester(const string& name, const string& address) : m_Name(name), m_Address(address)
	{
		try
		{
			a = new A();
			b = new B();
		}
		catch (const std::exception&)
		{

			delete a;
			delete b;
			throw;   // ���������쳣
		}
		cout << "���� Tester ����!" << endl;
	}
	~Tester()
	{
		delete a;
		delete b;
		cout << "���� Tester ����!" << endl;
	}
private:
	string m_Name;
	string m_Address;
	A* a = NULL;
	B* b = NULL;
};

int main()
{
	Tester* tes = NULL;
	try
	{
		tes = new Tester("Hakuno", "486"); 
	}
	catch (exception e)
	{
		cout << e.what() << endl;
	};
	delete tes; // ɾ��NULLָ���ǰ�ȫ��

	system("pause");
	return 0;
}

/*
================================================================================
==>����ʧ��Ӧ�׳��쳣
--------------------------------------------------------------------------------
	swap�в��׳��쳣��

	1. �ڹ��캯�����׳��쳣��C++��֪ͨ������ʧ�ܵ�Ψһ������
	2. ���캯�����׳��쳣��������������������ᱻִ�У������Ķ��󲻻ᱻɾ���������ڴ�й©��
	3. �����������ֹ���ʱ���Ѿ�������ϵ��Ӷ��󣨷Ƕ�̬����ģ���������ر�������
================================================================================
*/