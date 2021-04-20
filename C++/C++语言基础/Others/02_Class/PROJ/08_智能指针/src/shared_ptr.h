#pragma once

#include <iostream>
#include <memory>
#include <typeinfo>

#include "Object.h"

/*
================================================================================
==>shared_ptr
--------------------------------------------------------------------------------
�ص㣺
	1.��Դ�������ü�����
	2.�������졢��ֵ
	3.��������
ȱ�ݣ��޷�������������໥������
================================================================================
*/

typedef std::shared_ptr<Object> sharedPtrObj;

// ֵ���ݣ���ʱ�������������ü���+1
void print(sharedPtrObj shared_P)
{
	std::cout << "ֵ���ݣ����ü�����" << shared_P.use_count() << std::endl; // 0
}

// ���ô��ݣ����ü������䡣
void printRef(const sharedPtrObj& shared_P)
{
	std::cout << "���ô��ݣ����ü�����" << shared_P.use_count() << std::endl; // 0
}

void sharedPtrTest()
{
	sharedPtrObj shared_P1;
	// �� shared_ptr.use_count() ��ǰָ����Դ�������ܺ�
	std::cout << "���ü�����" << shared_P1.use_count() << std::endl; // 0

	Object* objPtr = new Object();
	sharedPtrObj shared_P2(objPtr);		// �󶨶�̬�������ü���+1����ǰΪ1��
	sharedPtrObj shared_P3(shared_P2);	// �������죬���ü���+1����ǰΪ2��
	sharedPtrObj shared_P4 = shared_P2;	// ������ֵ�����ü���+1����ǰΪ3��
	shared_P3.reset();					// ������ã����ü���-1����ǰΪ2���ȼ���obj2 = nullptr;

	sharedPtrObj shared_P5;				// ��ָ�루�޲Σ�
	shared_P4.swap(shared_P5);			// ָ�뽻�������ü������䡣
	std::swap(shared_P4, shared_P5);	// �������壬���ü������䡣
	shared_P4 = nullptr;				// ������ã����ü���-1����ǰΪ1��

	// �� ����ָ��shared_P2������Դ��ԭʼ��Object*ָ�롣
	auto pObject = shared_P2.get();			// ����ԭʼ��Object*ָ�롣
	std::cout << "Type of shared_ptr.get() is :" << typeid(pObject).name() << std::endl;
	if (pObject) // pObject�ǿ�ָ��
	{
		std::cout << pObject->getValue() << std::endl;
	}

	if (shared_P2)
	{
		std::cout << "m_Value id is " << shared_P2->getValue() << std::endl;	// ָ����ʣ�1
		std::cout << "m_Value id is " << (*shared_P2).getValue() << std::endl;	// ������ʣ�1
	}

	// �� ���shared_P1�Ƿ�����������Դ��Ψһ�����ߡ�
	std::cout << "���ü�����" << shared_P2.use_count() << std::endl;	// ���ü���Ϊ1��
	std::cout << "Ψһ���У�" << shared_P2.unique() << std::endl;		// shared_P2�ǵ�ǰ��Դ��Ψһ�����ߣ�1

	// �� ����ֵ���ݣ���ֹ���ü����仯��
	print(shared_P2); // ֵ���ݣ���ʱ�������������ü���+1�����ã�
	printRef(shared_P2);
}