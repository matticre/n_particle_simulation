#pragma once

#include <cmath>
#include <iostream>

class Vector3D {

public:
    // Default constructor: intialize each component to 0
    Vector3D() : m_x(0), m_y(0), m_z(0) {};

    // Constructor: initialize each component with given value
    Vector3D(float x, float y, float z) : m_x(x), m_y(y), m_z(z) {};

    // Setters
    void Set_X(float x) { m_x = x; };
    void Set_Y(float y) { m_y = y; };
    void Set_Z(float z) { m_z = z; };
    
    // Getters
    float Get_X() const { return m_x; };
    float Get_Y() const { return m_y; };
    float Get_Z() const { return m_z; };

    // @brief Vector magnitude
    // @return Return the magnitude of the vector
    float GetMag() { return sqrtf(m_x*m_x + m_y*m_y + m_z*m_z); };

    // @brief Dot product
    // @return Return the dot product of two vectors
    float Dot(Vector3D &vec);

    // @brief Vector product
    // @return Return the vector product of two vectors
    Vector3D VecProd(Vector3D &vec);


    // Operator overloading
    Vector3D& operator+=(const Vector3D& vec);
    Vector3D& operator-=(const Vector3D& vec);
    friend std::ostream& operator<< (std::ostream& os, const Vector3D &vec);
    
private:
    // Vector components
    float m_x;
    float m_y;
    float m_z;
    
};

// Operator overloading
Vector3D operator+(const Vector3D& vec1, const Vector3D& vec2);
Vector3D operator-(const Vector3D& vec1, const Vector3D& vec2);
Vector3D operator*(const float&  alpha, const Vector3D& vec);
Vector3D operator*(const double& alpha, const Vector3D& vec);
