#pragma once

#include<iostream>
#include<string>
#include"MyItem.h"

//Klasa reprezentująca plik tekstowy w systemie plików
//Dziedziczy po klasie obiektu systemowego: MyItem
class MyFile : public MyItem
{
public:
    //Konstruktor przyjmujący nazwę pliku
    MyFile(const std::string & name);
    
    //Funkcja zwracająca głęboką kopię pliku
    MyItem * clone() const override;

    //Funkcja wypisująca nazwę pliku
    void ls(unsigned int op) const override;
    
    //Funkcja wypisująca zawartość pliku
    void cat();
    
    //Operator dodający tekst do zawartości pliku
    MyFile& operator<<(const std::string& text);
        
    
private:
    std::string m_content;
};