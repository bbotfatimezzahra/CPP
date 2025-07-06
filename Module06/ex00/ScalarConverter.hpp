#pragma once
#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
# include <string>
# include <exception>

class ScalarConverter
{
	private :
		ScalarConverter();
		ScalarConverter(const ScalarConverter &copy);
		ScalarConverter &operator=(const ScalarConverter &rhs);
		~ScalarConverter();
	public :
		static void convert(const std::string &str);
		class ImpossibleConversionException : public std::exception{
			public :
				const char *what() const throw();
		};

};

#endif
