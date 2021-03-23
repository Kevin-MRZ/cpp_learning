#pragma once

#include <iostream>
#include <memory>
#include <typeinfo>

#include "Object.h"

/*
================================================================================
==>unique_ptr
--------------------------------------------------------------------------------
�ص㣺
	1.��Դ��ռ�������ڼ�飩
	2.�����������������켰��ֵ��
	3.��֧������
	4.������������
 ʹ�ã�
	1.unique_ptr.reset();  �󶨶�̬����
	2.unique_ptr.release() �ͷ�����Ȩ
	3.std::move() ת������Ȩ���ƶ����壩
================================================================================
*/

void uniquePtrTest()
{
	typedef std::unique_ptr<Object> uniquePtrObj;
	typedef std::unique_ptr<Object[]> uniquePtrObjArray;

	uniquePtrObj unique_P1, unique_P2, unique_P3, unique_P4, unique_P5;	//����������ָ��

	Object* p = new Object();
	uniquePtrObj unique_P0(p);

	// 1.�󶨶�̬����
	unique_P1.reset(new Object());		//�󶨶�̬����

	// 2.�ͷ�����Ȩ
	Object* ptr = unique_P1.release();	//���ض���ָ��
	ptr->~Object();					//�ֶ��ͷ�

	// 3.ת������Ȩ
	unique_P4 = std::move(unique_P2);		//�ƶ�����
	unique_P5.reset(unique_P3.release());

	// 4.֧������
	Object* pn = new Object[2];
	uniquePtrObjArray unique_P6(pn);
}