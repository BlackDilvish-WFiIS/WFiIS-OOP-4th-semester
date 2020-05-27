#pragma once

#include<iostream>

class Malenstwo;

class MalenstwoSamoSprzatacz
{
public:
	MalenstwoSamoSprzatacz(Malenstwo* ptr); 
	~MalenstwoSamoSprzatacz();

	Malenstwo* operator->();

private:
	Malenstwo* _ptr;

};
