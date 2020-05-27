#include"InfoClass.h"

InfoClass::InfoClass(const std::string name) 
    : m_name(name)
{
    std::cout<<"++ Tworze obiekt InfoClass: "+info()+"\n";
}

InfoClass::~InfoClass()
{
    std::cout<<"++ Usuwam obiekt InfoClass: "+info()+"\n";
}

std::string InfoClass::info() const
{
    return "info = "+m_name;
}

void InfoClass::info(std::string newName)
{
    m_name = newName;
}

