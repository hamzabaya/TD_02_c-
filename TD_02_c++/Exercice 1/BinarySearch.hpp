#ifndef BINARYSEARCH_HPP
#define BINARYSEARCH_HPP

#include "SearchingAlgorithm.hpp"

class BinarySearch : public SearchingAlgorithm {
public:

    BinarySearch();  

    int search(const std::vector<int>& tableau, int cible) override;  
};

#endif
