#pragma once

#include<iostream>
#include<vector>
#include"Malenstwo.h"

class ZbieraczMalenstw
{
public:
	~ZbieraczMalenstw();

	static std::vector<Malenstwo*> malenstwaPtr;
	static size_t allocatedMalenstwa;

private:

};
