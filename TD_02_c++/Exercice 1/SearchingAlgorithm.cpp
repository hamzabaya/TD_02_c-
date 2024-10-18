#include "SearchingAlgorithm.hpp"
#include <iostream>
#include <vector>

using namespace std;

int SearchingAlgorithm::totalComparisons = 0;
int SearchingAlgorithm::totalSearch = 0;
double SearchingAlgorithm::averageComparisons = 0.0;

SearchingAlgorithm::SearchingAlgorithm(): numberComparisons(0) {}

void SearchingAlgorithm::displaySearchResults(std::ostream& os, int results, int target){
    totalComparisons += numberComparisons;
    ++totalSearch;
    averageComparisons = totalComparisons / totalSearch;
    os << totalComparisons << std::endl;
    os << averageComparisons << std::endl;   
}
