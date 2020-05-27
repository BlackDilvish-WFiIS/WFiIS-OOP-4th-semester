#pragma once

#define STATE_TYPE( NAME ) class NAME : public Stan

class MaszynaStanow;

//Klasa abstrakcyjna reprezentująca pojedynczy stan w maszynie stanow
class Stan
{
public:
	//Operator () realizujacy wywolanie dzialania stanu
    virtual void operator()() = 0;

	//funkcja zwracajaca nazwe stanu
    virtual const char* nazwa() const = 0;

	//funkcja wywolujaca podsumowanie (zapisane dane w stanie)
    virtual void podsumowanie() const = 0;

    virtual ~Stan() = default;

	//Funkcja przypisujaca do stanu wskaznik do maszyny do ktorej
	//stan zostal przypisany
	//@praram: machine - wskaznik do maszyny do ktorej przypisany zostal stan
	void SetMachine(MaszynaStanow* machine);
protected:
	MaszynaStanow* m_machine;
};
