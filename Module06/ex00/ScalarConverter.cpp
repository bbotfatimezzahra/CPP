#include "ScalarConverter.hpp"
#include <iostream>
#include <cstdlib>
#include <cerrno>
#include <climits>
#include <cfloat>
#include <iomanip>

static void	castInt(const std::string &str);
static void	castFloat(const std::string &str);
static void	castDouble(const std::string &str);

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

static bool	isChar(const std::string &str)
{
	if (str.length() == 1 && !std::isdigit(str[0]))
		return true;
	return false;
}

static bool	isInt(const std::string &str)
{
	size_t	i=0;

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

static bool	isFloat(const std::string &str)
{
	size_t	i = 0;
	int	dot = 0;
	int	f = 0;

	if (str[i] == '-')
		i++;
	if (!std::isdigit(str[i]))
		return false;
	while (i < str.length())
	{
		if (str[i] == '.' && !dot && str[i+1])
			dot++;
		else if (str[i] == '.' && (dot || !str[i+1]))
			return false;
		else if (str[i] == 'f' && isdigit(str[i-1]) && !str[i+1])
			f++;
		else if (!isdigit(str[i]))
			return false;
		i++;
	}
	if (!dot || !f)
		return false;
	return true;
}

static bool	isDouble(const std::string &str)
{
	size_t	i = 0;
	int	dot = 0;

	if (str[i] == '-')
		i++;
	if (!std::isdigit(str[i]))
		return false;
	while (i < str.length())
	{
		if (str[i] == '.' && !dot && str[i+1])
			dot++;
		else if (str[i] == '.' && (dot || !str[i+1]))
			return false;
		else if (!isdigit(str[i]))
			return false;
		i++;
	}
	if (!dot)
		return false;
	return true;
}

static bool	isLiteral(const std::string &str)
{
	if (!str.compare("-inff") || !str.compare("-inf"))
		return true;
	else if (!str.compare("+inff") || !str.compare("+inf"))
		return true;
	else if (!str.compare("nanf") || !str.compare("nan"))
		return true;
	else
		return false;
}

static void	castChar(const std::string &str)
{
	char	c = str[0];

	if (std::isprint(c))
		std::cout << "char: " << c << std::endl;
	else
		std::cout << "char: Non displayable"<< std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "float: " << static_cast<float>(c)<<"f"<< std::endl;
	std::cout << std::fixed <<  std::setprecision(1) <<  "double: " << static_cast<double>(c) << std::endl;
}

static void	castInt(const std::string &str)
{
	errno = 0;
	long	num = std::strtol(str.c_str(), 0, 10);

	if (errno || num < INT_MIN || num > INT_MAX)
		return (castFloat(str));

	if (std::isprint(static_cast<unsigned char>(num)))
		std::cout << "char: " << static_cast<char>(num) << std::endl;
	else if ( num < 0 || num > 255)
		std::cout << "char: Impossible"<< std::endl;
	else
		std::cout << "char: Non displayable"<< std::endl;
	std::cout << "int: " << num << std::endl;
	std::cout << std::fixed << std::setprecision(1) <<  "float: " << static_cast<float>(num) <<"f"<< std::endl;
	std::cout << std::fixed <<  std::setprecision(1) <<  "double: " << static_cast<double>(num) << std::endl;
}

static void	castFloat(const std::string &str)
{
	errno = 0;
	double	num = std::strtod(str.c_str(), 0);

	if (errno || num < FLT_MIN || num > FLT_MAX)
		return (castDouble(str));

	if (std::isprint(static_cast<unsigned char>(num)))
		std::cout << "char: " << static_cast<char>(num) << std::endl;
	else if ( num < 0 || num > 255)
		std::cout << "char: Impossible"<< std::endl;
	else
		std::cout << "char: Non displayable"<< std::endl;
	if (num < INT_MIN || num > INT_MAX)
		std::cout << "int: Impossible"<< std::endl;
	else
		std::cout << "int: " << static_cast<int>(num) << std::endl;
	std::cout << std::fixed <<  std::setprecision(1) << "float: " << num <<"f"<< std::endl;
	std::cout << std::fixed <<  std::setprecision(1) << "double: " << static_cast<double>(num) << std::endl;
}

static void	castDouble(const std::string &str)
{
	errno = 0;
	long double	num = std::strtold(str.c_str(), 0);

	if (errno || num < DBL_MIN || num > DBL_MAX)
	{
		std::cout << "char: Impossible"<< std::endl;
		std::cout << "int: Impossible"<< std::endl;
		std::cout << "float: Impossible"<< std::endl;
		std::cout << "double: Impossible"<< std::endl;
		return;
	}

	if (std::isprint(static_cast<unsigned char>(num)))
		std::cout << "char: " << static_cast<char>(num) << std::endl;
	else if ( num < 0 || num > 255)
		std::cout << "char: Impossible"<< std::endl;
	else
		std::cout << "char: Non displayable"<< std::endl;
	if (num < INT_MIN || num > INT_MAX)
		std::cout << "int: Impossible"<< std::endl;
	else
		std::cout << "int: " << static_cast<int>(num) << std::endl;
	if (num < FLT_MIN || num > FLT_MAX)
		std::cout << "float: Impossible"<< std::endl;
	else
		std::cout << std::fixed <<  std::setprecision(1) <<  "float: " << static_cast<float>(num) <<"f"<< std::endl;
	std::cout << std::fixed <<  std::setprecision(1) <<  "double: " << num << std::endl;
}

static void	castLiteral(const std::string &str)
{
	std::cout << "char: Impossible"<< std::endl;
	std::cout << "int: Impossible"<< std::endl;
	if (!str.compare("nan") || !str.compare("+inf") || !str.compare("-inf"))
	{
		std::cout << "float: " << str <<"f"<< std::endl;
		std::cout << "double: " << str << std::endl;
	}
	else
	{
		std::cout << "float: " << str << std::endl;
		std::cout << "double: " << str.substr(0, str.length()-1) << std::endl;
	}
}

void ScalarConverter::convert(const std::string &str)
{
	if (isChar(str))
		castChar(str);
	else if (isFloat(str))
		castFloat(str);
	else if (isDouble(str))
		castDouble(str);
	else if (isInt(str))
		castInt(str);
	else if (isLiteral(str))
		castLiteral(str);
	else
		std::cout << "UNKOWN TYPE" << std::endl;
}
