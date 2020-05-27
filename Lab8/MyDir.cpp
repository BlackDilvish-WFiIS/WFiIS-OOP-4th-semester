#include"MyDir.h"

MyDir::MyDir(const std::string & name)
    : MyItem(name)
{
    
}

MyDir::MyDir(const MyDir& dir)
    : MyItem(dir.GetName())
{
    for(auto& it : dir.m_items)
        *this /= it->clone();
}

MyDir::MyDir(MyDir&& dir)
    : MyItem(dir.GetName())
{
    m_items = std::move(dir.m_items);
}
    
MyItem* MyDir::clone() const
{
    return new MyDir(*this);
}

void MyDir::ls(unsigned int op) const
{
    op++;
    printName(op, '/');
    
    for(auto& it : m_items)
        it->ls(op);
}

void MyDir::operator/=(MyItem* item)
{
    m_items.push_back(MyUnique(item));
}

void MyDir::operator/=(MyUnique&& ptr)
{
    m_items.push_back(std::move(ptr));
}