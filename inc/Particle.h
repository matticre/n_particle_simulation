#pragma once

#include "Vector3D.h"

class Particle{
    public:
        // Default constructor: each attribute is null
        Particle() : 
            m_position(Vector3D()), m_velocity(Vector3D()), m_mass(0.0f) {};
        
        // Constructor starting from two Vector3D (position and velocity) and one float (mass)
        Particle(Vector3D &position, Vector3D &velocity, float mass) : 
            m_position(position), m_velocity(velocity), m_mass(mass) {};
        
        // Constructor starting from three floats for position, three floats for velocity
        // one float for mass
        Particle(float x, float y, float z, float vx, float vy, float vz, float mass) : 
            m_position(Vector3D(x,y,z)), m_velocity(Vector3D(vx,vy,vz)), m_mass(mass) {};
        
        // Position getter
        Vector3D GetPosition(){ return m_position;};
        
        // Position setter
        void SetPosition(Vector3D &position){m_position = position;};

        // Velocity getter
        Vector3D GetVelocity(){ return m_velocity;};
        
        // Velocity setter
        void SetVelocity(Vector3D &velocity){m_velocity = velocity;};

        friend std::ostream& operator<<(std::ostream &os, Particle &particle);

    private:
        Vector3D m_position;
        Vector3D m_velocity;
        float    m_mass;

};