#pragma once

#include <iostream>
#include <memory>
#include <typeinfo>

#include "Object.h"

/*
================================================================================
==>auto_ptr
--------------------------------------------------------------------------------
�ص㣺
	1.��Դ��ռ
	2.֧�ֿ�������ֵ���������壬������ԭָ��ʧЧ��
	3.��֧������
	4.�������������������ݣ���ʱ��������ת������Ȩ��
	5.���ܳ�ʼ��ָ��Ƕ�̬�ڴ棨�Ƕ�̬�ڴ��޷��ͷţ�
 ����ԭ�򣺱�����Ǳ�ڵ��ڴ����⵼�³��������
 ʹ�ã�
	1.auto_ptr.reset();  �󶨶�̬����
	2.auto_ptr.release() �ͷ�����Ȩ
	3.std::move() ת������Ȩ���ƶ����壩
================================================================================
*/

void autoPtrTest()
{
	typedef std::auto_ptr<Object> autoPtrObj;
	typedef std::auto_ptr<int> autoPtrInt;

	// �� auto_ptr��Դ��ռ����������ʱ����ͬһ��Դ�޷��ͷ����Ρ�
	int* ptr1 = new int(3);
	autoPtrInt auto_P1(ptr1);
	//autoPtrInt auto_P2(ptr1);
	std::cout << "*ptr1 " << *ptr1 << std::endl;
	std::cout << "*auto_P1 " << *auto_P1 << std::endl;
	//std::cout << *auto_P2 << std::endl;

	// �� auto_ptr�������壬��������ʱ����ap3���������Ϊnullptr��
	int* ptr2 = new int(5);
	autoPtrInt auto_P3(ptr2);
	autoPtrInt auto_P4(auto_P3);
	//std::cout << "*auto_P3 " << *auto_P3 << std::endl;
	std::cout << "*auto_P4 " << *auto_P4 << std::endl;

	// �� auto_ptr��֧�����飨Ĭ�ϲ����������󣩣���������ʱ���������е�n-1�������޷�������
	Object* pArray = new Object[2];
	//autoPtrObj ap5(pArray); // ��֧����������

	// auto_ptr.reset();  �󶨶�̬����
	autoPtrObj auto_P5, auto_P6;
	auto_P6.reset(new Object());
	// auto_ptr.release() �ͷ�����Ȩ
	auto_P6.release();
	// ͨ��std::moveת������Ȩ
	auto_P6 = std::move(auto_P5); // auto_P6.reset(auto_P5.release())
}