#include <iostream>
#include <memory>
#include <typeinfo>

#include "auto_ptr.h"
#include "unique_ptr.h"
#include "shared_ptr.h"
#include "weak_ptr.h"
#include "sharedPtrWithWeakPtr.h"
#include "enable_shared_from_this.h"

/*
================================================================================
==>����ָ��
--------------------------------------------------------------------------------
	 ����ָ��
	 auto_ptr
	 shared_ptr ������Դ�����ü�����
	 unique_ptr ��ռ��Դ
	 weak_ptr   ����shared_ptr

ǰ�᣺��ֹ�ֶ�������Դ��
	1.һ����ָ�벻Ӧʹ����������ָ��ͬʱ����
	2.ʹ��weak_ptr���shared_ptr�ɴ���ѭ�����á�
	3.����ڲ��ӿ��У����轫this��Ϊ�������룬����Ӧ������enable_shared_from_this��
	4.shared_ptr��weak_ptr����ָ����ȣ��ռ������������+һ��ָ�룬����24�ֽڣ���Ч�ʵ͡�
================================================================================
*/

int main()
{
	//autoPtrTest();
	//uniquePtrTest();
	//sharedPtrTest();
	//weakPtrTest();
	//sharedPtrWithWeakPtr();

	//esft_Bad();
	esft_Good();

	system("pause");
}