#include"Kolo.h"

Kolo::Kolo(double r)
    : radius(r)
{
}

void Kolo::wypisz(std::ostream& os) const
{
    os<<"Kolo o promieniu: "<<radius<<"\n";
}

double Kolo::polePow() const
{
    return PI*radius*radius;
}

