#pragma once

#include<iostream>

class Ksztalt
{
public:
	virtual ~Ksztalt() = default;

	virtual void wypisz(std::ostream& os = std::cout) const = 0;

	virtual double polePow() const = 0;

	static void wypisz(const Ksztalt& k);
};
