#include"ListaString.h"

ListaString::ListaString()
{
    if(ListaString::m_doNoise)
        std::cout<<" (list-def-ctor) \n";
}

ListaString::ListaString(const ListaString& list)
    : m_strings(list.m_strings)
{
    if(ListaString::m_doNoise)
        std::cout<<" (list-copy-ctor)  \n";
}

ListaString::ListaString(ListaString&& list)
{
    if(ListaString::m_doNoise)
        std::cout<<" (list-move-ctor)  \n";

    m_strings = std::move(list.m_strings);
}

ListaString::~ListaString()
{ 
    if(ListaString::m_doNoise)
        std::cout<<" (list-dtor)  \n";
}

void ListaString::PrintStrings(std::ostream& os) const
{
    for(size_t i=0; i<m_strings.size(); i++)
        os << "   " << i+1 << ". " << m_strings[i] << "\n";
}

ListaString& ListaString::operator<<(const std::string& text)
{
    m_strings.push_back(text);
    return *this;
}

void ListaString::rob_halas(bool value)
{
    m_doNoise = value;
}

std::string ListaString::operator[](size_t i) const
{
    return m_strings[i];
}

std::ostream& operator<<(std::ostream& os, const ListaString& list)
{
	list.PrintStrings(os);
	return os;
}

bool ListaString::m_doNoise = false;
