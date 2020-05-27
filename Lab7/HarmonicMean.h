#pragma once

#include"Mean.h"

//Klasa reprezentujaca srednia harmoniczna
//dziedziczy po klasie Mean
class HarmonicMean : public Mean
{
 public:
    //Konstruktor ktory ustawia nazwe sredniej w klasie bazowej
    //na 'harmonic'
    HarmonicMean();
    
    //Dodaje liczbę do sumy elementów sredniej harmonicznej
    //wg wzoru 'suma += 1/data'
    //oraz zwieksza licznik dodanych liczb
    Mean& operator<<(double data) override;
    
    //Wypisuje komunikat błędu o próbie dodania elementu do 
    //stałej średniej harmonicznej
    const Mean& operator<<(double data) const override;
    
    //Zwraca srednia harmoniczna z przekazanych elementow
    //za pomoca wzoru 'm_count/m_sum'
    double result() const override;
};