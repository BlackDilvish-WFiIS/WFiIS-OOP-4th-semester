#pragma once

// Klasa potrafiaca przechowywac rozne wartosci zmiennych roznych typow.
// Zmienne tego samego typu zawsze posiadaja te sama wartosc.
class SetHoldRet
{
public:

    // Szablon funkcji, ktora ustawia wartosc przechowywana przez klase dla
    // danego typu. Realizowane jest to za pomoca funkcji pomocniczej, w 
    // ktorej ta zmienna jest przechowywana jako zmienna statyczna.
    template<typename T>
    void base(const T& obj)
    {
        mediator(obj, true);
    }
    
    
    // Szablon funkcji, ktora zwraca stala referencje do zmiennej szczegolnego typu.
    // Mechanizm zrealizowany za pomoca funkcji pomocniczej, ktora posiada te
    // zmienna jako zmienna statyczna.
    template<typename T>
    const T& product()
    {
        return mediator(T());
    }
    
private:
    template<typename T>
    const T& mediator(const T& obj, bool create = false)
    {
        static T object;
        
        if(create)
            object = obj;
            
        return object;
    }
};