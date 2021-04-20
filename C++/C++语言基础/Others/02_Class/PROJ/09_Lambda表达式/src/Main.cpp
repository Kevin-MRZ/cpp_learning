#include <iostream>
#include <vector>
#include <algorithm>

/*
================================================================================
==> Lambda���ʽ
--------------------------------------------------------------------------------
 �﷨��ʽ��[ capture ] ( params ) opt -> ret { body; };
	1.capture��	�����б�������lambda���ʽ�ɷ����������еı�����
		- []��		������
		- [=]��		��ֵ����һ����������const������ԭֵ���Ĳ���Ӱ�츱�������޷��޸ĸ�����
		- [&]��		�����ò���
		- [this]��	����ǰ����
	2.params��	����������ʵ�����С�
	3.opt��		ѡ���mutable��
	4.ret��		����ֵ���ͣ�����ʽָ����Ҳ���Զ��ƶϣ���һ��returnʱ����
	5.body��		ʵ���塣

 ʾ����[](int x) {return x % 7 == 0; }
	1.�޺�����������ָ����auto f = [](int x ){ return x % 3 ==0; }; ����ʹ�ÿ���f()���档
	2.δ��������ֵ���ͣ����ݷ���ֵ�Զ��ƶϣ�
	3.Ĭ������£�Lambda����Ϊconst��������ʹ��mutableȡ��const���ԡ�
================================================================================
*/

bool func7(int x)
{
	return x % 7 == 0;
}

void lambda()
{
	std::vector<int> vec(10);
	std::generate(vec.begin(), vec.end(), std::rand); // std::generate() ���������

	//std::vector<int>::reverse_iterator iter;
	//for ( iter = vec.rbegin(); iter != vec.rend(); ++iter)
	std::vector<int>::iterator iter;
	for (iter = vec.begin(); iter != vec.end(); ++iter)
	{
		std::cout << *iter << " ";
	}
	std::cout << std::endl;
	
	// std::count() ��������ͳ��ĳ��ֵ���ֵĴ�����
	//int count = std::count_if(vec.begin(), vec.end(), func7);  // std::count_if() ��������ͳ����ν��ƥ��Ĵ˴���
	int count = std::count_if(vec.begin(), vec.end(), [](int x) { return x % 7 == 0; });  // ʹ�� Lambda���ʽ ���� func()������

	int a = 5;
	auto f = [=] () mutable { return a *= 5; };//��ֵ�����޷��޸ģ���Ҫ��ȡ��Lambda�������ԡ�
	std::cout << f() << std::endl;
} 

int main()
{
	lambda();

	return 0;
}