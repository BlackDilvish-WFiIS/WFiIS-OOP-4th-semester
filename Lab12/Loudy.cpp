#include"Loudy.h"

LoudyOutOfRangeException::~LoudyOutOfRangeException()
{
    m_arr->clean();
    
    delete m_arr;
}