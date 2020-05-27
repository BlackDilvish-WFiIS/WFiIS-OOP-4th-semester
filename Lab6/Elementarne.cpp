#include"Elementarne.h"
#include<cmath>

Liniowa::Liniowa(double aa, double bb)
    : m_a(aa), m_b(bb)
{
}

double Liniowa::wartosc(double x) const
{
    return m_a*x + m_b;
}

double Sinus::wartosc(double x) const
{
    return std::sin(x);
}

double Kwadratowa::wartosc(double x) const
{
    return m_a*x*x + m_b*x + m_c;
}

Kwadratowa::Kwadratowa(double aa, double bb, double cc)
    : m_a(aa), m_b(bb), m_c(cc)
{
}

Fun* Liniowa::clone() const
{
    return new Liniowa(m_a, m_b);
}

Fun* Sinus::clone() const
{
    return new Sinus();
}

Fun* Kwadratowa::clone() const
{
    return new Kwadratowa(m_a, m_b, m_c);
}