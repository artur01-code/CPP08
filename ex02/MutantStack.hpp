#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <list>

template<typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack(void) {};
		MutantStack(MutantStack const &rhs) {*this = rhs;}
		~MutantStack(void) {}
		MutantStack &operator=(MutantStack const &rhs)
		{
			std::stack<T>::operator=(rhs);
			return (*this);
		}

		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator begin(void) {return (std::stack<T>::c.begin());}
		iterator end(void) {return (std::stack<T>::c.end());}
};

#endif
