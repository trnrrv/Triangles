#pragma once
#include <cstddef>
#include <stdexcept>
#include <vector>

#define MAX_TABLE_SIZE 10

template <typename T> 
class Matrix {
private:
    struct MatrixData {
        size_t _dimSize;
        T** _data;
    };
    struct MatrixData createSubMatrix(const size_t pivot_col, const size_t dimSize);
public:
    struct MatrixData mFull;
    Matrix(size_t dimSize, T **data) {
        if((dimSize > MAX_TABLE_SIZE) || (dimSize < 0) ||
            (!data))
            throw std::invalid_argument("Incorrect Matrix parameters!");

        mFull._dimSize = dimSize;
        mFull._data = data; //copy pointer
    }
    ~Matrix() {}

    T calcD(struct MatrixData m);
    std::vector<T> getUpStringCoef(struct MatrixData m);
};

template <typename T> 
T Matrix<T>::calcD(struct Matrix<T>::MatrixData m) {
    T cumulSum = 0;

    //Base cases
    if(m._dimSize == 0) {
        throw std::invalid_argument("Incorrect Matrix parameters!");
        return 0;
    } else if(m._dimSize == 1) {
        return m._data[0][0];
    } else if(m._dimSize == 2) {
        return m._data[0][0]*m._data[1][1] - m._data[0][1]*m._data[1][0];
    } else {
        for(size_t i = 0; i < m._dimSize; i++) {
            struct Matrix<T>::MatrixData subM = createSubMatrix(i, m._dimSize);
            cumulSum += calcD(subM);
        }
    } 
    return cumulSum;
}

/**
 * @brief Creates submatrix for upper string in matrix
 */
template <typename T>
struct Matrix<T>::MatrixData Matrix<T>::createSubMatrix(const size_t pivot_col, const size_t dimSize) {
    T subData[dimSize-1][dimSize-1];     
    size_t newCol = 0;                  
    for(size_t i = 0; i < dimSize; i ++) { //columns
        for(size_t j = 1; j < dimSize; j ++) { //strings
            if(i != pivot_col) {
                newCol = i < pivot_col ? i : i - 1;
                subData[newCol][j-1] = mFull._data[j][i];
            }    
        }
    }   

    T** ptr = new T*[dimSize-1];
    for(size_t i = 0; i < dimSize-1; i++) {
        ptr[i] = subData[i];
    }

    struct MatrixData m = {dimSize-1, ptr};
    return m;
}

template <typename T>
std::vector<T> Matrix<T>::getUpStringCoef(struct Matrix<T>::MatrixData m) {
    std::vector<T> coefs;
    for(size_t i = 0; i < m._dimSize; i++) {
        struct Matrix<T>::MatrixData subM = createSubMatrix(i, m._dimSize);
        coefs.push_back(this->calcD(subM));
    }
    return coefs;
}

