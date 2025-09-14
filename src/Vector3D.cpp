#include "Vector3D.h"

Vector3D& Vector3D::operator+=(const Vector3D &vec) {
    m_x += vec.m_x;
    m_y += vec.m_y;
    m_z += vec.m_z;

    return *this;
}
