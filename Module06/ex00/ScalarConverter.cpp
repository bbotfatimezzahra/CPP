#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
	*this = copy;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &rhs)
{
	(void) rhs;
	return *this;
}

ScalarConverter::~ScalarConverter()
{}

bool	isChar(const std::string &str)
{
	if (str.length() != 1 || isdigit(str[0]))
		return false;
	return true;
}

bool	isInt(const std::string &str)
{
	int	i=0;

	if (str[i] == '-')
		i++;
	while (i < str.length())
	{
		if (!isdigit(str[i]))
			return false;
		i++;
	}
	return true;
}

bool	isFloat(const std::string &str)
{
	int	i = 0;
	int	dot = 0;

	if (str[i] == '-')
		i++;
	while (i < str.length())
	{
		if (str[i] == 'f')
			break;
		if (str[i] == '.')
			dot++;
		if (dot > 1 || !isdigit(str[i]))
			return false;
		i++;
	}
	return true;


}

bool	isDouble(const std::string &str)
{

}

bool	isLiteral(const std::string &str)
{

}

void	castChar(const std::string &str)
{

}

void	castInt(const std::string &str)
{

}

void	castFloat(const std::string &str)
{

}

void	castDouble(const std::string &str)
{

}

void	castLiteral(const std::string &str)
{

}

void ScalarConverter::convert(const std::string &str)
{
	if (isChar(str))
		castChar(str);
	else if (isInt(str))
		castInt(str);
	else if (isFloat(str))
		castFloat(str);
	else if (isDouble(str))
		castDouble(str);
	else if (isLiteral(str))
		castLiteral(str);
	else
		std::cout << "UNKOWN TYPE" << std::endl;
}
