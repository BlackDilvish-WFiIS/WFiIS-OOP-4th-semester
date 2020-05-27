#include"ProstaRozniczka.h"

ProstaRozniczka::ProstaRozniczka(double step)
    : m_step(step)
{
}


ProstaRozniczka* ProstaRozniczka::z(Fun* func)
{
    m_f = func;
    return this;
}

ProstaRozniczka ProstaRozniczka::operator()(Fun* func)
{
    return *z(func);
}

double ProstaRozniczka::operator()(double x) const
{
     return w(x);
}

double ProstaRozniczka::w(double x) const
{
    return (m_f->wartosc(x + m_step) - m_f->wartosc(x - m_step))/(2*m_step);
}