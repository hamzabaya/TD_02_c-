#include "LinearSearch.hpp"
#include "SearchingAlgorithm.hpp"


LinearSearch::LinearSearch() {};

int LinearSearch::search(const std::vector<int>& tableau, int cible) {
    numberComparisons = 0;

    for (size_t i=0; i < tableau.size(); i++){
        numberComparisons++;
        if (tableau [i] == cible){
            return i;
        }
    }
    
    return -1; // En cas d'erreur, cible pas trouvée
}

/*
int main (){
    std::vector<int> tableau = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int cible = 13;  
    LinearSearch ls;
    int result = ls.search(tableau, cible);
    std::cout << "r:"<< result << std::endl;
    std::cout << "n:" << ls.numberComparisons << std::endl;
    return 1;
}
*/