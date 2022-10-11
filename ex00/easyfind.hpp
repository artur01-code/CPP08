#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <algorithm>

template<typename T>
typename T::iterator easyFind(T &container, int target)
{
	typename T::iterator it = std::find(container.begin(), container.end(), target);

	if (it == container.end())
		throw std::invalid_argument("easyFind: Target not found in container");
	return (it);
}

#endif
