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
void ScalarConverter::printConvert(std::string const &str)
{
    _typeOfStr = getType(str);

    switch (_typeOfStr)
    {
    case CHAR:
        _char = str[0];
        _double = static_cast<double>(_char);
        fromDouble();
        break;
    case INT:
        _int = std::stoi(str);
        _double = static_cast<double>(_int);
        fromDouble();
        break;
    case FLOAT:
        _float = std::stof(str);
        _double = static_cast<double>(_int);
        fromDouble();
        break;
    case DOUBLE:
        _double = std::stod(str);
        fromDouble();
        break;
    case INF_POS:
        break;
    case INF_NEG:
        break;
    case NANF:
        break;
    default:
        std::cout << "Error: Unknown Type";
    }
}

void ScalarConverter::printChar(int c)
{
    std::cout
        << "char: ";
    if (std::isprint(c))
    {
        _char = static_cast<char>(c);
        std::cout << c;
    }
    else
    {
        if (c > 127 || c < 0)
            std::cout
                << "char: impossible";
        else
            std::cout
                << "char: unprintable";
    }
}
// ./convert 0
// char: Non displayable
// int: 0
// float: 0.0f
// double: 0.0

void ScalarConverter::fromChar()
{
    _double = static_cast<double>(_int);
    fromDouble();

    // _int = static_cast<int>(_char);
    // printChar(_int);
    // _float = static_cast<float>(_int);
    // _double = static_cast<double>(_int);
    // std::cout
    //     << "\nint: "
    //     << static_cast<int>(_int)
    //     << "\nfloat: "
    //     << static_cast<float>(_float)
    //     << "f\ndouble: "
    //     << static_cast<double>(_double)
    //     << std::endl;
}

void ScalarConverter::fromInt()
{
    _double = static_cast<double>(_int);
    fromDouble();

    // _float = static_cast<float>(_int);
    // _double = static_cast<double>(_int);
    // printChar(_int);
    // std::cout
    //     << "\nint: "
    //     << _int
    //     << "\nfloat: "
    //     << _float
    //     << "f\ndouble: "
    //     << _double
    //     << std::endl;
}

// compicated
void ScalarConverter::fromFloat()
{
    _double = static_cast<double>(_float);
    fromDouble();
}

// complicated
void ScalarConverter::fromDouble()
{
    if (_double < 128 && _double >= 0)
        printChar(static_cast<int>(_double));
    else
        std::cout << "char: impossible";

    if (_double < std::numeric_limits<int>::max() && _double > std::numeric_limits<int>::min())
        std::cout << "\nint: " << static_cast<int>(_double);
    else
        std::cout << "\nint: impossible";

    if (_double < std::numeric_limits<float>::max() && _double > std::numeric_limits<float>::min())
        std::cout << static_cast<float>(_double) << "f";
    else
        std::cout << "\nfloat: impossible";

    std::cout << "\ndouble: " << _double;
}

// std::numeric_limits<int>::min()

// std::cout
//     << "char: "
//     << static_cast<char>(c)
//     << "\nint: "
//     << static_cast<int>(c)
//     << "\nfloat: "
//     << static_cast<float>(c)
//     << "f\ndouble: "
//     << static_cast<double>(c)
//     << std::endl;

// void ScalarConverter::printFloat(float f)
// {
//     std::cout << f;

// }

// void ScalarConverter::printDouble(double d)
// {
//     std::cout << d;
// }

// void ScalarConverter::unprintable()
// {
//     std::cout << "unprintable";
// }
// void ScalarConverter::unprintable(std::ostream &o)
// {
//     o << "char unprintable";
// }

/********************************************/
/********************************************/
/****** PRIVATE MEMBER FUNCTIONS ******/

ScalarConverter::type ScalarConverter::getType(std::string const &str)
{
    int i = 0;
    bool dot = 0;
    bool chars = 0;

    if (str.compare("+inff") == 0 || str.compare("+inf") == 0)
        return INF_POS;
    if (str.compare("-inff") == 0 || str.compare("-inf") == 0)
        return INF_NEG;
    if (str.compare("nan") == 0 || str.compare("nanf") == 0)
        return NANF;

    while (str[i])
    {
        if (str[i] >= '0' && str[i] <= '9')
            ;
        else if (str[i] == '.')
            dot = 1;
        else
            chars = 1;
    }

    if (dot && str.back() == 'f')
        return FLOAT;
    else if (dot && str.back() != 'f')
        return DOUBLE;
    else if (chars)
        return CHAR;
    else
        return INT;
}

/********************************************/
/********************************************/
/****** STREAM ******/

/********************************************/
/********************************************/
/****** PRIVATE ******/
