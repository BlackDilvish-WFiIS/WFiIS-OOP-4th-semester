#pragma once

#include<iostream>
#include"Ksztalt.h"

const double PI = 3.1415;

class Kolo : public Ksztalt
{
public:
	Kolo(double r);

	void wypisz(std::ostream& os = std::cout) const override;
	double polePow() const override;

private:
	double radius;

};
