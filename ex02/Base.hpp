#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>

#ifndef COLOR
#define COLOR
#define GREY "\033[0;30m"
#define RESET "\033[0m"
#endif

class Base
{
public:
    virtual ~Base();
};

Base * generate(void);
void identify(Base* p);
void identify(Base& p);

class A : public Base
{
};

class B : public Base
{
};

class C : public Base
{
};

#endif
