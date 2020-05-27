#pragma once

#include<iostream>
#include"MalenstwoSamoSprzatacz.h"

class Malenstwo
{
public:
	Malenstwo(int val = 0);

	void* operator new(size_t size);
	void* operator new[](size_t size);

	void operator delete(void* ptr);
	void operator delete[](void* ptr);

	int& wartosc();

private:
	int _val;

};
