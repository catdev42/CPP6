#include "Base.hpp"
#include <iostream>

Base::~Base()
{
    std::cout << GREY << "Base destructor" << RESET << std::endl;
    return;
}

Base *generate(void)
{
    int num = rand() % 3;
    switch (num)
    {
    case 0:
        return new A();
    case 1:
        return new B();
    case 2:
        return new C();
    default:
        return NULL;
    }
}
void identify(Base *p)
{
    if (dynamic_cast<A *>(p) != nullptr)
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B *>(p) != nullptr)
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C *>(p) != nullptr)
        std::cout << "C" << std::endl;
}

void identify(Base &p)
{
    try
    {
        (void)dynamic_cast<A &>(p);
        std::cout << "A" << std::endl;
        return;
    }
    catch (const std::exception &e)
    {
        ;
    }

    try
    {
        (void)dynamic_cast<B &>(p);
        std::cout << "B" << std::endl;
        return;
    }
    catch (const std::exception &e)
    {
        ;
    }

    try
    {
        (void)dynamic_cast<C &>(p);
        std::cout << "C" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "unknown type" << std::endl;
    }
}
