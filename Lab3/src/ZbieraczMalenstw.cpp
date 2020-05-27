#include"ZbieraczMalenstw.h"


ZbieraczMalenstw::~ZbieraczMalenstw()
{
    for(auto p : ZbieraczMalenstw::malenstwaPtr)
        if(p)
            free(p);
}

std::vector<Malenstwo*> ZbieraczMalenstw::malenstwaPtr;
size_t ZbieraczMalenstw::allocatedMalenstwa;

