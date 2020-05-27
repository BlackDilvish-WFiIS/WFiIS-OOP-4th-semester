#pragma once

#include<iostream>
#include"Ksztalt.h"

class Kwadrat : public Ksztalt
{
public:
	Kwadrat(double a); 

	void wypisz(std::ostream& os = std::cout) const override;
	double polePow() const override;

private:
	double base;
};
