#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <exception>
#include <time.h>
#include <iostream>
#include <sstream>
#include <fstream>

class BitcoinExchange {


public:

	class errorOpen : public std::exception {
		public:
		virtual const char* what() const throw();
	};

	BitcoinExchange();
};


#endif
