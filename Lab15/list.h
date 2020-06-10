#pragma once

#include<iostream>
#include<stdexcept>


//Szablon klasy reprezentującej węzeł w liście dwukierunkowej,
//przechowujacy wartosc zadanego typu.
template<typename T>
class Node
{
public:
    //Konstruktor inicjalizujacy wezel listy wartoscia oraz wskaznikami na
    //kolejny i poprzedni element w liscie.
    Node(T val, Node<T>* p, Node<T>* n)
        : value(val), prev(p), next(n)
    {}

    //Wartosc wezla
    T value;
    //Wskaznik na poprzedni element
    Node<T>* prev;
    //Wskaznik na kolejny element
    Node<T>* next;
};


//Szablon klasy reprezentujacej kontener bedacy opakowaniem na
//liste dwukierunkowa, o zadanym typie przechowywanych wartosci.
template<typename T>
class List
{
public:
    //Konstruktor domyslny inicjalizujacy wskazniki listy na nullptr
    List()
        : m_head(nullptr), m_tail(nullptr)
    {
    }
    
    //Konstruktor kopiujacy, wykonujacy gleboka kopie listy.
    List(const List<T>& list)
        : m_head(nullptr), m_tail(nullptr)
    {
        auto node = list.m_head;
        
        while(node)
        {
            push_back(node->value);
            node = node->next;
        }
    }
    
    //Konstruktor inicjalizujacy liste wartosciami z przekazanej tablicy
    List(size_t size, const T* arr)
        : m_head(nullptr), m_tail(nullptr)
    {
        for(size_t i=0; i<size; i++)
            push_back(arr[i]);
    }
    
    //Destruktor czyszczacy pamiec po liscie.
    ~List()
    {
        clear();
    }
    
    //Funkcja ktora dodaje element na koniec listy dwukierunkowej
    void push_back(T val)
    {
        Node<T>* node = new Node<T>(val, m_tail, nullptr);

        m_tail = node;
        
        if(!m_head)
            m_head = node;
        else
            node->prev->next = node;
    }
    
    //Funkcja, ktora usuwa element z konca listy dwukierunkowej
    void pop_back()
    {
        if(m_head)
        {
            auto toDel = m_tail;
            
            if(toDel->prev)
                toDel->prev->next = nullptr;
            else
                m_head = nullptr;
                
            delete m_tail;
        }
    }
    
    //Funkcja zwracajaca referencje do wartosci przechowywanej na
    //poczatku listy dwukierunkowej
    T& front()
    {
        if(m_head)
            return m_head->value;
            
        throw std::range_error("error");
    }
    
    //Funkcja usuwajaca wszystkie elementy z listy dwukierunkowej i
    //czyszczaca po nich pamiec.
    void clear()
    {
        auto node = m_head;
        
        while(node)
        {
            auto next = node->next;
            delete node;
            node = next;
        }
        
        m_head = nullptr;
        m_tail = nullptr;
    }
    
    //Zaprzyjazniony operator << wypisujacy elementy listy dwukierunkowej
    friend std::ostream& operator<< (std::ostream& os, const List<T> list)
    {
        auto node = list.m_head;
        
        if(!node)
            return os;
        else
        {
            std::cout << "{";
            while(node != list.m_tail)
            {
                std::cout << "\"" << node->value << "\", ";
                node = node->next;
            }
            std::cout << "\"" << node->value << "\"}";
        }
        
        return os;
    }
    
    
    //Klasa reprezentujaca iterator w liscie dwukierunkowej. 
    //Posiada dwa tryby: iterowania w przod i iterowania w tyl.
    class Iterator
    {
    public:
        //Konstruktor inicjalizujacy iterator wskaznikiem na obecnie wskazywany
        //element oraz flaga w jakim trybie ma pracowac.
        Iterator(Node<T>* p, bool rev = false)
        : m_pointer(p), m_reverse(rev)
        {}
        
        //Operator post-inkrementacji iteratora.
        Iterator operator++(int i)
        {
            auto ptr = m_pointer;
            
            if(!m_reverse)
                m_pointer = m_pointer->next;
            else
                m_pointer = m_pointer->prev;
                
            return ptr;
        }
        
        //Operator pre-inkrementacji iteratora.
        Iterator operator++()
        {
            if(!m_reverse)
                m_pointer = m_pointer->next;
            else
                m_pointer = m_pointer->prev;
                
            return m_pointer;
        }
        
        //Operator * zwracajacy wartosc elementu pod wskazywanym przez iterator
        //adresem.
        T operator*()
        {
            return m_pointer->value;
        }
        
        //Operator -> zwracajacy wskaznik do elementu pod wskazywanym przez iterator
        //adresem.
        T* operator->()
        {
            return &(m_pointer->value);
        }
        
        //Operator != sprawdzajacy czy dwa iteratory wskazuja na ten sam element
        bool operator!=(const Iterator& it)
        {
            return m_pointer != it.m_pointer;
        }
        
    private:
        Node<T>* m_pointer;
        bool m_reverse;
    };
    
    //Zwraca iterator pokazujacy na poczatek listy dwukierunkowej
    Iterator begin() const { return Iterator(m_head); }
    
    //Zwraca iterator pokazujacy za koncem listy dwukierunkowej
    Iterator end() const { return Iterator(nullptr); }
    
    //Zwraca iterator odwrotny, pokazujacy na koniec listy dwukierunkowej
    Iterator rbegin() const { return Iterator(m_tail, true); }
    
    //Zwraca iterator odwrotny, pokazujacy przed poczatkiem listy dwukierunkowej
    Iterator rend() const { return Iterator(nullptr, true); }

    
private:
    Node<T>* m_head;
    Node<T>* m_tail;
};
