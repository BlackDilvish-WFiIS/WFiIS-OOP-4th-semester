#include"BitArray.h"

BitArray::BitArray(size_t size, bool type)
    : m_array(new unsigned char[size/8 + 1]), m_bitsCount(size)
{   
    for(size_t i=0; i<size/8 + 1; i++)
        m_array[i] = 255*type;
}

BitArray::BitArray(const BitArray& arr)
    : m_array(new unsigned char[arr.m_bitsCount/8 + 1]), m_bitsCount(arr.m_bitsCount)
{
    for(int i=m_bitsCount; i>=0; i--)
    {
        BitGetter(m_array[i/8], i % 8) = static_cast<bool>(arr[i]);
    }
}

BitArray::~BitArray()
{
    delete[] m_array;
}

BitGetter BitArray::operator[](size_t pos) const
{
    if(pos <= m_bitsCount)
        return BitGetter(m_array[pos/8], pos % 8);
    else
        std::cout<<"Poza zakresem!\n";
    
    return BitGetter(m_array[m_bitsCount/8], m_bitsCount % 8);
}

BitArray BitArray::operator=(const BitArray& arr)
{
    if(this == &arr)
        return *this;

    delete[] m_array;
    m_bitsCount = arr.m_bitsCount;
    m_array = new unsigned char[m_bitsCount/8 + 1];

    std::memcpy(m_array, arr.m_array, m_bitsCount/8 + 1);

    return *this;
}

void BitArray::print() const
{
    for(int i = m_bitsCount-1; i>=0; i--)
    {
        std::cout<<BitGetter(m_array[i/8], i%8);

        if(i%8 == 0)
            std::cout<<" <-"<<i<<" ";
    }
}

