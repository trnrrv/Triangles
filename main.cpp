#include <iostream>
#include <vector>
#include "triangle.h"

#define MAX_TRIANG_NUM 1000000
#define MIN_TRIANG_NUM 0

int main(void) {
    size_t N = 0;
    int inBuf = 0;
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


}