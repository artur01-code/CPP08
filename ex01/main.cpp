#include "Span.hpp"

int main(void)
{
	srand(time(NULL));
	std::cout << std::string(60, '-') << std::endl;
	std::cout << "Creating an empty span and try adding 10" << std::endl;
	try
	{
		Span mySpan;
		mySpan.addNumber(10);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::string(60, '-') << std::endl;
	std::cout << "Creating span with size of 10 and try adding values" << std::endl;
	std::cout << "	until it runs out of capacity" << std::endl;
	try
	{
		Span mySpan(10);
		for (int i = 0; i < 11; i++)
		{
			std::cout << "adding " << i << ": ";
			mySpan.addNumber(i);
			std::cout << "success" << std::endl;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::string(60, '-') << std::endl;
	std::cout << "Creating span with size of 50 and assign random values" << std::endl;
	std::cout << "	check for longest and shortest span" << std::endl;
	try
	{
		Span mySpan(259);
		for (int i = 0; i < 25; i++)
		{
			int nbr = rand() % 100 + 1;
			mySpan.addNumber(nbr);
			std::cout << "mySpan[" << i << "]: " << nbr << std::endl;
		}
		std::cout << "longest: " << mySpan.longestSpan() << std::endl;
		std::cout << "shortest: " << mySpan.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::string(60, '-') << std::endl;
	std::cout << "Creating span with size of 25000 and assign random values" << std::endl;
	std::cout << "	check for longest and shortest span" << std::endl;
	try
	{
		Span mySpan(25000);
		for (int i = 0; i < 25000; i++)
		{
			int nbr = (rand() % 10000000) + 1;
;
			mySpan.addNumber(nbr);
			// std::cout << "mySpan[" << i << "]: " << nbr << std::endl;
		}
		std::cout << "longest: " << mySpan.longestSpan() << std::endl;
		std::cout << "shortest: " << mySpan.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::string(60, '-') << std::endl;
	std::cout << "Creating a span with no elements (or one)" << std::endl;
	std::cout << "	should throw an exception" << std::endl;
	try
	{
		Span mySpan;
		std::cout << "longest: " << mySpan.longestSpan() << std::endl;
		std::cout << "shortest: " << mySpan.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
}
