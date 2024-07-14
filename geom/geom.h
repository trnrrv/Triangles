#pragma once
#include <stddef.h>

template <typename T> 
class Point {
    public:
        T X, Y, Z;
        Point(T x = 0, T y = 0, T z = 0, T r = 0) {
            X = x;
            Y = y;
            Z = z;
        }
        ~Point() {

        }        
};

template <typename T> 
class Plane {
    private:
        Point<T> X, Y, Z;
    public:
        double A, B, C;
        Plane(Point<T> x = {0, 0, 0}, Point<T> y = {0, 0, 0}, Point<T> z = {0, 0, 0}) {
            X = x;
            Y = y;
            Z = z;
            //A = 
        }

        ~Plane() {

        }

        void isPlanesIntersect(Plane p1, Plane p2);
};


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