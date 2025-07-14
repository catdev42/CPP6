#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <cctype>
#include <exception>

#ifndef COLOR
#define COLOR
#define GREY "\033[0;30m"
#define RESET "\033[0m"
#endif

class ScalarConverter
{

public:
    static void convert(std::string const &str);

private:
    enum type
    {
        CHAR = 0,
        INT = 1,
        FLOAT = 2,
        DOUBLE = 3,
        INF_NEG = 4,
        INF_POS = 5,
        NANF = 6
    };

    class InputException : public std::exception
    {
    public:
        virtual const char *what() const throw()
        {
            return "Invalid Input.";
        }
    };

    static type _typeOfStr;
    static char _char;
    static int _int;
    static float _float;
    static double _double;

    static type getType(std::string const &str);
    static void printFromDouble();
    static void printChar(int c);
    static void printSpecial();

    ScalarConverter();
    ScalarConverter(ScalarConverter const &src);
    ScalarConverter &operator=(ScalarConverter const &rhs);
    ~ScalarConverter();
};

#endif
