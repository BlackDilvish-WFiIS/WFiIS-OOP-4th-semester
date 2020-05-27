#pragma once

#include"MyItem.h"

class MyUnique
{
public:
    MyUnique(MyItem* item);
    MyUnique(MyUnique&& ptr);
    MyUnique(const MyUnique& ptr) = delete;
    ~MyUnique();
    
    MyItem* operator->() const;
    MyItem* get() const;
    
    MyUnique& operator=(MyUnique&& ptr);
    
private:
    MyItem* m_item;
};