#pragma once

#include "ListaString.h"
#include "Stan.h"
#include <iostream>
#include <string> 
#include <vector>

//Klasa dziedziczaca po klasie stan, reprezentujaca liste dostepnych systemow
//na maszynie stanow
STATE_TYPE( DostepneSystemy ) {
public:
	//Konstruktor przyjmujacy obiekt klasy ListaString ktory przechowuje 
	//nazwy systemow, a konstruktor przenosi tę liste do pola w klasie
	DostepneSystemy(ListaString systems)
		: m_systList(std::move(systems))
		, m_selected(0)
	{
		
	}
	
	//Przeladowanie operatora klasy podstawowej uruchamia drugi system z listy systemow
	virtual void operator()() {
		std::cout << "Program mozna uruchomic na nastepujacych systemach: " << std::endl;
		std::cout << m_systList;
		
		//std::cin >> m_selected; 
		m_selected = 1; // <- udajemy wczytywanie danych
		
		std::cout << "wybrano \'" << m_systList[m_selected] << "\'" << std::endl;
	}
	
	virtual const char* nazwa() const  { 
		return "DostepneSystemy";
	}
	
	virtual void podsumowanie() const {
		std::cout << " * Wybrano system: \'" << m_systList[m_selected] << "\'" << std::endl;;
	}
	
private:
	ListaString  m_systList;
	unsigned int m_selected;
};

//Klasa dziedziczaca po klasie stan, reprezentujaca instalacje
//w maszynie stanow
STATE_TYPE( Instalacja ) {
public:
	//Przeladowanie operatora klasy podstawowej symuluje instalacje
	virtual void operator()() {
		std::cout << "Instalacja w toku... " << std::endl;
		std::cout << "OK!" << std::endl;
	}
	
	virtual const char* nazwa() const { 
		return "Instalacja";
	}
	
	virtual void podsumowanie() const {
		return;
	};
};

//Klasa dziedziczaca po klasie stan, symulujaca pobieranie od
//uzytkownika adresu email
STATE_TYPE( ZbieranieDanych )
{
public:
	//Konstruktor przyjmujacy jako parametr rodzaj danych do pobierania
	//od uzytkownika i zapisujacy go w polu klasy
	ZbieranieDanych(const std::string& emailaddress)
		: m_operationType(emailaddress)
	{
		
	}

	//Przeladowanie operatora klasy podstawowej symuluje pobranie od uzytkownika 
	//podanego w konstruktorze rodzaju danych
	virtual void operator()() {
		if(m_operationType == "Adres email")
		{
			//std::cin>>m_emailAddress
			m_emailAddress = "Nowak@mail.com";
			std::cout<<"Prosze podac dana: "<<m_operationType<<" = ?, podano '"<<m_emailAddress<<"'\n"; 
		}
	}

	virtual const char* nazwa() const { 
		return "ZbieranieDanych";
	}

	virtual void podsumowanie() const {
		std::cout<<" * Adres email = "<<m_emailAddress<<"\n";
	};

private:
	std::string m_emailAddress;
	std::string m_operationType;
};

//Klasa dziedziczaca po klasie stan, realizujaca wypisywanie
//podsumowania ze wszystkich stanow na maszynie stanow
STATE_TYPE( Podsumowanie )
{
public:
	//Przeladowanie operatora klasy podstawowej wypisuje
	//podsumowanie ze wszystkich stanow na maszynie stanow
	virtual void operator()() {
		m_machine->PrintSummary();
	}

	virtual const char* nazwa() const { 
		return "Podsumowanie";
	}

	virtual void podsumowanie() const {
		return;
	};
};