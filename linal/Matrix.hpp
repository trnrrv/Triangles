#pragma once
#include <stddef.h>
#include <stdexcept>
#define MAX_TABLE_SIZE 10


template <typename T> 
class Matrix {
private:
    struct MatrixData {
        size_t _dimSize;
        T** _data;
    };
    struct MatrixData createSubMatrix(size_t pivot_col, size_t pivot_str, size_t dimSize);
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
};

template <typename T> 
T Matrix<T>::calcD(struct Matrix<T>::MatrixData m) {
    T cumulSum = 0;

    //Base case
    if(m._dimSize == 2) {
        return m._data[0][0]*m._data[1][1] - m._data[0][1]*m._data[1][0];
    } else {
        for(size_t i = 0; i < m._dimSize; i++) {
            struct Matrix<T>::MatrixData subM = createSubMatrix(i, 0, m._dimSize - 1);
            cumulSum += calcD(subM);
        }
    } 
    return cumulSum;
}

template <typename T>
struct Matrix<T>::MatrixData Matrix<T>::createSubMatrix(size_t pivot_col, size_t pivot_str,
                                            size_t dimSize) {
    T subData[dimSize-1][dimSize-1];                        
    for(size_t i = 0; i < dimSize - 1; i ++) {
        for(size_t j = 0; j < dimSize - 1; j ++) {
            if((i != pivot_col) || (j != pivot_str))
                subData[i][j] = mFull._data[i][j];
        }
    }   

    T** ptr = new T*[dimSize-1];
    for(size_t i = 0; i < dimSize-1; i++) {
        ptr[i] = subData[i];
    }

    struct MatrixData m = {dimSize-1, ptr};
    return m;
}

