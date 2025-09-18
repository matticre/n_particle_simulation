#include "Vector3D.h"

Vector3D& Vector3D::operator+=(const Vector3D &vec) {
    m_x += vec.m_x;
    m_y += vec.m_y;
    m_z += vec.m_z;

    return *this;
}

Vector3D& Vector3D::operator-=(const Vector3D &vec) {
    m_x -= vec.m_x;
    m_y -= vec.m_y;
    m_z -= vec.m_z;

    return *this;
}

std::ostream& operator<< (std::ostream& os, Vector3D vec){
    os << "(" << vec.Get_X()
       << "," << vec.Get_Y() 
       << "," << vec.Get_Z() << ")";

    return os;
}


Vector3D operator+(const Vector3D& vec1, const Vector3D& vec2){
    Vector3D result(vec1);
    result += vec2;

    return result;
}

Vector3D operator-(const Vector3D& vec1, const Vector3D& vec2){
    Vector3D result(vec1);
    result -= vec2;

    return result;
}
