#include "Serializer.hpp"
#include <iostream>

/********************************************/
/********************************************/
/****** MEMBER FUNCTIONS ******/

uintptr_t Serializer::serialize(Data *ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serializer::deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data *>(raw);
}

/********************************************/
/********************************************/
/****** STREAM ******/

/********************************************/
/********************************************/
/****** PRIVATE ******/

Serializer::Serializer()
{
    std::cout << GREY << "Serializer default constructor" << RESET << std::endl;
    return;
}

Serializer::Serializer(Serializer const &other)
{
    std::cout << GREY << "Serializer copy constructor" << RESET << std::endl;
    (void)&other;
    return;
}

Serializer &Serializer::operator=(Serializer const &other)
{
    std::cout << GREY << "Serializer copy assignment operator" << RESET << std::endl;
    (void)&other;
    return *this;
}

Serializer::~Serializer()
{
    std::cout << GREY << "Serializer destructor" << RESET << std::endl;
    return;
}
