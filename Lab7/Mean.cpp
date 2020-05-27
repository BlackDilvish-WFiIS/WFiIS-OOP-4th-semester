#include<iostream>
#include"Mean.h"

Mean::Mean(const std::string& name)
    : m_name(name)
{
}

void Mean::reset()
{
    m_sum = 0;
    m_count = 0;
}


std::ostream& operator<<(std::ostream& os,const Mean& mean)
{
    os<<mean.m_name;
    return os;
}