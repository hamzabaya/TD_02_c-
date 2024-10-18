#ifndef LINEARSEARCH_HPP
#define LINEARSEARCH_HPP

//#include <vector>
#include "SearchingAlgorithm.hpp"

class LinearSearch : public SearchingAlgorithm {
public:
    LinearSearch();

    int search(const std::vector<int>& tableau, int cible) override;
    
};


#endif