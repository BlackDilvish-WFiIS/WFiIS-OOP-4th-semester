#pragma once

#include<iostream>

//Klasa bedaca wrapperem na int, ktora reprezentuje predkosc
//maksymalna pojazdu
class PredkoscMaksymalna
{
public:
    //Konstruktor inicjalizujacy zmienna predkosci w ciele klasy
    PredkoscMaksymalna(int speed)
        : m_maxSpeed(speed) {}
    
    //Operator jawnego rzutowania obiektu klasy na typ int
    explicit operator int() const { return m_maxSpeed; }
private:
    int m_maxSpeed;    
};

//Przeladowany operator '<<' wypisujacy dane o predkosci
std::ostream& operator<<(std::ostream& os, const PredkoscMaksymalna& speed)
{
    os<<static_cast<int>(speed)<<" km/h";
    return os;
}