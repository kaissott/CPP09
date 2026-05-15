#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
class   PmergeMe {

private :

    std::vector<int> vectorAlg;
    // std::deque<>;
    void    VectorAlgorithm(int *numberTab, int index);

public :

    PmergeMe(int ac, char **av);
    // PmergeMe(const PmergeMe &other);
    // PmergeMe& operator=(const PmergeMe &other);
    ~PmergeMe();


};



#endif