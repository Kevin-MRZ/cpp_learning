#pragma once

#include <iostream>
#include <memory>
#include <typeinfo>

#include "Object.h"

/*
================================================================================
==>weak_ptr
--------------------------------------------------------------------------------
 weak_ptr ��ָ��  ����shared_ptr���ж϶����Ƿ���ڣ�������ʲ����ڵĶ���
	1.ʹ�ö���ʱ����Ҫ��ת��Ϊshared_ptr��
	2.�󶨵�shared_ptr��������ʹshared_ptr����+1��
	3.weak_ptr.lock()����������ָ�롣
	4.weak_ptr.expired()������ָ���Ƿ�Ϊnullptr��
================================================================================
*/

typedef std::shared_ptr<Object> sharedPtrObj;
typedef std::weak_ptr<Object> weakPtrObj;

void weakPtrTest()
{
	sharedPtrObj shared_P(new Object());
	weakPtrObj weak_P1;
	weakPtrObj weak_P2(shared_P);
	weakPtrObj weak_P3(shared_P);
	std::cout << "��ǰ new Object() ���ü�����" << shared_P.use_count() << std::endl; // 1
	{
		std::cout << "new Object() �Ƿ�Ψһ���ã�" << shared_P.unique() << std::endl; // 1

		// �� ����share_ptr���������ָ�롣
		auto shared_Ptr = weak_P2.lock(); // class std::shared_ptr<class Object>
		if (shared_Ptr == nullptr)
		{
			std::cout << "weak_P2�󶨵Ĺ���ָ�룺nullptr��" << std::endl;
		}
		else
		{
			std::cout << "��ǰ new Object() ���ü�����" << shared_Ptr.use_count() << std::endl; // 2��shared_P + shared_Ptr��
			shared_P.reset();
		}

		// �� �󶨵�shared_ptr�Ƿ�Ϊnullptr�������Ƿ��ѱ����٣���
		auto isNotExist = weak_P2.expired();
		if (isNotExist)
		{
			std::cout << "weak_P2�󶨵Ĺ���ָ��Ϊ0�������ѱ����٣�" << std::endl;
		}
		else
		{
			std::cout << "weak_P2�󶨵Ĺ���ָ���0��������Ȼ��" << std::endl;
		}
	}
}