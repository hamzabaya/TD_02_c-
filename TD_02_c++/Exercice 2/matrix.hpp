#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <vector>
#include <string>

using namespace std;

template <typename T>
class MatrixBase{
    protected : 
        vector<vector<T>> elements;
        size_t rows;
        size_t cols;



    public : 
        MatrixBase();
        MatrixBase(size_t, size_t);

        void addElement(size_t row, size_t col, const T& value);

        T getElement(size_t row, size_t col) const;

        size_t getRows() const;
        size_t getCols() const;

        void display() const;



};


#endif