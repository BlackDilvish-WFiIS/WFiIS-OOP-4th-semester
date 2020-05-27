#include"ArithmeticMean.h"
#include<iostream>

ArithmeticMean::ArithmeticMean()
    : Mean("Arithmetic")
{
}

Mean& ArithmeticMean::operator<<(double data)
{
    AddElement(data);
    return *this;
}

const Mean& ArithmeticMean::operator<<(double data) const
{
    std::cout<<"ERROR: cannot add value "<<data
             <<" to const Arithmetic Mean\n";
    return *this;
}

double ArithmeticMean::result() const
{
    if(GetCount() == 0)
        return 0;
    else
        return GetSum()/GetCount();
}
 