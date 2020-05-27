#include"BitGetter.h"

BitGetter::BitGetter(unsigned char& byte, size_t pos)
    : m_byte(byte), m_pos(pos)
{
}

void BitGetter::operator=(bool val)
{
    if(val)
        m_byte |= (1<<m_pos);
    else
        m_byte ^= (1<<m_pos);
}

BitGetter::operator bool()
{
    return m_byte & (1<<m_pos);
}

