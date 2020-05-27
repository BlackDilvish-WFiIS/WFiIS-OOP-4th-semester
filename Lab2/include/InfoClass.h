#pragma once

#include<iostream>
#include<string>

class InfoClass
{
public:
	//Konstruktor inicjalizujacy imie obiektu klasy (glosny)
	InfoClass(const std::string name);
	//Destruktor (glosny)
	virtual ~InfoClass();

	//Zwraca informacje o klasie w postaci obiektu klasy string
	virtual std::string info() const;
	//Zmienia imie obiektu
	void info(std::string newName);

private:
	std::string m_name;

};
