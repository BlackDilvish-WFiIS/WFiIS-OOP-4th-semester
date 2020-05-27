#pragma once

#include<iostream>
#include<string>
#include<exception>

//Prosta klasa posiadająca głośny konstruktor i destruktor. Posiada imie.
class Loudy
{
public:
    //Głośny konstruktor inicjalizujący obiekt zmienną name
    Loudy(const std::string& name)
        : m_name(name)
    {
        std::cout<<"Laudy "<<m_name<<" is waking up! \n";
    }
    
    //Głośny destruktor wypisujący imię obiektu
    ~Loudy()
    {
        std::cout<<"Laudy "<<m_name<<" is going to sleep... \n";
    }
    
    //Wyrzucenie wyjątku w celu pominięcia kodu aż do napotkania najbliższego
    //bloku catch
    void skip() const
    {
        throw std::runtime_error("Function Loudy::skip() was called");
    }
  
private:
    std::string m_name;
};


//Wczesna deklaracja wyprzedzająca klasy LoudyArray w celu 
//wykorzystania jej w klasie LoudyOutOfRangeException
class LoudyArray;


//Klasa reprezentująca wyjątek, który pojawia się gdy wykroczymy poza
//zakres tablicy wskaznikow do obiektów Loudy w klasie LoudyArray
class LoudyOutOfRangeException
{
public:
    //Konstruktor inicjalizujący pole wskaznikiem do obiektu
    //klasy LoudyArray, która rzuciła wyjątkiem LoudyOutOfRangeException
    LoudyOutOfRangeException(LoudyArray* arr)
        : m_arr(arr)
    {
    }
    
    //Destruktor czyszczący pamiec po obiekcie LoudyArray, który rzucił
    //wyjątkiem LoudyOutOfRangeException
    ~LoudyOutOfRangeException();
    
private:
    LoudyArray* m_arr;
};


//Klasa reprezentująca tablicę na wskazniki do obiektow klasy Loudy. 
//Jest to tablica o stałym rozmiarze i posiada obsługę błędu związanego z 
//podaniem niewlasciwego indeksu tablicy.
class LoudyArray
{
public:
    //Konstruktor inicjalizujacy obiekt zadanym rozmiarem oraz tworzy tablice
    //obiektow Loudy o zadanym rozmiarze
    LoudyArray(int size)
        : m_size(size), m_array(new Loudy*[size])
    {
        for(int i=0; i<m_size; i++)
            m_array[i] = nullptr;
    }
    
    //Ustawia wartosc tablicy w zadanym indeksie na przekazany do funkcji 
    //wskaznik do obiektu klasy Loudy. W razie gdy w podanym indeksie jest juz
    //obiekt, to ten jest usuwany i zastapiony nowym. W razie wykroczenia 
    //indeksiem poza zakres tablicy, rzucany jest wyjatek LoudyOutOfRangeExeption
    void set(int i, Loudy* loudy)
    {
        if(i<m_size)
        {
            if(m_array[i])
                delete m_array[i];
                
            m_array[i] = loudy;
        }
        else
        {
            delete loudy;
            throw LoudyOutOfRangeException(this);
        }
    }
    
    //Usuwa pamiec przydzielona do wszystkich zawartych w tablicy obiektow
    //oraz tablice.
    void clean()
    {
        for(int i=0; i<m_size; i++)
            delete m_array[i];
            
        delete[] m_array;
    }
    
private:
    int m_size;
    Loudy** m_array;
};
