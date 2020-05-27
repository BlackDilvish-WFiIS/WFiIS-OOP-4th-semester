#include"InfoSmartPtr.h"

InfoSmartPtr::InfoSmartPtr(InfoClass* ptr) 
    : m_ptr(ptr), m_counter(new int {1})
{
}

InfoSmartPtr::InfoSmartPtr(const InfoSmartPtr& sptr)
{
    m_counter = sptr.m_counter;
    *m_counter += 1;
    m_ptr = sptr.m_ptr;

}

InfoSmartPtr::~InfoSmartPtr()
{
    DecreaseCounter();
}

InfoSmartPtr& InfoSmartPtr::operator=(const InfoSmartPtr& sptr)
{
    DecreaseCounter();

    m_counter = sptr.m_counter;
    *m_counter += 1;

    m_ptr = sptr.m_ptr;

    return *this;
}

void InfoSmartPtr::DecreaseCounter()
{
    if(*m_counter == 1)
        delete m_ptr;
    else
        *m_counter -= 1;
}

