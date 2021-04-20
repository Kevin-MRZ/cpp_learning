#pragma once

#include <iostream>
#include <vector>

/*
================================================================================
==>vector����̬���顣
--------------------------------------------------------------------------------
	�䳤���洢���ա��������Ԫ�ء����ҿ졢��ɾ����
ע������ʹ��vector�洢bool��std::vector<bool>Ϊ�ٵ���������ʵ�ֲ�ȡ��λ���ֶΣ����ձ�ʾ����
		1��������λ�洢1��bool��1���ֽڴ洢8��bool�����޷�ͨ��ȡ��ַ��ȡָ��bool�����ָ�롣
		��λ��֧��ָ������ã�
================================================================================
*/

static void vectorTest()
{
	using Group = std::vector<float>;
	//typedef std::vector<float> Group;

	Group a;
	Group b = a;
	Group c(a);
	Group d(10);
	Group e(10, 1.0f);
	Group f(e.begin(), e.end());
	Group g({ 1.0f, 2.0f, 3.0f });
	Group h = { 1.0f, 2.0f, 3.0f };		// �б��ʼ��

	d.empty();							// ��̬�����Ƿ�Ϊ��
	d.size();							// ��̬���鵱ǰ��С
	d.max_size();						// ��̬����ɴ��������
	d.capacity();						// ��̬���鵱ǰ����
	d.reserve(100);						// ��չ��������100����ǰ�᣺��ǰ����С��100��
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

	// erase��ɾ���󷵻�ɾ��λ�ú����һ��Ԫ�أ�����������ʧЧ�����·����ڴ棩
	h.erase(h.begin());					// ɾ��ָ�������������䣩Ԫ�أ�����ɾ��λ�ú����һԪ��
	h.erase(h.begin(), h.end());

	b.push_back(10.0f);					// ���βԪ�أ�����������ʧЧ�����·����ڴ棩
	b.pop_back();

	// insert��ָ��λ��֮�����һ������Ԫ�أ�����������ʧЧ�����·����ڴ棩
	auto iter = b.insert(b.end(), 100.0f);		// ����Ԫ�أ�b.end()�����100.0f
	iter = b.insert(b.end(), 10, -10.0f);		// ����Ԫ�أ�b.end()�����10��-10.0f
	b.insert(b.end(), h.begin(), h.end());		// ����Ԫ�أ�b.end()�����h������Ԫ��
	// emplace��ָ��λ��֮ǰ����һ������Ԫ�ء�
	b.emplace(b.end(), 10.0f);					// ����Ԫ�أ�b.end()ǰ����10.0f
	b.emplace_back(10.0f);						// ���βԪ�أ���push_back������push_back���ù���Ϳ������죻emplace_backֱ����vectorĩβ���죬�޿�����Ч�ʸ��ߡ�
	b.resize(10);								// �ı�Ԫ�ظ������������٣�������չ��
	b.resize(100, 1.0f);
	b.clear();									// ���Ԫ�أ��ڴ��С����
	b.shrink_to_fit();							// �ڴ�����������Ԫ��ƥ�䣨�����飩

	// C�ӿڻ���
	std::vector<char> carr(100, 0);
	strcpy(&carr[0], "hakuno");
	//printf("%s\n", &carr[0]); 	//ʹ��carr.data()���档
	//printf("%s", carr.begin()); // ����
	carr.data();
	std::cout << carr.data() << std::endl;
}