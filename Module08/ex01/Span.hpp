#pragma once
#ifndef SPAN_HPP
# define SPAN_HPP

class Span
{
	private :
		std::vector<int>	con;
		unsigned int	size;
		Span();
	public :
		Span(unsigned int N);
		Span(const Span &copy);
		Span &operator=(const Span &rhs);
		~Span();
		void addNumber(int elem);
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
		int shortestSpan() const;
		int longestSpan() const;
};

std::ostream &operator<<(std::ostream &out, const Span &c);

#endif
