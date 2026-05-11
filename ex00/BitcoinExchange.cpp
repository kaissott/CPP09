#include "BitcoinExchange.hpp"

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>

BitcoinExchange::BitcoinExchange() {}


bool	BitcoinExchange::checkDateFormat(std::string &date) {

	const int daysIntMonths[12] =	{31, 28, 31, 30,
									31, 30, 31, 31,
									30, 31, 30, 31};
	std::stringstream ss(date);
	std::string year;
	std::string month;
	std::string day;

	bool		leapYear = false;

	if (!std::getline(ss, year, '-') || !std::getline(ss, month, '-') ||
		!std::getline(ss, day)) {
		std::cout << "Error: bad input ==> "<< date << std::endl;
		return false;
		}

	for (size_t i = 0; i < year.size(); ++i) {
		if (!std::isdigit(year[i])) {
			std::cout << "Error: bad input ==> " << date << std::endl;
			return false;
		}
	}
	for (size_t i = 0; i < month.size(); ++i) {
		if (!std::isdigit(month[i])) {
			std::cout << "Error: bad input ==> " << date << std::endl;
			return false;
		}
	}
	for (size_t i = 0; i < day.size(); ++i) {
		if (!std::isdigit(day[i])) {
			std::cout << "Error: bad input ==> " << date << std::endl;
			return false;
		}
	}

	int tmp = std::atoi(year.c_str());
	if (tmp < 0)
		return false;
	if ((tmp % 4 == 0 && tmp % 100 != 0) || tmp % 400 == 0) {
		leapYear = true;
	}

	tmp = std::atoi(month.c_str());
	if (tmp < 1 || tmp > 12) {
		std::cout << "Error: bad input ==> " << date << std::endl;
		return false;
	}
	const int m = tmp - 1;

	tmp = std::atoi(day.c_str());
	if (leapYear == true && m == 1) {
		if (tmp > 29)
			return false;
	}
	else if (tmp < 0 || tmp > daysIntMonths[m]) {
		std::cout << "Error: bad input ==> " << date << std::endl;
		return false;
	}
	std::cout << "Good input ==> " << date << std::endl;
	return true;
}

void	BitcoinExchange::checkValue(std::string &date, std::string &value) {

	float	valueConverted = 0;
	std::string				rest;
	std::stringstream		ss(value);

	if ((ss >> valueConverted) && !(ss >> rest)) {
		if (valueConverted > 0) {
			std::cout << "Good value : " << valueConverted << std::endl;
			this->_dataMap[date] = valueConverted;
		}
	}
	else {
		std::cout << "Bad Value : " << valueConverted << " " << rest << std::endl;
		return;
	}
}


void BitcoinExchange::initializeDataFile() {

	std::ifstream file("data.csv");
	if (file.fail())
		throw BitcoinExchange::errorOpen();

	std::string line;
	std::string date;
	std::string value;

	std::getline(file, line);
	while (std::getline(file, line)) {
		const size_t sep = line.find(',');
		if (sep == std::string::npos) {
			std::cout << "Error: bad input (missing separator) ==> " << line << std::endl;
			continue;
		}
		date = line.substr(0, sep);
		if (checkDateFormat(date) == false)
			continue;
		value = line.substr(sep + 1);
		checkValue(date, value);
	}

}

const char *BitcoinExchange::errorOpen::what() const throw() {
	return "Error\nOpen failed";
}
