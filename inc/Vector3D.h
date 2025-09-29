/**
 * In this class I reimplemented the 3D vector with its main algebric properties.
 */
#pragma once

#include <cmath>
#include <iostream>

class Vector3D {

public:
    // Default constructor: intialize each component to 0
    Vector3D() : m_x(0), m_y(0), m_z(0) {};

    // Constructor: initialize each component with given value
    Vector3D(double x, double y, double z) : m_x(x), m_y(y), m_z(z) {};

    // Setters
    void Set_X(double x) { m_x = x; };
    void Set_Y(double y) { m_y = y; };
    void Set_Z(double z) { m_z = z; };
    
    // Getters
    double Get_X() const { return m_x; };
    double Get_Y() const { return m_y; };
    double Get_Z() const { return m_z; };

    // @brief Vector magnitude
    // @return Return the magnitude of the vector
    double GetMag () const { return sqrt(m_x*m_x + m_y*m_y + m_z*m_z); };

    // @brief Dot product
    // @return Return the dot product of two vectors
    double Dot (const Vector3D &vec) const ;

    // @brief Vector product
    // @return Return the vector product of two vectors
    Vector3D Cross (const Vector3D &vec) const ;


    // Overloading of operator +=
    Vector3D& operator+=(const Vector3D& vec);
    
    // Overloading of operator -=
    Vector3D& operator-=(const Vector3D& vec);

    // Overloading of operator << in order to make use of std::cout 
    friend std::ostream& operator<< (std::ostream& os, const Vector3D &vec);
    
private:
    // Vector components
    double m_x;
    double m_y;
    double m_z;
    
};

// Overloading of operator +
Vector3D operator+(const Vector3D& vec1, const Vector3D& vec2);

// Overloading of operator -
Vector3D operator-(const Vector3D& vec1, const Vector3D& vec2);

// Overloading of operator * for the case scalar * vector
Vector3D operator*(const double&  alpha, const Vector3D& vec);

// Overloading of operator * for the case vector * scalar
Vector3D operator*(const Vector3D& vec, const double& alpha);
