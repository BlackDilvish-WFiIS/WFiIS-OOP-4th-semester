#pragma once

#include<iostream>
#include<cstring>
#include"BitGetter.h"

//Klasa opakowujaca tablice bitow.
class BitArray
{
public:
	//Konstruktor inicjalizujacy tablice bitow o zadanym rozmiarze i zadana wartoscia
	BitArray(size_t size, bool type = false);
	//Konstruktor kopiujacy
	BitArray(const BitArray& arr);
	//Destruktor niszczacy przydzielona dynamicznie pamiec
	~BitArray();

	//operator [] zwraca tymczasowy obiekt 'BitGetter' przechowujacy referencje do wybanego bitu
	BitGetter operator[](size_t pos) const;
	//Przeladowany operator =
	BitArray operator=(const BitArray& arr);
	//Wypisuje zawartosc tablicy na ekran
	void print() const;
private:

	unsigned char *m_array;
	size_t m_bitsCount;

};
