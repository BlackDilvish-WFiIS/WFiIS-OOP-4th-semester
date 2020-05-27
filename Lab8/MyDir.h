#pragma once

#include<iostream>
#include<string>
#include<vector>
#include"MyItem.h"
#include"MyUnique.h"

//Klasa reprezentująca katalog w systemie plików
//Dziedziczy po klasie obiektu systemowego: MyItem
class MyDir : public MyItem
{
public:
    //Konstruktor przyjmujący nazwę katalogu
    MyDir(const std::string & name);
    
    //Konstruktor wykonujący głęboką kopię katalogu
    MyDir(const MyDir& dir);
    
    //Konstruktor zapewniający przeniesienie całego
    //katalogu
    MyDir(MyDir&& dir);
    
    //Deklaracja domyślnego destruktora
    ~MyDir();
    
    //Funkcja zwracająca głęboką kopię katalogu
    MyItem * clone() const override;

    //Funkcja wypisująca strukturę katalogów w zadanym
    //katalogu
    void ls(unsigned int op = 0) const override;
    
    //Operator /= dodający obiekt systemowy do katalogu
    void operator/=(MyItem* item);
    
    //Operator /= dodający sprytny wskaźnik do obiektu
    //systemowy do katalogu
    void operator/=(MyUnique&& ptr);
    
private:
    std::vector<MyUnique> m_items;
};