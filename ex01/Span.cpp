#include "Span.hpp"

Span::Span(void) : _content(0), _N(0)
{

}

Span::Span(unsigned int N) : _content(0), _N(N)
{

}

Span::Span(Span const &rhs)
{
	*this = rhs;
}

Span &Span::operator=(Span const &rhs)
{
	this->_content.clear();
	this->_content.insert(this->_content.begin(), rhs._content.begin(), rhs._content.end());
	this->_N = rhs._N;
	return (*this);
}

Span::~Span(void)
{

}

const char * Span::OutOfCapacityException::what() const throw()
{
	return ("* Out of Capacity *");
}

const char * Span::NoSpanPossibleException::what() const throw()
{
	return ("* No span possible *");
}

void Span::addNumber(int n)
{
	if (this->_content.size() >= this->_N)
		throw Span::OutOfCapacityException();
	this->_content.push_back(n);
}

unsigned int Span::shortestSpan(void)
{
	if (this->_content.size() < 2)
		throw Span::NoSpanPossibleException();
	std::vector<int> tmp = this->_content;
	std::sort(tmp.begin(), tmp.end());
	unsigned int span = *(tmp.begin() + 1) - *tmp.begin();
	for (std::vector<int>::iterator it = tmp.begin(); it != tmp.end() - 1; it++)
	{
		span = std::min(span, static_cast<unsigned int>(*(it + 1) - *it));
	}
	return (span);
}

unsigned int Span::longestSpan(void)
{
	if (this->_content.size() < 2)
		throw Span::NoSpanPossibleException();
	return (*max_element(this->_content.begin(), this->_content.end()) - *min_element(this->_content.begin(), this->_content.end()));
}

void Span::fillSpan(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	while (begin != end)
	{
		if (this->_content.size() >= this->_N)
			throw OutOfCapacityException();
		this->addNumber(*begin);
		begin++;
	}
}
