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

double Vector3D::Dot (const Vector3D &vec) const{
    double x = this->m_x * vec.m_x;
    double y = this->m_y * vec.m_y;
    double z = this->m_z * vec.m_z;

    return x + y + z;
}

Vector3D Vector3D::Cross (const Vector3D &vec) const {
    double x = this->m_y * vec.m_z - this->m_z * vec.m_y;
    double y = this->m_z * vec.m_x - this->m_x * vec.m_z;
    double z = this->m_x * vec.m_y - this->m_y * vec.m_x;

    return Vector3D(x,y,z);
}


std::ostream& operator<< (std::ostream& os, const Vector3D &vec){
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

Vector3D operator*(const double&  alpha, const Vector3D& vec) {
    return Vector3D(alpha * vec.Get_X(),alpha * vec.Get_Y(), alpha * vec.Get_Z());
}
                                                                              
Vector3D operator*(const Vector3D& vec, const double& alpha) {
    return Vector3D(alpha * vec.Get_X(),alpha * vec.Get_Y(), alpha * vec.Get_Z());
}