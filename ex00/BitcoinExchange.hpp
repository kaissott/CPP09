#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <exception>
#include <time.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <map>

enum	e_type {

	DATA_FILE,
	INPUT_FILE
};

class BitcoinExchange {


public:

	class errorOpen : public std::exception {
		public:
		virtual const char* what() const throw();
	};

	void	initializeDataFile();
	void	initializeInputFile(char *inputFile);
	BitcoinExchange();

private:

	void	checkValue(std::string &date, std::string &value);
	void	checkInputValue(std::string &date, std::string &value);
	bool 	checkDateFormat(std::string &date, e_type type);
	void	findAndPrintDate(std::string &date, float value);
	std::map<std::string, float> _dataMap;

};


#endif
