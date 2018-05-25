#include <iostream>

using namespace std;

class IFibo
{
public:
	virtual int fibo(int n) = 0;
};

class FiboA:public IFibo
{
	int fibo(int n) { cout << "Soy Fibo tipo A" << endl; return 0; }
};

class FiboB :public IFibo
{
	int fibo(int n) { cout << "Soy Fibo tipo B" << endl; return 0; }
};

class FiboEngine
{
	IFibo *pf;
public:
	FiboEngine(IFibo*p) :pf(p) {}
	int fibo(int n);
};

int FiboEngine::fibo(int n) // Necesario para el gestor de virtualidad. Enlace dinamico. Polimorfismo
{
	return pf->fibo(n);
}

void main()
{
	FiboEngine f = new FiboA;
	f.fibo(10);
	FiboEngine f1 = new FiboB;
	f1.fibo(12);
};