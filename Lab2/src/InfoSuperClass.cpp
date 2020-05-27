#include"InfoSuperClass.h"

InfoSuperClass::InfoSuperClass(std::string name, int num)
    : InfoClass(name), m_num(num)
{
}

InfoSuperClass::~InfoSuperClass()
{
    std::cout<<"++ Usuwam obiekt InfoClass: "+InfoClass::info()+"\n";
}

std::string InfoSuperClass::info() const
{
    return InfoClass::info()+", num = "+std::to_string(m_num);
}

