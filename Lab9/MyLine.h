#pragma once

#include<string>
#include"Attributes.h"
#include"MyPrintable.h"

//Klasa reprezentujaca jedna linijke ktora mozna wypisac na ekran w postaci
//jednego znaku powielonego kilkukrotnie i zmienic jej kolor. 
//Dziedziczy w tym celu po klasach AttColor i MyPrintable
class MyLine : public AttColor, public MyPrintable
{
public:
    //Konstruktor ustawiajacy pola koloru, znaku i dlugosci linii
    MyLine(char c, size_t s, AttColor::Attribute col)
        :  AttColor(col), m_char(c), m_len(s)
    {}
    
    //Zwraca powielony znak w postaci jednej linii
    std::string rawString() const override
    {
        return std::string(m_len, m_char);
    }
    
    //Ustawia dlugosc linii
    void setLength(size_t len) { m_len = len; }
    
    //Ustawia znak powielany w linijce
    void setChar(char c) { m_char = c; }
    
private:
    char m_char;
    size_t m_len;
};