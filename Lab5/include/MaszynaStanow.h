#pragma once

#include<iostream>
#include<vector>
#include"Stan.h"

//Klasa reprezentujaca maszyne stanow tj.: mozna do niej
//dodac stany i uruchamiac ich dzialanie
class MaszynaStanow
{ 
public:
	MaszynaStanow();
	~MaszynaStanow();

	//Operator += dodaje do maszyny kolejny stan
	void operator+=(Stan* state);

	//Uruchamia maszyne stanow - ustawia pozycje wskaznika stanu na 
	//pierwsza pozycje
	void start();

	//Zwraca aktualnie wybrany stan
	Stan& operator()();

	//Ustawia pozycje wskaznika stanu na kolejna
	void operator++();

	//Ustawia pozycje wskaznika stanu na poprzednia
	void operator--();

	//Wypisuje dostepne stany z zaznaczeniem aktualnie wybranego
	void print(std::ostream& os) const;

	//Wywoluje funkcje 'podsumowanie' z kazdego stanu
	void PrintSummary() const;
private:
	void deleteStates();

	std::vector<Stan*> m_states;
	size_t m_currentState;

};

std::ostream& operator<<(std::ostream& os, const MaszynaStanow& machine);

