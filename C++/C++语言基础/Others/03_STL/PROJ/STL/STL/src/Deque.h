#pragma once

#include <iostream>
#include <deque>
#include <vector>

/*
================================================================================
==>deque��˫�˶��С�
--------------------------------------------------------------------------------
������ʣ���β��ɾ�죬�м���ɾ��������Ԫ�ظ������ƶ�����

���˶�����ɾ��
Ԫ�ط��ʼ���������vector��
������������smart_pointer,������Ѱ��pointer����ͬ�������ת����
��֧��������С���ƣ�����β���������ɾԪ�ض���ʹ������ʧЧ��
���·����ڴ�����vector�����踴��Ԫ�أ���
ʹ�ó�����
	1.������ɾ��������β��
	2.���������ָ����Ԫ�ء�
	3.����ʹ�õ�Ԫ�ر����ͷš�
================================================================================
*/

static void dequeTest()
{
	using Group = std::deque<float>;

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
	d.shrink_to_fit();					// ��������

	// ��ֵ
	b = g;
	b.assign(3, 1.0f);					// �������ݣ�3��1.0f
	b.assign(g.begin(), g.end());		// �������ݣ�������ֵg
	b.assign({ 1.0f, 2.0f, 3.0f });		// �������ݣ�1.0f, 2.0f, 3.0f

	// ����
	b.swap(a);							// ��������
	std::swap(a, b);					// ��������

	// Ԫ�ط���
	b[0];
	b.at(0);							// ����ָ������Ԫ��
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
	b.shrink_to_fit();							// �ڴ�����������Ԫ��ƥ�䣨�����飩

/*
	// ʹ��deque������Ϣ�Ľ����뷢�͡�

	using Buffer = std::vector<char>;
	using BufferGroup = std::deque<Buffer>;
	BufferGroup group;
	Buffer buffer;
	auto ok = readFromClient(socket, &buffer);
	if (ok)
	{
		group.emplace_back(std::move(buffer));
	}
	else
	{
		// handle error
	}

	while (!group.empty())
	{
		auto ok = sendToClient(socket, group.front());
		if (ok)
		{
			group.pop_front();
		}
		else
		{
			// handle error
			break;
		}
	}
*/
}