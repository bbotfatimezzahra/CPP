#pragma once
#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

static class ScalarConverter
{
	public :
		ScalarConverter();
		ScalarConverter(const ScalarConverter &copy);
		ScalarConverter &operator=(const ScalarConverter &rhs);
		~ScalarConverter();
		void convert(const std::string &str);
};

typedef enum e_types
{
	NONE,
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	LITERAL
}	t_types;

#endif
