#pragma once

#include<iostream>

//Klasa wskazujaca na pewien bit w tablicy bitow 'BitArray'
class BitGetter
{
public:
	//Konstruktor inicjalizujacy referencje do bajtu i pozycje bitu w nim
	BitGetter(unsigned char& byte, size_t pos);

	//Funkcja ustawiajaca bit na ktory wskazuje obiekt, na zadana wartosc
	void operator=(bool val);
	//Funkcja zwracajaca wartoc bitu na ktory wskazuje obiekt
	operator bool();

private:
	unsigned char& m_byte;
	size_t m_pos;
};
