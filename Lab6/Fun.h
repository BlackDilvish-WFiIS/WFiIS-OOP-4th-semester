#pragma once

//Klasa abstrakcyjna reprezentująca funkcję matematyczną
//i jej podstawowe właściwości
class Fun
{
public:
    virtual ~Fun() = default;

    //Funkcja zwracająca wartość funkcji w zadanym punkcie
    virtual double wartosc(double x) const = 0; 
    
    //Funkcja zwracająca kopię aktualnej funkcji jako niezależny
    //obszar w pamięci
    virtual Fun* clone() const = 0;
};

