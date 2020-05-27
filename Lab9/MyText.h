#pragma once

#include<string>
#include"Attributes.h"
#include"MyPrintable.h"

//Klasa reprezentujaca tekst ktory mozna wypisac na ekran.
//Moze on byc odpowiednio sformatowany i mozna nadac mu kolor.
//W celach zapewnienia tej funkcjonalnosci, klasa dziedziczy po AttColor,
//AttFormat i MyPrintable
class MyText : public AttColor, public AttFormat, public MyPrintable
{
public:
    //Konstruktor ustawia zawartosc tekstu, jego atrybuty - format i kolor
    MyText(const std::string& text, AttFormat::Attribute format, AttColor::Attribute col);
    
    //Zwraca tekst zawarty w klasie
    std::string rawString() const override { return m_text; }
    
    //Ustawia zawartosc tekstu
    void setText(const std::string& text) { m_text = text; }
    
private:
    std::string m_text;
};