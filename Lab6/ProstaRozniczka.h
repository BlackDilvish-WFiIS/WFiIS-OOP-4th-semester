#pragma once
#include"Fun.h"

//Klasa reprezentujaca prosta rozniczke operujaca
//na funkcjach elementarnych dziedziczacych po
//klasie Fun
class ProstaRozniczka
{
public:
    //Konstruktor inicjalizujacy dokladnosc
    //rozniczki zadana wartoscia
    ProstaRozniczka(double step);
    
    //Przypisuje funkcje z ktorej bedzie liczona rozniczka
    ProstaRozniczka* z(Fun* func);
    
    //Przeladowywuje operator() by przypisywal funkcje
    //z ktorej bedzie liczona rozniczka
    ProstaRozniczka operator()(Fun* func);
    
    //Operator () zwracajacy wartosc rozniczki w zadanym punkcie
    double operator()(double x) const;
    
    //Zwraca wartosc rozniczki w zadanym punkcie
    double w(double x) const;
    
private:
    double m_step;
    Fun* m_f;
};