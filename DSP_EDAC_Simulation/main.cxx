#include "basic_methods.hxx"

#include <iostream>
#include <string>

int main()
{
	for (;;)
	{
		std::cout << "=== Select EDAC simulation method ===" << std::endl;
		std::cout << "1. Even parity" << std::endl;

		std::string input;
		std::cin >> input;
		Method choice = static_cast<Method>(std::stoi(input));

		switch (choice)
		{
		case 1:
			even_parity();
		default:
			std::cout << "[!] Wrong choice." << std::endl;
		}
	}
	return 0;
}
