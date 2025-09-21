#pragma once
#ifndef SPAN_HPP
# define SPAN_HPP
# include <iostream>
# include <vector>
# include <algorithm>
# include <exception>

class Span
{
	private :
		std::vector<int>	_con;
		unsigned int	_size;
		Span();
	public :
		Span(unsigned int N);
		Span(const Span &copy);
		Span &operator=(const Span &rhs);
		~Span();
		unsigned int getSize(void) const;
		std::vector<int> getCon(void) const;
		void addNumber(int elem);
		void addRange(std::vector<int>::iterator begin,std::vector<int>::iterator end);
		int shortestSpan() const;
		int longestSpan() const;
		class FullCapacityException : public std::exception {
		public :
			const char *what() const throw() {
				return "Container Is Full";}
		};
		class NoSpanException : public std::exception {
		public :
			const char *what() const throw() {
				return "No Span Found";}
		};
};

std::ostream &operator<<(std::ostream &out, const Span &c);

#endif
