#include "easyfind.hpp"
#include <vector>
#include <list>

int main(void)
{
	std::vector<int> vector;

	std::list<int> list;
	for (int i = 1; i < 10; i++)
	{
		vector.push_back(i);
		list.push_back(i);
	}
	std::cout << "trying to find 0 to 11 in list" << std::endl;
	for (int i = 1; i < 12; i++)
	{
		try
		{
			std::cout << *(easyFind(list, i)) << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	std::cout << std::string(50, '-') << std::endl;
	std::cout << "trying to find 0 to 11 in vector" << std::endl;
	for (int i = 1; i < 12; i++)
	{
		try
		{
			std::cout << *(easyFind(vector, i)) << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	return (0);
}
