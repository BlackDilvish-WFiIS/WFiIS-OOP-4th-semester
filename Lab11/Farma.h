#pragma once

#include<iostream>
#include<string>
#include<vector>
#include<memory>
#include<algorithm>
#include<map>
#include<utility>
#include"Zwierz.h"

//Klasa reprezentujaca farme. Jest to kontener na sprytne wskazniki wskazujace
//na obiekty dziedziczace po klasie Zwierz.
class Farma
{
public:
    ~Farma();

    //Wypisuje opis o kazdym z przechowywanych zwierzat, poprzedzony napisem
    //przekazanym jako parametr
    void wypisz(const std::string& desc) const
    {
        std::cout<<"-- "<<desc<<" --\n";
        
        for(const auto& a: m_herd)
            a->opisz();
    }
    
    //Dodaje do stada zwierze (mechanizm przeniesienia sprytnego wskaznika do
    //ciala klasy)
    void dodaj(std::unique_ptr<Zwierz>&& animal)
    {
        m_herd.push_back(std::move(animal));
    }
    
    //Zlicza ile razy wsrod przechowywanych zwierzat pojawia sie zadane imie
    size_t zliczImie(const std::string& name) const
    {
        return std::count_if(m_herd.begin(), m_herd.end(), [=](const std::unique_ptr<Zwierz>& a) { return a->imie() == name; });
    }
    
    //Przedstawia ile razy wsrod przechowywanych zwierzat pojawia sie kazde z
    //imion, w sposob posortowany
    void statystykaImion() const
    {
        std::map<std::string, size_t> names;
        
        for(const auto& a: m_herd)
            names[a->imie()]++;
         
        for(const auto& n: names)
            std::cout<<n.first<<": "<<n.second<<std::endl;
    }
    
    //Zwraca vector zawierajacy wskazniki do wszystkich owiec znajdujacych sie
    //na farmie
    std::vector<Owca*> wyprowadzOwce() const
    {
        std::vector<Owca*> sheep;
        
        for(const auto& a: m_herd)
        {
            auto sp = dynamic_cast<Owca*>(a.get());
            
            if(sp)
                sheep.push_back(sp);
        }
        
        return sheep;
    }

private:
    std::vector<std::unique_ptr<Zwierz>> m_herd;
};