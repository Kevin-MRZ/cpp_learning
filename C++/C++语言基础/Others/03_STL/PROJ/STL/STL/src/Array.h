#pragma once

#include <iostream>
#include <array>

/*
================================================================================
==>array�����顣
--------------------------------------------------------------------------------
������ջ�ϡ��������·��䣬֧��������ʡ�
	�������洢���ա��������Ԫ�ء����ҿ졢��ɾ����
================================================================================
*/

template<typename C>
void checkSize(C& c)
{
	if (c.size() > 3)
	{
		c[3] = 10;
	}
	c.at(3) = 10;
}

static void arrayTest()
{
	int abc[100];
	std::array<int, 100> a;
	std::array<int, 100> b = {};
	std::array<int, 100> c = { 1,2,3,4,5,6 };
	std::array<int, 100> d = { 1, 0 };

	//�ӿ�
	a.empty();		// �����Ƿ�Ϊ��
	a.size();		// ���鵱ǰ��С
	a.max_size();	// �����������
					// �����������== < != > <= >=
	auto aa = a;

	aa.swap(a);		// ��������
	swap(aa, a);	// ��������

	//����Ԫ��
	a[1];
	a.at(1);		// ��ȡ��������λ�ô�Ԫ��
	a.front();		// ��ȡ������Ԫ��
	a.back();		// ��ȡ����βԪ��
	checkSize(a);

	//������
	a.begin();		// ������
	a.end();
	a.cbegin();		// �����������������޸�ָ���Ԫ��ֵ
	a.cend();
	a.rbegin();		// ���������
	a.rend();
	a.crbegin();	// �������������
	a.crend();

	// C�ӿڻ���
	std::array<char, 100> carr;
	strcpy(&carr[0], "hakuno");
	//printf("%s", &carr[0]);
	//printf("%s", carr.begin()); // ����
	std::cout << carr.data() << std::endl;

	auto info = std::get<1>(carr);
	carr.fill(0);	// ���Ԫ��
}