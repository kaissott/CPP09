
#include <cstdlib>

#include "BitcoinExchange.hpp"





int	main(int ac, char* av[]) {

	if (ac == 2) {
		BitcoinExchange btc;
		try {
			btc.initializeDataFile();
			btc.initializeInputFile(av[1]);
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	else
		std::cout << "Error : could not open file." << std::endl;
}
