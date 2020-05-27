#pragma once

#include<iostream>
#include"InfoSuperClass.h"

//Klasa bezpiecznego wskaznika ktory za pomoca wbudowanego licznika decyduje
//czy nalezy usunac obiekt
//Tak jak shared_ptr, moze wskazywac na obiekt na ktory wskazuja inne InfoSmartPtr
class InfoSmartPtr 
{
public:
	//Konstruktor inicjalizujacy pole wskaznika i licznika
	InfoSmartPtr(InfoClass* ptr);
	//Konstruktor kopiujacy zwiekszajacy licznik odwolan
	InfoSmartPtr(const InfoSmartPtr& sptr);
	//Bezpieczny destruktor (Zmniejsza licznik lub usuwa obiekt
	//na ktory wskazuje)
	~InfoSmartPtr();	

	//Przeladowany operator '=' zwiekszajacy licznik odwolan przy kopiowaniu
	InfoSmartPtr& operator=(const InfoSmartPtr& sptr);

	//Przeladowany operator '*' zwracajacy obiekt na ktory wskazuje sprytny wskaznik
	InfoClass& operator*() const { return *m_ptr; }
	//Przeladowany operator '->' zwracajacy wskaznik do obiektu na ktory wskazuje
	InfoClass* operator->() const { return m_ptr; }

private:
	void DecreaseCounter();

	InfoClass* m_ptr;
	int* m_counter;

};
