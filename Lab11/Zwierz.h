#pragma once

#include<string>
#include<iostream>

//Klasa bazowa opisujaca zwierze posiadajace imie.
class Zwierz
{
public:
    //Konstruktor inicjalizujacy imie zwierza
    Zwierz(const std::string& name)
        : m_name(name) {}
        
    virtual ~Zwierz() = default;
    
    //Zwraca imie zwierza
    std::string imie() const { return m_name; }
    
    //Wypisuje dane o zwierzu
    virtual void opisz() const = 0;
private:
    std::string m_name;
};


//Klasa reprezentujaca owce, dziedziczy po klasie zwierz. 
//Owca moze zostac obstrzyzona
class Owca : public Zwierz
{
public:
    //Konstruktor inicjalizujacy imie zwierza
    Owca(const std::string& name)
        : Zwierz(name) {}
        
    //Glosny destruktor informujacy owca o jakim imieniu zostala zniszczona
    //(wyslana do zagrody)
    ~Owca()
    {
        std::cout<<"Owca "<<imie()<<" wrocila do zagrody\n";
    }
    
    //Zwraca opis owcy: jej imie oraz informacje czy zostala obstrzyzona
    void opisz() const override
    {
        auto shedStatus = m_isShed ? "ostrzyzona" : "nieostrzyzona";
        std::cout<<"Owca "<<imie()<<" - "<<shedStatus<<std::endl;
    }
    
    //Zmienia status owcy na: 'ostrzyzona'
    void ostrzyz()
    {
        m_isShed = true;
    }
    
private:
    bool m_isShed = false;
};


//Klasa reprezentujaca krowe, dziedziczy po klasie zwierz. 
class Krowa : public Zwierz
{
public:
    //Konstruktor inicjalizujacy imie zwierza
    Krowa(const std::string& name)
        : Zwierz(name) {}
        
    //Glosny destruktor informujacy krowa o jakim imieniu zostala zniszczona
    //(wyslana do obory)
    ~Krowa()
    {
        std::cout<<"Krowa "<<imie()<<" wrocila do obory\n";
    }
        
    //Zwraca opis krowy: jej imie
    void opisz() const override
    {
        std::cout<<"Krowa "<<imie()<<std::endl;
    }    
};


//Klasa reprezentujaca konia, dziedziczy po klasie zwierz. 
class Kon : public Zwierz
{
public:
    //Konstruktor inicjalizujacy imie zwierza
    Kon(const std::string& name)
        : Zwierz(name) {}
        
    //Glosny destruktor informujacy kon o jakim imieniu zostal zniszczony
    //(wyslany do stajni)
    ~Kon()
    {
        std::cout<<"Kon "<<imie()<<" wrocil do stajni\n";
    }
        
    //Zwraca opis konia: jego imie
    void opisz() const override
    {
        std::cout<<"Kon "<<imie()<<std::endl;
    }    
};
