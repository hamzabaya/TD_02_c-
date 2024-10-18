#ifndef JUMPSEARCH_HPP
#define JUMPSEARCH_HPP

#include "SearchingAlgorithm.hpp"

class JumpSearch : public SearchingAlgorithm{
private:    
    int fenetre;

public:
    JumpSearch();

    int search(const std::vector<int>& tableau, int cible) override;

};


#endif
