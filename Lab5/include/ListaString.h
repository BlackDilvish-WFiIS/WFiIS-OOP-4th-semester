#pragma once

#include<iostream>
#include<string>
#include<vector>

//Klasa bedaca kontenerem na napisy
//która zapewnia korzystanie z mechanizmu przenoszenia.
class ListaString
{ 
public:
	//Konstruktor domyslny ktory daje glosny efekt jesli zmienna m_doNoise jest
	//ustawiona na true
	ListaString();

	//Konstruktor kopiujacy ktory daje glosny efekt jesli zmienna m_doNoise jest
	//ustawiona na true
	ListaString(const ListaString& list);

	//Konstruktor przenoszacy ktory daje glosny efekt jesli zmienna m_doNoise jest
	//ustawiona na true
	ListaString(ListaString&& list);

	//Destruktor ktory daje glosny efekt jesli zmienna m_doNoise jest
	//ustawiona na true
	~ListaString();

	//Ustawia zmienna m_doNoise na wartosc przekazana jako parametr
	static void rob_halas(bool value);

	//Operator << dodajacy napis do listy napisow
	ListaString& operator<<(const std::string& text);

	//Funkcja wypisujaca wszyskie napisy w liscie
	void PrintStrings(std::ostream& os) const;

	//Funkcja zwracajaca element z listy napisow o indeksie zadnym
	//w parametrze funkcji
	std::string operator[](size_t i) const;

private:
	std::vector<std::string> m_strings;
	static bool m_doNoise;
};

std::ostream& operator<<(std::ostream& os, const ListaString& list);