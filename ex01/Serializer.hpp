#ifndef SERI_HPP
#define SERI_HPP

#include <exception>
#include "Data.hpp"
#include <stdint.h>

class Serializer
{

  private:
    Serializer();

  public:
    Serializer(const Serializer &src);

    ~Serializer();
    Serializer & operator=(const Serializer &assign);
		
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);

};

#endif