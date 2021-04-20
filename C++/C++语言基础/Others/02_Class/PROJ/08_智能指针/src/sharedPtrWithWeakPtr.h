#pragma once

#include <iostream>
#include <memory>
#include <typeinfo>

/*
================================================================================
==>weak_ptr����shared_ptr��������໥�������⡣
--------------------------------------------------------------------------------
================================================================================
*/

class B;

class A
{
public:
	//std::shared_ptr<B> b;
	std::weak_ptr<B> b;
	A() { std::cout << "class A ����" << std::endl; }
	~A() { std::cout << "class A ����" << std::endl; }
};

class B
{
public:
	//std::shared_ptr<A> a;
	std::weak_ptr<A> a;
	B() { std::cout << "class B ����" << std::endl; }
	~B() { std::cout << "class B ����" << std::endl; }
};

void sharedPtrWithWeakPtr()
{
	std::shared_ptr<A> sp1(new A);
	std::shared_ptr<B> sp2(new B);

	sp1->b = sp2;
	sp2->a = sp1;

	std::cout << "sp1���ü�����" << sp1.use_count() << std::endl; //���ü���-->1
	std::cout << "sp2���ü�����" << sp2.use_count() << std::endl; //���ü���-->1
}