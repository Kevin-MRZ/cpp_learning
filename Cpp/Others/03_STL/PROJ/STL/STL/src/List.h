#pragma once
#include <list>
/*
================================================================================
==>List��˫������
--------------------------------------------------------------------------------
��֧��������ʣ�������β�ٶȿ죬��ɾ�죬��ɾ����ʹ������ʧЧ��

�쳣����Nice��
================================================================================
*/

static void listTest()
{
	using Group = std::list<float>;

	Group a;
	Group b = a;
	Group c(a);
	Group d(10);
	Group e(10, 1.0f);
	Group f(e.begin(), e.end());
	Group g({ 1.0f, 2.0f, 3.0f });
	Group h = { 1.0f, 2.0f, 3.0f };		// �б��ʼ��

	d.empty();							// �Ƿ�Ϊ��
	d.size();							// ��ǰ��С
	d.max_size();						// �ɴ��������
		
	// ��ֵ
	b = g;
	b.assign(3, 1.0f);					// �������ݣ�3��1.0f
	b.assign(g.begin(), g.end());		// �������ݣ�������ֵg
	b.assign({ 1.0f, 2.0f, 3.0f });		// �������ݣ�1.0f, 2.0f, 3.0f

	// ����
	b.swap(a);							// ��������
	std::swap(a, b);					// ��������

	// Ԫ�ط���
	if (!b.empty())
	{
		b.front();						// ������Ԫ��
		b.back();						// ����βԪ��
	}

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
	//for (int i = 0; i < 5; ++i) ++iterBegin;
	//std::advance(iterBegin, 4);
	//auto iter5 = std::next(iterBegin, 4);

	if (!a.empty())
	{
		a.pop_back();					// ɾ��βԪ��
	}

	auto iterAfter = b.erase(b.begin());
	iterAfter = b.erase(b.begin(), b.end());

	b.push_back(10.0f);
	b.pop_back();
	b.push_front(1.2f);

	// insert��ָ��λ��֮�����һ������Ԫ�أ�����������ʧЧ�����·����ڴ棩
	auto iter = b.insert(b.end(), 100.0f);		// ����Ԫ�أ�b.end()�����100.0f
	iter = b.insert(b.end(), 10, -10.0f);		// ����Ԫ�أ�b.end()�����10��-10.0f
	b.insert(b.end(), h.begin(), h.end());		// ����Ԫ�أ�b.end()�����h������Ԫ��

	b.emplace_front(1.3f);
	b.emplace(b.end(), 10.0f);					// ����Ԫ�أ�b.end()ǰ����10.0f
	b.emplace_back(10.0f);						// ���βԪ�أ���push_back������push_back���ù���Ϳ������죻emplace_backֱ����vectorĩβ���죬�޿�����Ч�ʸ��ߡ�

	b.resize(10);								// �ı�Ԫ�ظ������������٣�������չ��
	b.resize(100, 1.0f);
	b.clear();									// ���Ԫ�أ��ڴ��С����
	
	// �㷨
	b.remove(1.0f);
	b.remove_if([](auto v) { return v > 100.0f; });
	b.reverse(); // ��ת
	b.sort(); // ����
	g.sort();
	b.merge(g); // �ϲ�����b, g������
	c.unique(); // ȥ�������ظ�Ԫ�أ��������ʹ�ã�
	c.splice(c.begin(), b); // ƴ��
}