#pragma once
#include <stddef.h>
#include <stdexcept>

template <typename T> 
class Point {
    public:
        T X, Y, Z;
        Point(T x = 0, T y = 0, T z = 0) {
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
        }

        ~Plane() {

        }

        
};


template <typename T> 
class Triangle3D {
    private:
        Point<T> getCoordByNum(unsigned char num);
    public:
        Point<T> X, Y, Z, R;
        size_t points;
        Triangle3D(Point<T> x = 0, Point<T> y = 0, Point<T> z = 0, Point<T> r = 0) {
            X = x;
            Y = y;
            Z = z;
            R = r;
            points = 4;
        }
        ~Triangle3D() {

        }    

    bool isTrianglesIntersect(Triangle3D p2);    
};

template <typename T> 
Point<T> Triangle3D<T>::getCoordByNum(unsigned char num) {
    switch(num) {
        case 0:
            return this->X;
        case 1:
            return this->Y;
        case 2:
            return this->Z;
        case 3:
            return this->R;
        default:
            throw std::invalid_argument("Incorrect number of coordinate!");
            return {0, 0, 0};
    }
}

template <typename T>
bool Triangle3D<T>::isTrianglesIntersect(Triangle3D<T> t2) {
    Plane<T> p1;
    Plane<T> p2;

    //Cpmbimatorics
    for(size_t i = 0; i < t2.points; i++) {
        //t1.getCoordByNum(0)
    }
    return false;
}