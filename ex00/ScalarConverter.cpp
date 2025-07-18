#include "ScalarConverter.hpp"
#include <iostream>
#include <climits>
#include <cfloat>
#include <cstdlib>
#include <iomanip>

ScalarConverter::type ScalarConverter::_typeOfStr;
char ScalarConverter::_char;
int ScalarConverter::_int;
float ScalarConverter::_float;
double ScalarConverter::_double;

ScalarConverter::ScalarConverter()
{
    std::cout << GREY << "ScalarConverter default constructor" << RESET << std::endl;
}

ScalarConverter::ScalarConverter(ScalarConverter const &src)
{
    (void)&src;
    std::cout << GREY << "ScalarConverter copy constructor" << RESET << std::endl;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &other)
{
    (void)&other;
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

void ScalarConverter::convert(std::string const &str)
{
    _typeOfStr = getType(str);

    switch (_typeOfStr)
    {
    case CHAR:
        if (str[0] == '\'')
            _char = str[1];
        else
            _char = str[0];
        _double = static_cast<double>(_char);
        printFromDouble();
        break;
    case INT:
    case FLOAT:
    case DOUBLE:
        _double = std::atof(str.c_str());
        printFromDouble();
        break;
    case INF_POS:
    case INF_NEG:
    case NANF:
        printSpecial();
        break;
    default:
        std::cout << "error: Unknown Type";
    }
}

/********************************************/
/********************************************/
/****** PRIVATE MEMBER FUNCTIONS ******/

void ScalarConverter::printFromDouble()
{
    if (_double < 128 && _double >= 0)
        printChar(static_cast<int>(_double));
    else
        std::cout << "char: impossible";

    if (_double <= INT_MAX && _double >= INT_MIN)
        std::cout << "\nint: " << static_cast<int>(_double);
    else
        std::cout << "\nint: impossible";

    std::cout << std::fixed;

    if (_double == static_cast<int>(_double))
        std::cout << std::setprecision(1);
    else
        std::cout << std::setprecision(2);

    if (_double <= FLT_MAX && _double >= -FLT_MAX)
        std::cout << "\nfloat: " << static_cast<float>(_double) << "f";
    else
        std::cout
            << "\nfloat: impossible";

    std::cout << "\ndouble: " << _double << std::endl;
}

void ScalarConverter::printChar(int c)
{
    std::cout
        << "char: ";
    if (std::isprint(c))
    {
        _char = static_cast<char>(c);
        std::cout << "'" << _char << "'";
    }
    else
    {
        if (c > 127 || c < 0)
            std::cout
                << "impossible";
        else
            std::cout
                << "unprintable";
    }
}

ScalarConverter::type ScalarConverter::getType(std::string const &str)
{
    size_t i = 0;
    bool dot = 0;
    bool nums = 0;
    size_t len = str.length();

    if (str.compare("+inff") == 0 || str.compare("+inf") == 0)
        return INF_POS;
    if (str.compare("-inff") == 0 || str.compare("-inf") == 0)
        return INF_NEG;
    if (str.compare("nan") == 0 || str.compare("nanf") == 0 || str.empty())
        return NANF;

    if ((str[i] == '-' || str[i] == '+') && len != 1)
        i++;

    while (str[i])
    {
        if (str[i] >= '0' && str[i] <= '9')
            nums = 1;
        else if (str[i] == '.')
            dot = 1;
        else
        {
            if (len == 1)
                return CHAR;
            if (str[0] == '\'')
            {
                if ((str[2] == '\'' && len == 3) || len == 1)
                    return CHAR;
                else
                    throw InputException();
            }
            if (str[i] == 'f' && i != len - 1)
                throw InputException();
            if (str[i] != 'f' && len != 1)
                throw InputException();
        }
        i++;
    }

    if (dot && len == 1)
        return CHAR;
    else if (dot && str[len - 1] == 'f')
        return FLOAT;
    else if (dot && str[len - 1] != 'f')
        return DOUBLE;
    else
        return INT;
}

void ScalarConverter::printSpecial()
{
    std::cout
        << "char: impossible\n"
        << "int: impossible\n";
    if (_typeOfStr == INF_POS)
        std::cout << "float: " << "+inff" << "\n"
                  << "double: " << "+inf"
                  << std::endl;
    else if (_typeOfStr == INF_NEG)
        std::cout << "float: " << "-inff" << "\n"
                  << "double: " << "-inf"
                  << std::endl;
    else if (_typeOfStr == NANF)
        std::cout << "float: " << "nanf" << "\n"
                  << "double: " << "nan"
                  << std::endl;
}
