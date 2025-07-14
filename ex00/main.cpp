#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
		std::cout << "Usage: ./convert <number>" << std::endl;

	std::string str = argv[1];
	try
	{
		ScalarConverter::convert(str);
	}
	catch (std::exception &e)
	 {
        std::cerr << "Error: " << e.what() << std::endl;
        return (1);
    }
}
