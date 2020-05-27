#include"Malenstwo.h"
#include"ZbieraczMalenstw.h"

Malenstwo::Malenstwo(int val)
    : _val(val)
{
    std::cout<<"Konstrukcja Malenstwa: wart = "<<val<<std::endl;
}

int& Malenstwo::wartosc()
{
    return _val;
}

void* Malenstwo::operator new(size_t size)
{
    ZbieraczMalenstw::allocatedMalenstwa += size;
    std::cout<<"Alokuje jeden obiekt: 1 ("<<size<<" bajtow)\n";

    if(ZbieraczMalenstw::malenstwaPtr.size() > ZbieraczMalenstw::allocatedMalenstwa)
    {
        return ZbieraczMalenstw::malenstwaPtr[ZbieraczMalenstw::allocatedMalenstwa];
    }
    else
    {
        std::cout<<"Pierwszy obiekt na stercie - prealokuje skladowisko na 100 elementow\n";
        for(int i=0;i<100;i++)
            ZbieraczMalenstw::malenstwaPtr.push_back((Malenstwo*) malloc(sizeof(Malenstwo)));

        return ZbieraczMalenstw::malenstwaPtr[ZbieraczMalenstw::allocatedMalenstwa - size];
    }
}

void* Malenstwo::operator new[](size_t size)
{
    ZbieraczMalenstw::allocatedMalenstwa += size/4;
    std::cout<<"Alokuje tablice [] o rozmiarze"<<size/4<<" ("<<size*sizeof(Malenstwo*)<<" bajtow)\n";

    return ZbieraczMalenstw::malenstwaPtr[ZbieraczMalenstw::allocatedMalenstwa - size];

}

void Malenstwo::operator delete(void* ptr)
{
    std::cout<<"Zwalniam jeden obiekt: 1"<<" ("<<sizeof(*static_cast<Malenstwo*>(ptr))<<" bajtow)\n";

    free(ptr);
}

void Malenstwo::operator delete[](void* ptr)
{
    std::cout<<"Zwalniam tablice [] o rozmiarze"<<sizeof(static_cast<Malenstwo*>(ptr))/4<<
               " ("<<sizeof(static_cast<Malenstwo*>(ptr))<<" bajtow)\n";
}

