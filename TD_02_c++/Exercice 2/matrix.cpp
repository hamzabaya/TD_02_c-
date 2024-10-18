#include <vector>
#include "matrix.hpp"

using namespace std;

template <typename T>
MatrixBase<T>::MatrixBase() : rows(0), cols(0) {}

template <typename T>
MatrixBase<T>::MatrixBase(size_t r, size_t c) : rows(r), cols(c) {
    elements.resize(r, vector<T>(c));
}

template <typename T>
void MatrixBase<T>::addElement (size_t row, size_t col, const T& value){
    if (row < rows && col < cols){
        elements[row][col] = value;
    }
}

template <typename T>
T MatrixBase<T>::getElement(size_t row, size_t col) const{
    if (row < rows && col < cols) {
        return elements[row][col];
    }
    throw out_of_range ("Indice en dehors des bornes");
}

template <typename T>
size_t MatrixBase<T>::getRows() const{
    return rows;
}

template <typename T>
size_t MatrixBase<T>::getCols() const{
    return cols;
}

template <typename T>
void MatrixBase<T>::display() const{
    for (size_t i = 0; i < rows; ++i){
        for (size_t j = 0; j < cols; ++j){
            cout << elements[i][j] << " " ;
        }
        cout << endl;
    }
}

