#pragma once
#include"Fun.h"

//Klasa reprezentująca funkcję zlozona
//z innych funkcji elementarnych.
//Dziedziczy po abstrakcyjnej klasie Fun.
class FZlozona : public Fun
{
public:
    //Konstruktor inicjalizujacy parametry funkcji zlozonej
    //kopiami zadanych wskaznikow do funkcji elementarnych
    FZlozona(Fun* fun1, Fun* fun2);
    
    //Destruktor czyszczacy pamiec po przyjetych funkcjach 
    //elementarnych
    ~FZlozona();
    
    //Zwrocenie wartosci funkcji zlozonej w zadanym punkcie
    double wartosc(double x) const override; 
    
    //Funkcja zwracająca kopię aktualnej funkcji jako niezależny
    //obszar w pamięci
    Fun* clone() const override;
    
private:
    Fun* m_f1;
    Fun* m_f2;
};