#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}


const char *BitcoinExchange::errorOpen::what() const throw() {
	return "Error\nOpen failed";
}
