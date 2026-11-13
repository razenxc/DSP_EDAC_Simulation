#include "basic_methods.hxx"
#include "utils.hxx"

#include <iostream>
#include <vector>
#include <cstdint>
#include <string>
#include <stdexcept>

void even_parity()
{
	std::cout << std::endl;
	std::cout << "=== Even parity simulation ===" << std::endl;

	// =============
	// TRANSMITTER
	std::vector<uint16_t> input_data;

	// well I could use boolean instead of uint16 but I realized it only after implementation of the code below
	std::string temp_input;
	uint32_t temp_numeric_output;
	std::cout << "[*] Enter a string of bits (% 2 == 0) that is divisible by 2 withot a remainder." << std::endl;
	std::cout << "[*] I won’t be validating each individual character. You are on your own." << std::endl; // I did validations anyway

	// Input
	for (;;)
	{
		std::cin >> temp_input;

		// division check
		if (temp_input.length() % 2 != 0)
		{
			std::cout << "[!] You were told to enter a string of bits that is divisible by 2 without a remainder. Try again!" << std::endl;
			continue;
		}

		// 1 and 0 only check
		bool is_valid = true;
		for (const char var : temp_input)
		{
			if (var != '0' && var != '1')
			{
				is_valid = false;
				break;
			}
		}

		if (!is_valid)
		{
			std::cout << "[!] You were told to enter a string of bits. Try again!" << std::endl;
			continue;
		}

		break;
	}

	// convert input string to vector of uint16s
	for (size_t i = 0; i < temp_input.length(); i++)
	{
		uint16_t numeric_val = temp_input[i] - '0';
		input_data.push_back(numeric_val);
	}

	// count 1s
	uint32_t temp_1s_count = 0;
	for (const uint16_t var : input_data)
	{
		if (var == 1) temp_1s_count++;
	}

	// add 1 in the end if count of 1s is even
	if (temp_1s_count % 2 != 0)
	{
		input_data.insert(input_data.end(), 1);
	}
	// add 0 in the end if count of 1s is odd
	else if (temp_1s_count % 2 == 0)
	{
		input_data.insert(input_data.end(), 0);
	}
	else
	{
		throw std::exception("[?] Something unknown went wrong...");
	}

	// error vector (To-Do: implement random error)

	std::vector<uint16_t> e_vec(input_data.size(), 0);
	e_vec.back() = 1;

	// output
	std::cout << "[+] Input data:";
	for (const uint16_t var : input_data)
	{
		std::cout << var;
	}

	std::cout << std::endl;

	

	// error simulation (input_data XOR e_vec)
	std::cout << "[+] Error vec:";
	for (const uint16_t var : e_vec)
	{
		std::cout << var;
	}
	std::cout << std::endl;

	// composing of data that will be transmitted
	std::vector<uint16_t> request = Utils::XOR_uint16t_vectors(input_data, e_vec);
	if (request.empty())
	{
		throw std::exception("[!] Execution failed as vectors was different sizes");
	}

	// output of the data that will be transmitted
	std::cout << "[+] Request: ";
	for (const uint16_t var : request)
	{
		std::cout << var;
	}
	std::cout << std::endl;

	// =========
	// RECEIVER
	uint32_t ones_count = 0;

	for (const uint16_t var : request)
	{
		if (var == 1) ones_count++;
	}

	// verification using the method
	if (ones_count % 2 != 0)
	{
		std::cout << "=== The transmission was corrupted. An odd number of 1s was detected in the bit string. ===" << std::endl;
	}
	else
	{
		std::cout << "=== The transmission was successful. The number of 1s in the received string is divisible by 2. ===" << std::endl;
	}

	std::cout << "=== Transmitted: ";
	for (const uint16_t var : input_data) { std::cout << var; }
	std::cout << " >>> Received: ";
	for (const uint16_t var : request) { std::cout << var; }
	std::cout << " ===" << std::endl;
}