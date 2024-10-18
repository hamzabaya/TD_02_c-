#include "JumpSearch.hpp"
#include <cmath>

JumpSearch::JumpSearch() {};

int JumpSearch::search(const std::vector<int>& tableau, int cible){
    numberComparisons = 0;
    size_t n = tableau.size();        
    size_t fenetre = sqrt(n);
    size_t present ;

    while (tableau[std::min(fenetre, n) - 1] < cible){
        present = fenetre;
        fenetre += sqrt(n);
        if (present > n){
            return -1;
        }
    }

    for (size_t i = present; i < std::min(fenetre, n); i++){
        numberComparisons++;
        if (tableau [i] == cible){
            return i;
        }
    }

    return -1; 

}

