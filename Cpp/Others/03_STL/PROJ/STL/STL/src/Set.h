#pragma once

#include <iostream>
#include <set>
#include <string>
#include <algorithm>

/*
================================================================================
==>set�����������ṹ����
--------------------------------------------------------------------------------
����Ԫ���Զ����򣨴�С���󣩣���Ψһ��
��ɾ�鸴�Ӷȣ�O(logn)��
Ԫ�ر���֧���ϸ����˳��
��1�� x < y == true , y < x == false 
��2�� x < y == true , y < z == true , x < z == true 
��3�� x < x == false 
��4�� a == b , b == c , c == a
���ܸı�Ԫ�ص�ֵ��

�����ࣺ

================================================================================
*/

class Player;
struct CompareAge;
struct CompareName;
void compareTest();

static void setTest()
{
	using Group = std::set<float>;

	Group a;
	Group b = a;
	Group c(a);
	Group d(c.begin(), c.end());
	Group e({ 1.0f, 2.0f, 3.0f });
	Group f = { 1.0f, 2.0f, 3.0f };		// �б��ʼ��

	d.empty();
	d.size();
	d.max_size();

	auto keycomp = c.key_comp();
	auto valuecomp = c.value_comp();

	b = e;

	b.swap(a);
	std::swap(a, b);

	// ������
	a.begin();							// ������
	a.end();
	a.cbegin();							// �����������������޸�ָ���Ԫ��ֵ
	a.cend();
	a.rbegin();							// ���������
	a.rend();
	a.crbegin();						// �������������
	a.crend();

	auto iterBegin = a.begin();

	// �㷨
	auto num = a.count(1.0f); // ͳ�Ƽ�����ĳ��Ԫ�صĸ�����
	auto findIter = a.find(1.0f);	// ����Ԫ����ĳ��Ԫ�ص�λ�ã����ص�������

	if (findIter == a.end())
	{
		// δ�ҵ�
	}
	else
	{
		*findIter;
	}

	auto lower = a.lower_bound(1.0f); // ���ص�һ����С�ڸ�Ԫ�صĵ��������������򷵻�end()
	if (lower != a.end())
	{
		if (*lower == 1.0f)
		{
			// has 1.0f
		}
	}
	auto high = a.upper_bound(1.0f); // ���ص�һ�����ڸ�Ԫ�صĵ��������������򷵻�end()
	auto range = a.equal_range(1.0f); // ���ֲ��ң�return pair

	auto eraseIter = b.erase(b.begin());
	eraseIter = b.erase(b.begin(), b.end());

	auto state = b.insert(100.0f); // return pair
	b.insert(e.begin(), e.end());	// return void
	b.emplace(10.0f); // ֱ�ӹ��죬�������ι��죨��ʼ����+�������죩

	b.emplace_hint(b.end(), 50.0f); // �����ֵ��

	for (auto v : b)
	{
		std::cout << v << " ";
	}
	std::cout << std::endl;

	compareTest();
}

/*
================================================================================
����setԪ���������
================================================================================
*/

class Player
{
public:
	Player(int age, std::string name) : m_age(age), m_name(name) { std::move(age); }
	~Player() {}
	const int& getAge() const { return m_age; }
	const std::string& getName() const { return m_name; }
	void print() const { std::cout << m_age << " : " << m_name << std::endl; }
	void changeAge(int newAge) { m_age = newAge; }
	bool operator == (Player const& rhs) const
	{
		return m_age == rhs.m_age && m_name == rhs.m_name;
	}

private:
	int m_age;
	std::string m_name;
};

struct CompareAge
{
	template<typename T>
	bool operator() (const T& t1, const T& t2) const
	{
		return t1.getAge() < t2.getAge();
	}
};

struct CompareName
{
	template<typename T>
	bool operator() (const T& t1, const T& t2) const
	{
		return t1.getName() < t2.getName();
	}
};

void compareTest()
{
	Player a(35, "Yasuo");
	Player b(7, "Teemo");
	Player c(19, "Lux");

	std::cout << "Order by Age:\n";
	using Group1 = std::set<Player, CompareAge>;
	Group1 g1;
	g1.insert(a);
	g1.insert(b);
	g1.insert(c);

	for(auto& v : g1)
	{
		v.print();
	}

	auto ageIter = g1.begin();
	//(*ageIter).changeAge(30);

	std::cout << "Order by Name:\n";
	using Group2 = std::set<Player, CompareName>;
	Group2 g2;
	g2.insert(a);
	g2.insert(b);
	g2.insert(c);

	for (auto& v : g2)
	{
		v.print();
	}

	Player aa(19, "Lux");
	// set�����ṩfind���ҹ��򣺹���ʱ���������CompareName��
	auto iter = g2.find(aa);
	if (iter == g2.end())
	{
		std::cout << "δ�ҵ�" << std::endl;
	}
	else
	{
		std::cout << "���ҵ�" << std::endl;
	}

	// �㷨��Ĳ��ҹ��򣺸�������==�������
	iter = std::find(g2.begin(), g2.end(), aa);

}