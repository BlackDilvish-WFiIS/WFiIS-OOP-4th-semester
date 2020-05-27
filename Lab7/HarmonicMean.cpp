#include"HarmonicMean.h"
#include<iostream>

HarmonicMean::HarmonicMean()
    : Mean("Harmonic")
{
}

Mean& HarmonicMean::operator<<(double data)
{
    AddElement(1.0/data);
    return *this;
}

const Mean& HarmonicMean::operator<<(double data) const
{
    std::cout<<"ERROR: cannot add value "<<data
             <<" to const Harmonic Mean\n";
    return *this;
}

double HarmonicMean::result() const
{
    if(GetSum() == 0)
        return 0;
    else
        return (GetCount()/GetSum());
}