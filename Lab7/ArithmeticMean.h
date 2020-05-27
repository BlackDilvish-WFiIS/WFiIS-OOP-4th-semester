#pragma once

#include"Mean.h"

//Klasa reprezentujaca srednia arytmetyczna
//Dziedziczy po klasie Mean
class ArithmeticMean : public Mean
{
public:
    //Konstruktor ktory ustawia nazwe sredniej w klasie bazowej
    //na 'arithmetic'
    ArithmeticMean();
    
    //Dodaje liczbę do sumy elementów sredniej arytmetycznej
    //wg wzoru 'suma += data'
    //oraz zwieksza licznik dodanych liczb
    Mean& operator<<(double data) override;
    
    //Wypisuje komunikat błędu o próbie dodania elementu do 
    //stałej średniej arytmetycznej
    const Mean& operator<<(double data) const override;
    
    //Zwraca srednia arytmetyczna z przekazanych elementow
    //za pomoca wzoru 'm_sum/m_count'
    double result() const override;
};