#include "BinarySearch.hpp"
#include <cmath>

BinarySearch::BinarySearch() {}

int BinarySearch::search(const std::vector<int>& tableau, int cible) {
    numberComparisons = 0;
    int left = 0, right = tableau.size() - 1;

    while (left <= right) {
        int milieu = left + (right - left) / 2;
        numberComparisons++;

        if (tableau[milieu] == cible)
            return milieu;
        else if (tableau[milieu] < cible)
            left = milieu + 1;
        else
            right = milieu - 1;
    }

    return -1; 
}
