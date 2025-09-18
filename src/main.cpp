#include "Vector3D.h"
#include <iostream>

int main (){
    Vector3D vec1(1,2,3);
    Vector3D vec2(4,5,6);

    std::cout << vec1 << std::endl
              << vec1 + vec2 << std::endl
              << vec1 - vec2 << std::endl;

    return 0;
}
