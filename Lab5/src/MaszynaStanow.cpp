#include"MaszynaStanow.h"

MaszynaStanow::MaszynaStanow()
    : m_currentState(0)
{

} 

MaszynaStanow::~MaszynaStanow()
{
    deleteStates();
}

void MaszynaStanow::operator+=(Stan* state)
{
    m_states.push_back(state);
    state->SetMachine(this);
}

void MaszynaStanow::start()
{
    std::cout<<"Rozpoczynamy dzialanie maszyny stanow!\n";
    m_currentState = 0;
}

Stan& MaszynaStanow::operator()()
{
    return (*m_states[m_currentState]);
}

void MaszynaStanow::operator++()
{
    if(m_currentState < m_states.size())
        m_currentState++;
}

void MaszynaStanow::operator--()
{
    if(m_currentState > 0)
        m_currentState--;
}

void MaszynaStanow::deleteStates()
{
    for(auto& s : m_states)
        delete s;
    m_states.clear();
    m_currentState = 0;
}

void MaszynaStanow::print(std::ostream& os) const
{
    for(size_t i=0; i<m_states.size(); i++)
	{
		if(i == m_currentState)
			os << " >" << m_states[i]->nazwa() << "< ";
        else
            os <<  m_states[i]->nazwa()<< " "; 
	}
}

void MaszynaStanow::PrintSummary() const
{
    std::cout<<"Podsumowanie: \n";
    for(const auto& s : m_states)
        s->podsumowanie();
}

std::ostream& operator<<(std::ostream& os, const MaszynaStanow& machine)
{
	machine.print(os);
    return os;
}

