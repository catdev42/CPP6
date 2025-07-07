#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>

#ifndef COLOR
#define COLOR
#define GREY "\033[0;30m"
#define RESET "\033[0m"
#endif

class Data
{
public:
    Data();
    Data(int num);
    Data(Data const &other);
    Data &operator=(Data const &other);
    ~Data();
    int getNum()const;

private:
   int number;
};

std::ostream &operator<<(std::ostream &o, Data const &infile);

#endif
