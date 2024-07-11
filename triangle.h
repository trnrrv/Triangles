#pragma once

template <typename T> 
class Triangle3D {
    public:
        size_t fieldsNum;
        T X, Y, Z, R;
        Triangle3D(T x = 0, T y = 0, T z = 0, T r = 0) {
            fieldsNum = 3;
            X = x;
            Y = y;
            Z = z;
            R = r;
        }
        ~Triangle3D() {

        }        
};