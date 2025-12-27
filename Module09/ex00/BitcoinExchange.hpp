#pragma once
#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP
# include <iostream>
# include <map>
# include<sstream>
# include<fstream>
# include<iterator>

class BitcoinExchange
{
	private :
		std::map<std::string,float> _db;
		BitcoinExchange();
	public :
		BitcoinExchange(const BitcoinExchange &copy);
		BitcoinExchange(std::string file);
		BitcoinExchange & operator=(const BitcoinExchange &rhs);
		~BitcoinExchange();
		bool 	parseFile(std::string file, std::string delim);
		void 	calculateValue(std::string date, float amount);
		void 	handleError(std::string str, int flag);
		bool 	checkDate(std::string line, int flag);
		float 	checkValue(std::string line, int flag);
		class 	DataBaseException : public std::exception{
			public :
				const char *what() const throw(){return "";};
		};
	
};

#endif
