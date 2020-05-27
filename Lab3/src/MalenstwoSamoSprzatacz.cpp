#include"MalenstwoSamoSprzatacz.h"
#include"Malenstwo.h"

MalenstwoSamoSprzatacz::MalenstwoSamoSprzatacz(Malenstwo* ptr)
    : _ptr(ptr)
{
}

MalenstwoSamoSprzatacz::~MalenstwoSamoSprzatacz()
{
    delete _ptr;
}

Malenstwo* MalenstwoSamoSprzatacz::operator->()
{
    return _ptr;
}

