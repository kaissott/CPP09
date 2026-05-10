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

	static void	initializeDataFile();

	BitcoinExchange();

private:

	static bool checkDateFormat(std::string date);

	std::map<std::string, size_t> _dataMap;

};


#endif
