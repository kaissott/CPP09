#include "PmergeMe.hpp"

#include <cctype>
#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>

void    PmergeMe::VectorAlgorithm(int *numberTab, int index) {

    std::vector<WLpairs> pairs;

    for (int i = 0; i < index; i += 2) {
        
    }

}

PmergeMe::PmergeMe(int ac, char **av) {

    int numbersTab[ac];

    for (int i = 1; i < ac; ++i) {

        for (int j = 0; av[i][j] != '\0'; ++j) {
            if (std::isdigit(av[i][j]) == 0) {
                std::cout << "Error" << std::endl;
                return;
            }
        }
        const int tmp = std::atoi(av[i]);
        numbersTab[i - 1] = tmp;
    }
    VectorAlgorithm(numbersTab, ac - 1);
}

PmergeMe::~PmergeMe() {
    
}