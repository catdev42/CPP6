#include "ScalarConverter.hpp"
#include <iostream>

ScalarConverter::ScalarConverter()
{
    std::cout << GREY << "ScalarConverter default constructor" << RESET << std::endl;
}

ScalarConverter::ScalarConverter(ScalarConverter const &src)
{
    std::cout << GREY << "ScalarConverter copy constructor" << RESET << std::endl;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &rhs)
{
    std::cout << GREY << "ScalarConverter copy assignment operator" << RESET << std::endl;
    return *this;
}

ScalarConverter::~ScalarConverter()
{
    std::cout << GREY << "ScalarConverter destructor" << RESET << std::endl;
}

/********************************************/
/********************************************/
/****** MEMBER FUNCTIONS ******/

/********************************************/
/********************************************/
/****** STREAM ******/

std::ostream &operator<<(std::ostream &o, const ScalarConverter &infile)
{
    o << "";
    return o;
}

/********************************************/
/********************************************/
/****** PRIVATE ******/
