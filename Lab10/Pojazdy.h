#pragma once

#include<iostream>
#include<string>
#include"Predkosc.h"


//Klasa bazowa dla wszystkich pojazdow. Zawiera zmienna numeru rejestracyjnego
//ktory posiada kazdy pojazd
class Pojazd
{
public:
    //Konstruktor inicjalizujacy zmienna numerem rejestracyjnym pojazdu
    Pojazd(const std::string& reg)
        : m_registration(reg) {}
        
    virtual ~Pojazd() = default;
    
    //Funkcja zwracajaca dokladny opis pojazdu (typ oraz nr rejestracji)
    virtual std::string GetDescription() const = 0;
    
protected:
    //Funkcja zwracajaca numer rejestracyjny pojazdu
    std::string GetRegistration() const { return m_registration; }
    
private:
    std::string m_registration;
};



//Przeladowany operator '<<' wypisujacy szczegolowy opis pojazdu
std::ostream& operator<<(std::ostream& os, const Pojazd& poj)
{
    os<<poj.GetDescription();
    return os;
}



//Klasa reprezentujaca pojazd ladowy. Dziedziczy po klasie Pojazd
class PojazdLadowy : virtual public Pojazd
{
public:
    //Konstruktor inicjalizujacy zmienna numerem rejestracyjnym pojazdu
    PojazdLadowy(const std::string& reg)
        : Pojazd(reg) {}
        
    std::string GetDescription() const override { return "PojazdLadowy <" + GetRegistration() + ">"; }
};



//Klasa reprezentujaca Samochod. Dziedziczy po klasie PojazdLadowy
class Samochod : public PojazdLadowy
{
public:
    //Konstruktor inicjalizujacy zmienna numerem rejestracyjnym pojazdu i 
    //jego predkoscia maksymalna
    Samochod(const std::string& reg, const PredkoscMaksymalna& speed)
        : Pojazd(reg), PojazdLadowy(reg), m_maxSpeed(speed) {}  
    
    std::string GetDescription() const override { return "Samochod <" + GetRegistration() + ">"; }
    
    //Zwraca predkosc maksymalna samochodu
    PredkoscMaksymalna predkoscMaksymalna() const { return m_maxSpeed; }
private:
    PredkoscMaksymalna m_maxSpeed;
};



//Klasa reprezentujaca Motorowke. Dziedziczy po klasie Pojazd
class Motorowka : virtual public Pojazd
{
public:
    //Konstruktor inicjalizujacy zmienna numerem rejestracyjnym pojazdu i 
    //jego predkoscia maksymalna
    Motorowka(const std::string& reg, const PredkoscMaksymalna& speed)
        : Pojazd(reg), m_maxSpeed(speed) {} 
        
    std::string GetDescription() const override { return "Motorowka <" + GetRegistration() + ">"; }
    
    //Zwraca predkosc maksymalna motorowki
    PredkoscMaksymalna predkoscMaksymalna() const { return m_maxSpeed; }
        
private:
    PredkoscMaksymalna m_maxSpeed;
};



//Klasa reprezentujaca Rower. Dziedziczy po klasie PojazdLadowy
class Rower : public PojazdLadowy
{
public:
    //Konstruktor inicjalizujacy zmienna numerem rejestracyjnym pojazdu
    Rower(const std::string& reg)
        : Pojazd(reg), PojazdLadowy(reg) {}
        
    std::string GetDescription() const override { return "Rower <" + GetRegistration() + ">"; }
};



//Klasa reprezentujaca Amfibie. Dziedziczy po klasie Samochod i Motorowka
class Amfibia : public Samochod, public Motorowka
{
public:
    //Konstruktor inicjalizujacy zmienna numerem rejestracyjnym pojazdu i 
    //jego predkoscia maksymalna na ziemi jak i w wodzie
    Amfibia(const std::string& reg, const PredkoscMaksymalna& landSpeed, const PredkoscMaksymalna& waterSpeed)
        : Pojazd(reg), Samochod(reg, landSpeed), Motorowka(reg, waterSpeed) {}
        
    std::string GetDescription() const override { return "Amfibia <" + GetRegistration() + ">"; }
        
    //Zwraca predkosc maksymalna amfibii na ziemi
    PredkoscMaksymalna predkoscMaksymalna_Lad() const { return Samochod::predkoscMaksymalna(); }
    
    //Zwraca predkosc maksymalna amfibii w wodzie
    PredkoscMaksymalna predkoscMaksymalna_Woda() const { return Motorowka::predkoscMaksymalna(); }
};