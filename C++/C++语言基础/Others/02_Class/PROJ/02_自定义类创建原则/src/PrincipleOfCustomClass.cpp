#include <iostream>
#include <vector>
#include <assert.h>

class Principle {
public:
	// �޲ι���
	Principle() : m_value(new int(10)) {}
	
	// ��������
	Principle(const Principle& rhs) : m_value(new int(*(rhs.m_value))) {}
	
	// �������죨������ֵ��������ֵ��
	Principle(Principle&& rhs);

	// ��ֵ���������
	Principle& operator = (const Principle& rhs) 
	{
		*m_value = *(rhs.m_value);
		return *this;
	}
	// ��ֵ��������أ�����Ϊ��ֵ��
	Principle& operator = (Principle&& rhs)
	{
		// ���������ж���Ӧ�ԣ�e = std::move(e);
		if (&rhs == this)
		{
			return *this;
		}
		delete m_value;
		m_value = rhs.m_value;
		rhs.m_value = nullptr;
		return *this;
	}

	// ��������
	~Principle() { delete m_value; };

	void print() const
	{
		assert(m_value);	// �� m_value ���ڣ����ӡ��
		std::cout << *m_value << std::endl;
	}

private:
	int* m_value;
};

// �������죨��������ֵ��������ֵ����
Principle::Principle(Principle&& rhs)
{
	m_value = rhs.m_value;
	rhs.m_value = nullptr;
}

// ������ֵ��������ֵ
void print(const int& a)
{
	
	std::cout << a << std::endl;
}

int main()
{
	int abc = 10;
	// ������ֵ�������ֵ
	print(abc);		// 10
	print(10);		// 10

	std::vector<int> a;
	for (int i = 0; i < 10; i++)
	{
		a.push_back(i);
	}

	Principle b, e;
	auto& c = b;

	// ������ֵ��������ֵ����ȡ��Դ����
	// �˴�ʵ�ʵ�����	Principle(Principle&& rhs);
	Principle d = std::move(b);

	// ����ִ��move����ʹ�á�
	// b.print(); // �� print���� �� assert(m_value); ���г��� core dumped ���� b ����Դ�Ѳ����ڡ�
	// �������д Principle(Principle&& rhs);  b.print(); �Ϳ�ִ�гɹ���
	
	e = std::move(e);
}

/*
================================================================================
==>������ԭ��
--------------------------------------------------------------------------------
������������Դ��Ҫ�Զ������º������й���
	1.���캯����
	2.����������
	3.��ֵ��������ء�
	4.�������죨����Ϊ��ֵ��������ֵ��
	5.��ֵ��������أ�����Ϊ��ֵ��������ֵ��
================================================================================
*/