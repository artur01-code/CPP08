#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>

class Span
{
	public:
		Span(void);
		Span(unsigned int N);
		Span(Span const &rhs);
		Span &operator=(Span const &rhs);
		~Span(void);
	private:
		std::vector<int> _content;
		unsigned int _N;
	public:
		class OutOfCapacityException : public std::exception
		{	
			const char *what() const throw();
		};
		class NoSpanPossibleException : public std::exception
		{	
			const char *what() const throw();
		};
		// std::vector<int> getContent(void);
		void addNumber(int n);
		unsigned int shortestSpan(void);
		unsigned int longestSpan(void);
		void fillSpan(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		void fillSpanButBetter(std::vector<int> vector);
};

#endif
