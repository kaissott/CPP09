#include "BitcoinExchange.hpp"

#include <cctype>
#include <cstddef>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

BitcoinExchange::BitcoinExchange() {}


bool	BitcoinExchange::checkDateFormat(std::string &date, e_type type) {

	const int daysIntMonths[12] =	{31, 28, 31, 30,
									31, 30, 31, 31,
									30, 31, 30, 31};
	std::stringstream ss(date);
	std::string year;
	std::string month;
	std::string day;

	bool		leapYear = false;

	if (type == INPUT_FILE) {
		if (date[date.size() - 1] != ' ') {
			std::cout << "Error : Bad Input => " << date << std::endl;
			return false;
		}
	}
	if (!std::getline(ss, year, '-') || !std::getline(ss, month, '-') ||
		!std::getline(ss, day)) {
		std::cout << "Error: bad input ==> "<< date << std::endl;
		return false;
		}

	for (size_t i = 0; i < year.size(); ++i) {
		if (!std::isdigit(year[i])) {
			std::cout << "Error: bad input => " << date << std::endl;
			return false;
		}
	}
	for (size_t i = 0; i < month.size(); ++i) {
		if (!std::isdigit(month[i])) {
			std::cout << "Error: bad input => " << date << std::endl;
			return false;
		}
	}
	for (size_t i = 0; i < day.size(); ++i) {
		if (day[i] == ' ' && i == (day.size() - 1) && type == INPUT_FILE)
			continue;
		if (!std::isdigit(day[i])) {
			std::cout << "Error: bad input => " << date << "." <<  std::endl;
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
		std::cout << "Error: bad input => " << date << std::endl;
		return false;
	}
	const int m = tmp - 1;

	tmp = std::atoi(day.c_str());
	if (leapYear == true && m == 1) {
		if (tmp > 29)
			return false;
	}
	else if (tmp < 0 || tmp > daysIntMonths[m]) {
		std::cout << "Error: bad input => " << date << std::endl;
		return false;
	}
	return true;
}

void	BitcoinExchange::checkValue(std::string &date, std::string &value) {

	float	valueConverted = 0;
	std::string				rest;
	std::stringstream		ss(value);

	if ((ss >> valueConverted) && !(ss >> rest)) {
		if (valueConverted >= 0) {
			this->_dataMap[date] = valueConverted;
		}
	}
	else {
		std::cout << "Bad Value : " << valueConverted << " " << rest << std::endl;
		return;
	}
}

void	BitcoinExchange::findAndPrintDate(std::string &date, float value) {

	if (this->_dataMap[date]) {
		std::cout << date << " => " << value << " = " << value * this->_dataMap[date] << std::endl;
		return;
	}
	else {
		std::map<std::string, float>::iterator it = _dataMap.lower_bound(date);
		--it;
		if (it == _dataMap.begin())
			std::cout << "Error, No data for " << date << " = " << value << std::endl;
		else
			std::cout << date << " => " << value << " = " << value * it->second << std::endl;
	}

}

void	BitcoinExchange::checkInputValue(std::string &date, std::string &value) {

	float				valueConverted = 0;
	std::string 		rest;
	std::stringstream 	ss(value);

	if (value[0] != ' ')
		std::cout << "Error: Bad input (no space after separator)" << std::endl;
	if ((ss >> valueConverted) && !(ss >> rest)) {
		if (valueConverted >= 0 && valueConverted <= 1000) {
			std::string realDate = date.substr(0, date.size() - 1);
			findAndPrintDate(realDate, valueConverted);
		}
		else if (valueConverted > 1000) {
			std::cout << "Error: too large number." << std::endl;
		}
		else if (valueConverted < 0) {
			std::cout << "Error: not a positive number." << std::endl;
		}
	}
	else {
		std::cout << "Bad Value : " << valueConverted << " " << rest << std::endl;
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
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}
		date = line.substr(0, sep);
		if (checkDateFormat(date, DATA_FILE) == false)
			continue;
		value = line.substr(sep + 1);
		checkValue(date, value);
	}

}

void	BitcoinExchange::initializeInputFile(char *inputFile) {

	std::ifstream	file(inputFile);
	if (file.fail())
		throw BitcoinExchange::errorOpen();
	std::string line;
	std::string date;
	std::string value;

	while(std::getline(file, line)) {
		const size_t sep = line.find('|');
		if (sep == std::string::npos) {
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}
		date = line.substr(0, sep);
		if (checkDateFormat(date, INPUT_FILE) == false)
			continue;
		value = line.substr(sep + 1);
		checkInputValue(date, value);
	}

}

const char *BitcoinExchange::errorOpen::what() const throw() {
	return "Error\nOpen failed";
}
