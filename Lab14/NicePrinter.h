#pragma once

#include<iostream>
#include<iomanip>
#include<string>

// Klasa pomocna przy wypisywaniu zmiennych z klasy SetHoldRet.
// Posiada dodatkowe funkcjonalnosci edycji wypisywanych informacji.
class NicePrinter
{
public:
    // Konstruktor ustawiajacy wartosc szerokosci prefiksu z numerem linii.
    NicePrinter(int w)
    {
        NicePrinter::m_width = w;
        std::cout<<"NicePrinter: Set "<<w<<"-digits prefix\n";
    }
    
    // Funkcja wypisujaca separator o numerze przekazanym jako parametr.
    void separator(int n) const
    {
        std::cout<<"=====-===== "<<n<<" =====-=====\n";
    }
    
    // Funkcja wypisujaca linijke tekstu jako naglowek (z asteriskami po bokach)
    void header(const std::string& h) const
    {
        std::cout<<"* "<<h<<" *\n";
    }
    
    
    // Szablon operatora (), ktory wypisuje przekazana zmienna wraz z numerem
    // linii, ktory zwieksza sie z kazdym wywolaniem funkcji.
    template<typename T>
    void operator()(const T& printable) const
    {
        std::cout << std::setw(m_width) << m_number++ 
                << ": " << printable << std::endl;
    }

private:
    static size_t m_width;
    static size_t m_number;
};

size_t NicePrinter::m_width = 0;
size_t NicePrinter::m_number = 1;