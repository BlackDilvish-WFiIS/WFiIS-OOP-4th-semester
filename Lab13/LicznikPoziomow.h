#pragma once

#include<iostream>

//Klasa bedaca licznikiem poziomow, na ktorych zostaly rzucone wyjatki.
//Informuje nas o rozpoczeciu i zakonczeniu obliczen na danym poziomie
class LicznikPoziomow
{
public:
    //Konstruktor licznika poziomow, ktory zwieksza licznik, bedacy statycznym
    //polem klasy, a nastepnie wypisuje jego wartosc.
    LicznikPoziomow()
    {
        std::cout<<"Rozpoczynamy poziom numer "<<++LicznikPoziomow::counter<<".\n";
    }
    
    //Destruktor, ktory zmniejsza licznik i wypisuje informacje o tym, ktory
    //poziom zostal opuszczony
    ~LicznikPoziomow()
    {
        std::cout<<"Konczymy poziom numer "<<LicznikPoziomow::counter--<<".\n";
    }
 
private:
    static size_t counter;
};

size_t LicznikPoziomow::counter = 0;