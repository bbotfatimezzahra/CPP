#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){};

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
	*this = copy;
}

BitcoinExchange & BitcoinExchange::operator=(const BitcoinExchange &rhs)
{
	if (this != &rhs)
	{
		_db = rhs._db;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange(){};

bool strToInt(const std::string& str, int &result)
{
	std::istringstream iss(str);
	return (iss >> result) && iss.eof();
}

bool strToFloat(const std::string& str, float &result)
{
	std::istringstream iss(str);
	if(!(iss >> result) && !iss.eof())
	{
		double test;
		iss.clear();
		if((iss >> test) && iss.eof())
			result = -2;
		else
			result = -1;
		return false;
	}
	return true;
}

bool 	checkLeapYear(int year)
{
	if (year % 400 == 0)
		return true;
	else if (year % 100 != 0 && year % 4 == 0)
		return true;
	else
		return false;
}

bool 	checkDay(int date[3])
{
	int leap = checkLeapYear(date[0]);

	if (date[1] == 2)
	{
		if ((leap && date[2] <= 29) || (!leap && date[2] <= 28))
			return true;
		else 
			return false;
	}
	else if (date[1] == 4 || date[1] == 6 || date[1] == 9 || date[1] == 11)
	{
		if (date[2] <= 30)
			return true;
		else
			return false;
	}
	else if (date[2] <= 31)
		return true;
	else
		return false;
}

void 	BitcoinExchange::handleError(std::string str, int flag)
{
	if (!flag)
	{
		std::cout << "Database File Error : "<< str << std::endl;
		throw DataBaseException();
	}
	else
		std::cout << "Error: "<< str << std::endl;
}

void 	BitcoinExchange::checkDate(std::string line, int flag)
{
	int date[3];
	std::string::size_type n;

	for (int i = 0; i < 3; i++)
	{
		n = line.size();
		if (i != 2)
		{
			n = line.find("-");
			if (n == std::string::npos)
				handleError("Bad Input", flag);
		}
		if (!strToInt(line.substr(0,n), date[i]))
			handleError("Bad Input", flag);
		if (date[i] <= 0)
			handleError("Bad Input", flag);
		if (i == 0 && date[i] > 2025)
			handleError("Bad Input", flag);
		if (i == 1 && date[i] > 12)
			handleError("Bad Input", flag);
		if (i == 2 && !checkDay(date))
			handleError("Bad Input", flag);
		if (i != 2)
			line = line.substr(n+1 , line.size()-n);
	}
}

float 	BitcoinExchange::checkValue(std::string line, int flag)
{
	float value;

	if (!strToFloat(line, value))
	{
		if (value == -1)
			handleError("Bad input",flag);
		else if (value == -2)
			handleError("too large a number",flag);
		return value;
	}
	if (value < 0)
		handleError("not a positive number",flag);
	if (flag && value > 1000)
	{
		handleError("too large a number",flag);
		value = -2;
	}
	return value;
}

void 	BitcoinExchange::calculateValue(std::string date, float amount)
{
	float value;
	std::map<std::string,float>::iterator it;

	it = _db.find(date);
	if (it == _db.end())
	{
		it = _db.lower_bound(date);
		if (it != _db.begin())
			value = std::reverse_iterator<std::map<std::string, float>::iterator>(it)->second;
		else
			value = it->second;
	}
	else
		value = it->second;
	std::cout << date << " => "<< amount << " = " << value * amount << std::endl; 
}

void 	BitcoinExchange::parseFile(std::string filename, std::string delim)
{
	int flag = (delim.compare(",") == 0)? 0 : 1;
	std::ifstream file(filename.c_str());
	std::string line;

	if (!file.is_open())
	{
		handleError("Cannot open file",flag);
		return;
	}
	std::getline(file, line);
	if (line.empty())
		handleError("Empty file", flag);
	if (!flag && line.compare("date,exchange_rate"))
		handleError("malformed first line", flag);
	else if (flag && line.compare("date | value"))
		handleError("malformed first line", flag);

	std::string 	date;
	float value;
	std::string::size_type n;

	line.clear();
	std::getline(file,line);
	while (!line.empty())
	{
		n = line.find(delim);
		if (n == std::string::npos)
		{
			handleError("Bad input", flag);
			line.clear();
			std::getline(file,line);
			continue;
		}
		date = line.substr(0, n);
		checkDate(date, flag);
		n += delim.size();
		value = checkValue(line.substr(n, line.size()-n), flag);
		if (!flag)
			_db.insert(std::make_pair(date, value));
		else if (value >= 0)
			calculateValue(date, value);
		line.clear();
		std::getline(file,line);
	}
}

BitcoinExchange::BitcoinExchange(std::string file)
{
	parseFile("data.csv", ",");
	parseFile(file, " | ");
}
