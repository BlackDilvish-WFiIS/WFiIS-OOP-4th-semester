#pragma once

#include<iostream>
#include<exception>
#include<string>

//Klasa reprezentujaca wyjatek, rzucany w przypadku gdy nie powioda sie obliczenia
//w klasie Obliczenia. Zawiera informacje (wskaznik) o poprzednim, wyrzuconym wyjatku 
//oraz w jakim pliku i ktorej linijce zostal rzucony wyjatek.
//Dziedziczy po klasie std::runtime_error
class Calc_error : public std::runtime_error
{
public:
    //Konstruktor inicjalizujacy informacje o wyjatku w klasie bazowej
    //std::runtime_error informacja o tym w ktorej funkcji byl rzucony wyjatek,
    //w ktorym pliku oraz w ktorej linijce.
    Calc_error(std::runtime_error* err, const std::string& info,
                const std::string& file, size_t line);
    
    //Funkcja obslugujaca wyjatek typu Calc_error lub std::runtime_error 
    //zlapany tuz przed wywolaniem jej wywolaniem oraz wszystkie wyjatki 
    //zapisane w tych wyjatkach. Konczy swoje dzialanie gdy ostatni obslugiwany
    //wyjatek nie wskazuje na zaden wyjatek, ktory zostal rzucony przed nim.
    static void handler();
        
private:
    static void unpackExceptions(std::runtime_error* ex);

    std::runtime_error* m_prevError;
};