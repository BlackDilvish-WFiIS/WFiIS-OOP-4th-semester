#pragma once

#include<iostream>
#include"InfoClass.h"

class InfoSuperClass : public InfoClass
{
public:
	//Konstruktor inicjalizujacy pole 'num', odwolujacy
	//sie do konstruktora klasy bazowej
	InfoSuperClass(std::string name, int num);
	//Destruktor (glosny)
	~InfoSuperClass();

	//Zwraca informacje o klasie w postaci obiektu klasy string
	std::string info() const override;

private:
	int m_num;

};
