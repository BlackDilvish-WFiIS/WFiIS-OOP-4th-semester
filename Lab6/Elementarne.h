#pragma once
#include"Fun.h"

//Klasa reprezentująca funkcję liniową
//Dziedziczy po abstrakcyjnej klasie Fun
class Liniowa : public Fun
{
public:
    //Konstruktor inicjalizujący parametry funkcji liniowej
    Liniowa(double aa=0, double bb=0);

    //Funkcja zwracająca wskaźnik do funkcji liniowej
    //z domyslnymi parametrami
    static Liniowa* utworz()
    {
        return new Liniowa();
    }
    
    //Ustawienie wartosci parametru 'a' funkcji liniowej
    Liniowa* a(double aa) { m_a = aa; return this; }
    
    //Ustawienie wartosci parametru 'b' funkcji liniowej
    Liniowa* b(double bb) { m_b = bb; return this; }
    
    //Zwrocenie wartosci funkcji liniowej w zadanym punkcie
    double wartosc(double x) const override;
    
    //Funkcja zwracająca kopię aktualnej funkcji jako niezależny
    //obszar w pamięci
    Fun* clone() const override;
    
private:
    double m_a, m_b;
};


//Klasa reprezentująca funkcję sinus
//Dziedziczy po abstrakcyjnej klasie Fun
class Sinus : public Fun
{
public:
    //Zwrocenie wartosci funkcji sinus w zadanym punkcie
    double wartosc(double x) const override;
    
    //Funkcja zwracająca kopię aktualnej funkcji jako niezależny
    //obszar w pamięci
    Fun* clone() const override;
};


//Klasa reprezentująca funkcję kwadratową
//Dziedziczy po abstrakcyjnej klasie Fun
class Kwadratowa : public Fun
{
public:
    //Konstruktor inicjalizujący parametry funkcji kwadratowej
    Kwadratowa(double aa=0, double bb=0, double cc=0);

    //Funkcja zwracająca wskaźnik do funkcji kwadratowej
    //z domyslnymi parametrami
    static Kwadratowa* utworz()
    {
        return new Kwadratowa();
    }
    
    //Ustawienie wartosci parametru 'a' funkcji kwadratowej
    Kwadratowa* a(double aa) { m_a = aa; return this; }
    
    //Ustawienie wartosci parametru 'b' funkcji kwadratowej
    Kwadratowa* b(double bb) { m_b = bb; return this; }
    
    //Ustawienie wartosci parametru 'c' funkcji kwadratowej
    Kwadratowa* c(double cc) { m_c = cc; return this; }
    
    //Zwrocenie wartosci funkcji kwadratowej w zadanym punkcie
    double wartosc(double x) const override;
    
    //Funkcja zwracająca kopię aktualnej funkcji jako niezależny
    //obszar w pamięci
    Fun* clone() const override;
    
private:
    double m_a, m_b, m_c; 
  
};