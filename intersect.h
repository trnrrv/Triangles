#pragma once

#include "triangle.h"

template <typename T> 
class Plane {
    private:
    public:
        T X, Y, Z;
        Plane(T x = 0, T y = 0, T z = 0) {
            X = x;
            Y = y;
            Z = z;
        }

        ~Plane() {

        }

        void checkIntersect(Plane p1, Plane p2);
};