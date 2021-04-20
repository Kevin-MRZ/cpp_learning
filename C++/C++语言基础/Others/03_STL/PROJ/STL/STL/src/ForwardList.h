#pragma once

#include <forward_list>

/*
================================================================================
==>forward_list����������
--------------------------------------------------------------------------------
��֧��������ʣ�������Ԫ���ٶȿ죬��ɾ�죬��ɾ����ʹ������ʧЧ��

forward_list׷�����ܣ�����size()��Ա�������Ӷ���洢�ռ䣬Ӱ�����ɾ��Ч�ʣ���
================================================================================
*/

static void forwardListTest()
{
	using Group = std::forward_list<float>;

	Group a;
	Group b = a;
	Group c(a);
	Group d(10);
	Group e(10, 1.0f);
	Group f(e.begin(), e.end());
	Group g({ 1.0f, 2.0f, 3.0f });
	Group h = { 1.0f, 2.0f, 3.0f };		// �б��ʼ��

	d.empty();							// �Ƿ�Ϊ��
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
	}

	// ������
	a.begin();							// ������
	a.end();
	a.cbegin();							// �����������������޸�ָ���Ԫ��ֵ
	a.cend();
	a.before_begin();	// ��һ��Ԫ�ص�ǰһ��λ�ã�δ���壬ռλ�������������㷨����
	a.cbefore_begin();	

	auto iterBegin = a.begin();

	b.erase_after(b.before_begin()); // return void
	b.erase_after(b.before_begin(), b.end()); // return void

	b.push_front(1.2f);
	b.emplace_front(1.3f);
	
	auto iter = b.insert_after(b.before_begin(), 100.0f);		// ����Ԫ�أ�b.before_begin()�����100.0f
	iter = b.insert_after(b.before_begin(), 10, -10.0f);		// ����Ԫ�أ�b.before_begin()�����10��-10.0f
	b.insert_after(b.before_begin(), h.begin(), h.end());		// ����Ԫ�أ�b.before_begin()�����h������Ԫ��

	b.resize(10);								// �ı�Ԫ�ظ������������٣�������չ��
	b.resize(100, 1.0f);
	b.clear();									// ���Ԫ��

	// �㷨
	b.remove(1.0f);
	b.remove_if([](auto v) { return v > 100.0f; });
	b.reverse(); // ��ת
	b.sort(); // ����
	g.sort();
	b.merge(g); // �ϲ�����b, g������
	c.unique(); // ȥ�������ظ�Ԫ�أ��������ʹ�ã�
	c.splice_after(c.before_begin(), b); // ƴ��
}