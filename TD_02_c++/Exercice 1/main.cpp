#include "LinearSearch.hpp"
#include "JumpSearch.hpp"
#include "BinarySearch.hpp"
#include <vector>
#include <iostream>

int main() {
    std::vector<int> tableau = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int cible = 13;  

    std::cout << "Searching for target: " << cible << "\n";

    // Linear Search
    LinearSearch ls;
    int result = ls.search(tableau, cible);
    std::cout << "Total comparisons for Linear Search: ";
    ls.displaySearchResults(std::cout, result, cible);

    // Jump Search
    JumpSearch js;
    result = js.search(tableau, cible);
    std::cout << "Total comparisons for Jump Search: ";
    js.displaySearchResults(std::cout, result, cible);

    // Binary Search
    BinarySearch bs;
    result = bs.search(tableau, cible);
    std::cout << "Total comparisons for Binary Search: ";
    bs.displaySearchResults(std::cout, result, cible);

    return 0;
}
