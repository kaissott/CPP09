#include "BitcoinExchange.hpp"

void	checkLineFormat(BitcoinExchange &btc, std::string line) {

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