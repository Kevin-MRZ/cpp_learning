#pragma once

/*
================================================================================
==>enable_shared_from_this
--------------------------------------------------------------------------------
	1.�� T �̳� std::enable_shared_from_this<T> ����Ϊ���� T �ṩ��Ա������ shared_from_this��
	2.T ���Ͷ��� t ����Ϊ pt �� std::shared_ptr<T> ��������
	3.���� T::shared_from_this ��Ա�����������µ� std::shared_ptr<T> �������� pt ���� t ������Ȩ��
 Ӧ�ó���������A��share_ptr����������A�ĳ�Ա��������Ҫ�ѵ�ǰ�������Ϊ����������������ʱ����Ҫ����һ��ָ�������share_ptr��
 ʵ��ԭ��
================================================================================
*/

#include <iostream>
#include <memory>

class Bad
{
public:
	std::shared_ptr<Bad> getptr() 
	{
		return std::shared_ptr<Bad>(this);
	}
	Bad() { std::cout << "Bad::Bad() called" << std::endl; }
	~Bad() { std::cout << "Bad::~Bad() called" << std::endl; }
};

class Good : public std::enable_shared_from_this<Good> // ע�⣺�̳�
{
public:
	std::shared_ptr<Good> getptr() 
	{
		return shared_from_this();
	}
	Good() { std::cout << "Good::Good() called" << std::endl; }
	~Good() { std::cout << "Good::~Good() called" << std::endl; }
};

//void esft_Bad()
//{
//	// ����ÿ��shared_ptr����Ϊ�Լ��Ƕ�����е�������
//	std::shared_ptr<Bad> bp1(new Bad());
//	std::shared_ptr<Bad> bp2 = bp1->getptr();
//	// ��ӡbp1��bp2�����ü���
//	std::cout << "bp1.use_count() = " << bp1.use_count() << std::endl;
//	std::cout << "bp2.use_count() = " << bp2.use_count() << std::endl;
//}	// Bad ���󽫻ᱻɾ������

void esft_Good()
{
	std::shared_ptr<Good> gp1(new Good());
	std::shared_ptr<Good> gp2 = gp1->getptr();
	// ��ӡgp1��gp2�����ü���
	std::cout << "gp1.use_count() = " << gp1.use_count() << std::endl;
	std::cout << "gp2.use_count() = " << gp2.use_count() << std::endl;
}