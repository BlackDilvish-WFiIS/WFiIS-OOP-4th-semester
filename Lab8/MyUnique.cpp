#include"MyUnique.h"

MyUnique::MyUnique(MyItem* item)
    : m_item(item)
{
    
}

MyUnique::MyUnique(MyUnique&& ptr)
    : m_item(ptr.m_item)
{
    ptr.m_item = nullptr;
}

MyUnique::~MyUnique()
{
    delete m_item;
}

MyUnique& MyUnique::operator=(MyUnique&& ptr)
{
    if(m_item == ptr.m_item)
        return *this;
        
    m_item = ptr.m_item;
    ptr.m_item = nullptr;
    return *this;
}

MyItem* MyUnique::operator->() const
{
    return m_item;
}

MyItem* MyUnique::get() const
{
    return m_item;
}