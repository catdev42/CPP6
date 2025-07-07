#include "Data.hpp"
#include <iostream>

Data::Data()
{
    number = rand() % 101;
    std::cout << GREY << "Data default constructor" << RESET << std::endl;
    return;
}
Data::Data(int num) : number(num)
{
    std::cout << GREY << "Data param constructor" << RESET << std::endl;
    return;
}
Data::Data(Data const &other)
{
    std::cout << GREY << "Data copy constructor" << RESET << std::endl;
    number = other.getNum();
    return;
}

Data &Data::operator=(Data const &other)
{
    std::cout << GREY << "Data copy assignment operator" << RESET << std::endl;
    if (this != &other)
    {
        number = other.getNum();
    }
    return *this;
}

Data::~Data()
{
    std::cout << GREY << "Data destructor" << RESET << std::endl;
    return;
}

/********************************************/
/********************************************/
/****** MEMBER FUNCTIONS ******/

int Data::getNum() const
{
    return number;
}

/********************************************/
/********************************************/
/****** STREAM ******/

std::ostream &operator<<(std::ostream &o, const Data &infile)
{
    o << infile.getNum();
    return o;
}

/********************************************/
/********************************************/
/****** PRIVATE ******/
