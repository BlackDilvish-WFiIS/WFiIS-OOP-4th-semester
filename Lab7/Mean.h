#pragma once
#include<iostream>
#include<string>

//Klasa reprezentująca średnią z liczb i 
//posiadająca interfejs do operacji na wprowadzanych danych
class Mean
{
public:
    //Konstruktor ustawiający nazwę średniej
    Mean(const std::string& name);
    
    virtual ~Mean() = default;
    
    //Funkcja przyjmująca liczbę i zapisująca ją w sumie elementów średniej
    virtual Mean& operator<<(double data) = 0;
    
    //Funkcja zapobiegająca dodawaniu elementów do obiektu stałej średniej
    virtual const Mean& operator<<(double data) const = 0;
    
    //Funkcja zwracajaca wartosc sredniej z zapisanych liczb
    virtual double result() const = 0;
    
    //Ustawia sume i liczbe elementow na 0 - resetuje dane w sredniej
    void reset();

    //Funkcja ktora wypisuje nazwe sredniej
    friend std::ostream& operator<<(std::ostream& os,const Mean& mean);
    
protected:
    //Dodaje liczbe do sumy elementow wg. przepisu szczegolnej sredniej oraz
    //zwieksza liczbe elementow sredniej
    void AddElement(double data) { m_sum += data; m_count++; }
    
    double GetSum() const { return m_sum; }
    int GetCount() const { return m_count; }
    
private:
    std::string m_name;
    double m_sum = 0;
    int m_count = 0;
};