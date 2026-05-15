#include "RPN.hpp"


int main(int ac, char** av) {

    if (ac == 2) {
        const RPN rpn(av[1]);
    }
    else {
        std::cout << "Error\nPlease provide 1 argument" << std::endl;
    }

}