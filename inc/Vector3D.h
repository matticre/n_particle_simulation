#include <cmath>

class Vector3D {

    public:
        Vector3D() : m_x(0), m_y(0), m_z(0) {};
        Vector3D(float x, float y, float z) : m_x(x), m_y(y), m_z(z) {};

        void Set_X(float x) { m_x = x; };
        void Set_Y(float y) { m_y = y; };
        void Set_Z(float z) { m_z = z; };

        float Get_X() { return m_x; };
        float Get_Y() { return m_y; };
        float Get_Z() { return m_z; };

        float GetMag() { return sqrtf(m_x*m_x + m_y*m_y + m_z*m_z); };

        Vector3D& operator+=(const Vector3D &vec);

    private:
        float m_x;
        float m_y;
        float m_z;

};
