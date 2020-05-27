#pragma once

#include<iostream>
#include"Ksztalt.h"

class Trojkat : public Ksztalt
{
public:
	Trojkat(double a, double b, double c);

	void wypisz(std::ostream& os = std::cout) const override;
	double polePow() const override;

private:
	double fBase, sBase, tBase;

};
