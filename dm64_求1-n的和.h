#pragma once
/* 构造函数求解 */
class Temp
{
public:
	Temp() { ++num; sum += num; }
	
	static void reset() { num = 0; sum = 0; }
	static unsigned int getSum() { return sum; }

private:
	static unsigned int num;
	static unsigned int sum;
};

unsigned int Temp::num = 0;
unsigned int Temp::sum = 0;

int sum_Solution1(unsigned int n)
{
	Temp::reset();
	Temp* a = new Temp[n];
	delete[] a;
	a = nullptr;

	return Temp::getSum();
}

/* 虚函数求解 */
class A;
A* array[2];

class A
{
public:
	virtual unsigned int calSum(unsigned int n)
	{
		return 0;
	}
};

class B : public A
{
public:
	virtual unsigned int calSum(unsigned int n)
	{
		return array[!!n]->calSum(n - 1) + n;
	}
};

int sum_Solution2(unsigned int n)
{
	A a;
	B b;
	array[0] = &a;
	array[1] = &b;
	int sum = array[1]->calSum(n);
	return sum;
}

/* 函数指针求解 */
typedef unsigned int (*fun)(unsigned int);

unsigned int sum_Solution3_End(unsigned int n)
{
	return 0;
}

unsigned int sum_Solution3(unsigned int n)
{
	static fun f[2] = { sum_Solution3_End ,sum_Solution3 };
	return n + f[!!n](n - 1);
}

/* 模板类型实例化 */
template<unsigned int n>
struct sum_Solution4
{
	enum value { N = sum_Solution4<n - 1>::N + n };
};

template<>
struct sum_Solution4<1>
{
	enum value { N = 1 };
};