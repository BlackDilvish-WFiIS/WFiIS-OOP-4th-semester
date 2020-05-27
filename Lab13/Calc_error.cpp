#include"Calc_error.h"

Calc_error::Calc_error(std::runtime_error* err, const std::string& info,
                       const std::string& file, size_t line)
    : std::runtime_error(info + ", [plik = " + file + 
                         ", linia = " + std::to_string(line) + "]"), 
      m_prevError(err)
{
}


void Calc_error::handler() try
{
    throw;
}
catch(std::runtime_error* ex)
{
    std::cout<<" Zlapano wyjatek:  \n";
    
    unpackExceptions(ex);
}


void Calc_error::unpackExceptions(std::runtime_error* ex)
{
    while(ex)
    {
        std::cout<<" -- z powodu: "<<ex->what()<<std::endl;
        
        auto calc = dynamic_cast<Calc_error*>(ex);
        
        std::runtime_error* next = nullptr;
        
        if(calc)
            next = calc->m_prevError;
            
        delete ex;
        ex = next;
    }
}