#pragma once

#include<string>

//Klasa reprezentujaca obiekt ktorego zawartosc mozna wypisac
//na ekran
class MyPrintable
{
public:
    virtual ~MyPrintable() = default;

    //Zwraca zawartosc pola tekstu w wywolujacej klasie pochodnej
    virtual std::string rawString() const = 0;
};