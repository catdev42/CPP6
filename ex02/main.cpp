#include <iostream>
#include "Base.hpp"

int main(void)
{
	srand(time(0));
	Base *basePtr = generate();

	identify(basePtr);
	identify(*basePtr);

	delete basePtr;
}
