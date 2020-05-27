#include"Trojkat.h"
#include"cmath"

Trojkat::Trojkat(double a, double b, double c)
    : fBase(a), sBase(b), tBase(c)
{
}

void Trojkat::wypisz(std::ostream& os) const
{
    os<<"Trojkat o bokach: "<<fBase<<" "
            <<sBase<<" "<<tBase<<"\n";
}

double Trojkat::polePow() const
{
    double s = (fBase + sBase + tBase)/2; 

    return std::sqrt( s*(s-fBase)*(s-sBase)*(s-tBase) );
}

