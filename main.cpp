#include <iostream>
#include <vector>
#include <algorithm>
#include "geom.h"
#include "Matrix.hpp"

#define MAX_TRIANG_NUM 1000000
#define MIN_TRIANG_NUM 0

int main(void) {
    size_t N = 0;
    /*std::cin >> N;
    if((N < MIN_TRIANG_NUM) || 
       (N > MAX_TRIANG_NUM)) {
        std::cout << "Incorrect N";
        return 1;
    }

    std::vector<Triangle3D<int>> triangs;
    Triangle3D<int> trBuf(0, 0, 0, 0);

    for(size_t i = 0; i < N; i++) {
        std::cin >> trBuf.X;
        std::cin >> trBuf.Y;
        std::cin >> trBuf.Z;
        std::cin >> trBuf.R;
        triangs.emplace_back(trBuf);
    }*/

    int matrixData[3][3] = {{0, 1, 6}, 
                            {2, 3, 7},
                            {5, 10, 11}};
    int** ptr = new int*[3];
    ptr[0] = matrixData[0];
    ptr[1] = matrixData[1];
    ptr[2] = matrixData[2];

    Matrix<int> m(3, ptr);
    std::cout << m.calcD(m.mFull) << std::endl;
    std::vector<int> x = m.getUpStringCoef(m.mFull);
    for(auto& i: x)
        std::cout << i << ' ' << std::endl;

    Triangle3D<int> t1({0, 1, 6}, {2, 3, 7}, {4, 5, 7}, {1, 3, 9}); 
    Triangle3D<int> t2({3, 4, 5}, {5, 3, 8}, {6, 32, 4}, {1, 2, 2}); 

    t1.isTrianglesIntersect(t2);

    //auto print = [](const int& n) { std::cout << n << ' '; };
    //std::for_each(t1.X.X, t1.X.Z, print);
    std::cout << t1.X.Y << std::endl;

}