#include <tuple>

#include "BitcoinExchange.hpp"

void	checkDateFormat(std::string date, char sep) {

	std::string dayIntMonth[12] = {"31", "28", "31", "30", "31", "30", "31", "31", "30", "31", "30", "31"};
	bool		leapYear = false;

	std::string year;
	std::string month;
	std::string day;
	std::string tmp;

	std::stringstream	ss(date);

	while (std::getline(ss, tmp, sep)) {
		
	}


}

void	checkLineInputFormat(BitcoinExchange &btc, std::string line) {


}

void	openInputFile(BitcoinExchange &btc, const char *inputFile) {

	std::ifstream file(inputFile);
	if (file.fail())
		throw BitcoinExchange::errorOpen();


	std::string line;
	while (std::getline(file, line)) {
		checkLineFormat(btc, line);
	}
}


int	main(int ac, char* av[]) {

	if (ac == 3) {
		BitcoinExchange btc();
		try {
			// openData();
			openInputFile(btc, av[2]);
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
}

