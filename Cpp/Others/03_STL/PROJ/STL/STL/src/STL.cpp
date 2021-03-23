#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>

#include "Array.h"
#include "Vector.h"
#include "Deque.h"
#include "List.h"
#include "ForwardList.h"
#include "Set.h"
#include "Map.h"


/*
================================================================================
==>STL�����ɳ������������������㷨��
--------------------------------------------------------------------------------
������
	����ʽ������array��vector��deque��list��forward_list �����顢ָ�롢����
	����ʽ������set��map��multiset��multimap��hash_set��hash_map�����������������lgn��
	��˳��������unordered_set��unordered_map��unordered_multiset��unordered_multimap


stack��ջ��
queue�����У�
priority_queue (���ȼ�˳�� ����)
string���ַ�����
bitset������bool��sizeof(bool) == 1, ռ8λ��������Ƿ�ֻ��Ҫ1λ��

regex��������ʽ��
rand���������
thread��async��future�����߳����Բ�ʵ�֣�
time��ʱ����أ�

����֪ʶ
	1.������Ԫ��Ӧ�����������
		a.�ɿ�������ƣ�move�����޸�����
		b.�ɸ�ֵ��
		c.�����١�
	2.����ʽ����Ԫ�أ�Ӧ��Ĭ�ϵĹ��캯����
	3.����ĳЩ������std::find����Ԫ����Ҫ���� ==
	4.���ڹ���ʽ����������׼��Ĭ�� < > std::less
	5.��˳�����������ṩhash������
	6.stl�����ڴ��Ԫ��ֵ�������á�

STL���ԭ��Ч�����ȡ���ȫΪ�ˣ��������쳣����

================================================================================
*/

// ����ͨ�ýӿ�
template <typename T>
void containerAllInterface(T& a, T& b)
{
	T c;
	T d(a);						// copy
	T e = a;					// copy
	T f(std::move(a));			// a == NULL
	auto iterB = b.begin();
	auto iterE = b.end();
	T g(iterB, iterE);
	b.size();					// std::forward_list���ṩ��׷��ռ��ϵļ���Ч�ʣ�
	auto isEmpty = b.empty();	// return b.size() == 0;���㷨��һ��
	b.max_size();				// �������
	if (b == c) {}				// Ԫ�ر��붨�� ==
	if (b != d) {}				//  !(b == d)
	if (b < e) {}				// unordered_set��unordered_map ��֧��
								// == != < <= > >=

	e = b;
	e = std::move(b);
	e.swap(g);					// std::array ���Ե�
	swap(e, g);					// std::array ����

	e.cbegin();					// -> const_iterator
	auto ea = e.cbegin();
	auto eea = e.cbegin();
	*eea;
	*ea;

	e.cend();
	e.clear();					// std::forward_list��std::array��֧��
}

void stlTest()
{
	std::vector<int> a;
	std::vector<int> b;

	containerAllInterface(a, b);
}

int main()
{
	//stlTest();

	//arrayTest();
	//vectorTest();
	//dequeTest();
	//listTest();
	//forwardListTest();
	//setTest();
	mapTest();

	return 0;
}