#include"Kwadrat.h"

Kwadrat::Kwadrat(double a)
    : base(a)
{
}

void Kwadrat::wypisz(std::ostream& os) const
{
    os<<"Kwadrat o boku: "<<base<<"\n";
}

double Kwadrat::polePow() const
{
    return base*base;
}

