
#include <cstdlib>

#include "BitcoinExchange.hpp"

void	checkDateFormat(std::string date) {

	int daysIntMonths[12] = {31, 28, 31, 30,
							31, 30, 31, 31,
							30, 31, 30, 31};
	bool		leapYear = false;

	std::stringstream ss(date);
	std::string year;
	std::string month;
	std::string day;

	if (!std::getline(ss, year, '-')) {
		std::cout << "Error: bad input ==> "<< date << std::endl;
		return;
	}

	if (!std::getline(ss, month, '-')) {
		std::cout << "Error: bad input ==> " << date << std::endl;
		return;
	}

	if (!std::getline(ss, day)) {
		std::cout << "Error: bad input ==> " << date << std::endl;
		return;
	}

	for (size_t i = 0; i < year.size(); ++i) {
		if (!std::isdigit(year[i])) {
			std::cout << "Error: bad input ==> " << date << std::endl;
			return;
		}
	}
	for (size_t i = 0; i < month.size(); ++i) {
		if (!std::isdigit(month[i])) {
			std::cout << "Error: bad input ==> " << date << std::endl;
			return;
		}
	}
	for (size_t i = 0; i < day.size(); ++i) {
		if (!std::isdigit(day[i])) {
			std::cout << "Error: bad input ==> " << date << std::endl;
			return;
		}
	}

	int tmp = std::atoi(year.c_str());
	if (tmp < 0)
		return;
	if ((tmp % 4 == 0 && tmp % 100 != 0) || tmp % 400 == 0) {
		leapYear = true;
	}

	tmp = std::atoi(month.c_str());
	if (tmp < 1 || tmp > 12) {
		std::cerr << "Error: bad input ==> " << date << std::endl;
		return;
	}
	int m = tmp - 1;

	tmp = std::atoi(day.c_str());
	if (leapYear == true && m == 1) {
		if (tmp > 29)
			return;
	}
	else if (tmp < 0 || tmp > daysIntMonths[m]) {
		std::cerr << "Error: bad input ==> " << date << std::endl;
		return;
	}
	std::cout << "Good input ==> " << date << std::endl;
}

void	openInputFile(BitcoinExchange &btc, const char *inputFile) {

	(void)btc;
	(void)inputFile;
	std::ifstream file("data.csv");
	if (file.fail())
		throw BitcoinExchange::errorOpen();

	std::string line;
	std::string date;
	std::string value;
	while (std::getline(file, line)) {
		size_t sep = line.find(',');
		date = line.substr(0, sep);
		value = line.substr(sep + 1);
		// std::cout << date << std::endl;
		checkDateFormat(date);
	}
}


int	main(int ac, char* av[]) {

	if (ac == 3) {
		BitcoinExchange btc;
		try {
			openInputFile(btc, av[2]);
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
}

