#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <exception>
#include <time.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <map>

class BitcoinExchange {


public:

	class errorOpen : public std::exception {
		public:
		virtual const char* what() const throw();
	};

	void	initializeDataFile();
	void	checkValue(std::string &date, std::string &value);
	BitcoinExchange();

private:

	bool checkDateFormat(std::string &date);

	std::map<std::string, float> _dataMap;

};


#endif
