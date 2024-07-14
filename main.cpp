#include <iostream>
#include <vector>
#include "geom.h"
#include "Matrix.hpp"

#define MAX_TRIANG_NUM 1000000
#define MIN_TRIANG_NUM 0

int main(void) {
    size_t N = 0;
    std::cin >> N;
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
    }

    int matrixData[2][2] = {{0, 1}, 
                            {2, 3}};
    int** ptr = new int*[2];
    ptr[0] = matrixData[0];
    ptr[1] = matrixData[1];

    Matrix<int> m(2, ptr);
    std::cout << m.calcD(m.mFull);

}