#include"FZlozona.h"

FZlozona::FZlozona(Fun* fun1, Fun* fun2)
    : m_f1(fun1->clone()), m_f2(fun2->clone())
{
}

FZlozona::~FZlozona()
{
    delete m_f1;
    delete m_f2;
}

double FZlozona::wartosc(double x) const
{
    return m_f2->wartosc(m_f1->wartosc(x));
}


Fun* FZlozona::clone() const
{
    return new FZlozona(m_f1, m_f2);
}