#ifndef SEARCHINGALGORITHM_HPP
#define SEARCHINGALGORITHM_HPP

#include <vector>
#include <iostream>


class SearchingAlgorithm{
    public : 
        int numberComparisons;

        static int totalComparisons;
        static int totalSearch;
        static double averageComparisons;

        SearchingAlgorithm();


        virtual int search(const std::vector<int>& elements, int cible) = 0;
        void displaySearchResults(std::ostream& os, int results, int target) ;

        
    



};


#endif