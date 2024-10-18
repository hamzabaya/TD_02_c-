#include "matrix_numerical.hpp"
#include <iostream>
#include <vector>
#include <stdexcept>

template <typename T>
Matrix_numerical<T>::Matrix_numerical() : MatrixBase<T>() {}

template <typename T>
Matrix_numerical<T>::Matrix_numerical(size_t rows, size_t cols)
    : MatrixBase<T>(rows, cols) {}

template <typename T>
T Matrix_numerical<T>::getDeterminant() const {
    if (this->rows != this->cols) {
        throw std::invalid_argument("La matrice doit être carrée pour calculer le déterminant.");
    }

    if (this->rows == 2) {
        return this->getElement(0, 0) * this->getElement(1, 1) - this->getElement(0, 1) * this->getElement(1, 0);
    }

    T determinant = 0;
    for (size_t i = 0; i < this->cols; ++i) {
        determinant += (i % 2 == 0 ? 1 : -1) * this->getElement(0, i) * getFactor(0, i, this->rows - 1);
    }

    return determinant;
}

template <typename T>
T Matrix_numerical<T>::getFactor(size_t p, size_t q, size_t n) const {
    Matrix_numerical<T> temp(n, n);
    size_t row = 0, col = 0;

    for (size_t i = 0; i < this->rows; i++) {
        for (size_t j = 0; j < this->cols; j++) {
            if (i != p && j != q) {
                temp.addElement(row, col++, this->getElement(i, j));
                if (col == n) {
                    col = 0;
                    row++;
                }
            }
        }
    }
    return temp.getDeterminant();
}

template <typename T>
Matrix_numerical<T> Matrix_numerical<T>::getInverse() const {
    T det = this->getDeterminant();
    if (det == 0) {
        throw std::runtime_error("La matrice n'a pas d'inverse.");
    }

    Matrix_numerical<T> inverse(this->rows, this->cols);
    return inverse; 
}

template <typename T>
Matrix_numerical<T> Matrix_numerical<T>::operator+(const Matrix_numerical<T>& other) const {
    if (this->rows != other.getRows() || this->cols != other.getCols()) {
        throw std::invalid_argument("Les dimensions des matrices doivent correspondre pour l'addition.");
    }
    Matrix_numerical<T> result(this->rows, this->cols);
    for (size_t i = 0; i < this->rows; ++i) {
        for (size_t j = 0; j < this->cols; ++j) {
            result.addElement(i, j, this->getElement(i, j) + other.getElement(i, j));
        }
    }
    return result;
}

template <typename T>
Matrix_numerical<T> Matrix_numerical<T>::operator-(const Matrix_numerical<T>& other) const {
    if (this->rows != other.getRows() || this->cols != other.getCols()) {
        throw std::invalid_argument("Les dimensions des matrices doivent correspondre pour la soustraction.");
    }
    Matrix_numerical<T> result(this->rows, this->cols);
    for (size_t i = 0; i < this->rows; ++i) {
        for (size_t j = 0; j < this->cols; ++j) {
            result.addElement(i, j, this->getElement(i, j) - other.getElement(i, j));
        }
    }
    return result;
}

template <typename T>
Matrix_numerical<T> Matrix_numerical<T>::operator*(const Matrix_numerical<T>& other) const {
    if (this->cols != other.getRows()) {
        throw std::invalid_argument("Les colonnes de la première matrice doivent correspondre aux lignes de la seconde matrice.");
    }
    Matrix_numerical<T> result(this->rows, other.getCols());
    for (size_t i = 0; i < this->rows; ++i) {
        for (size_t j = 0; j < other.getCols(); ++j) {
            T sum = 0;
            for (size_t k = 0; k < this->cols; ++k) {
                sum += this->getElement(i, k) * other.getElement(k, j);
            }
            result.addElement(i, j, sum);
        }
    }
    return result;
}

template <typename T>
Matrix_numerical<T> Matrix_numerical<T>::operator/(const Matrix_numerical<T>& other) const {
    Matrix_numerical<T> inverseOther = other.getInverse();
    return *this * inverseOther;
}

template <typename T>
Matrix_numerical<T> Matrix_numerical<T>::getIdentity(int size) {
    Matrix_numerical<T> identity(size, size);
    for (int i = 0; i < size; ++i) {
        identity.addElement(i, i, 1);
    }
    return identity;
}


