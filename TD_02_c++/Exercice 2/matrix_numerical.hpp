#ifndef MATRIX_NUMERICAL_HPP
#define MATRIX_NUMERICAL_HPP

#include "matrix.hpp"
#include <stdexcept>
#include <cmath>


template <typename T>
class Matrix_numerical : public MatrixBase<T>{

public : 
    Matrix_numerical();
    Matrix_numerical(size_t r, size_t c);
    
    T getDeterminant() const;

    Matrix_numerical<T> operator+(const Matrix_numerical<T>& A) const;
    Matrix_numerical<T> operator-(const Matrix_numerical<T>& A) const;
    Matrix_numerical<T> operator*(const Matrix_numerical<T>& A) const;
    Matrix_numerical<T> operator/(const Matrix_numerical<T>& A) const;


    Matrix_numerical<T> getInverse() const;

    static Matrix_numerical<T> getIdentity(int n);


private :   
    T getFactor(size_t p, size_t q, size_t n) const;



};

#endif