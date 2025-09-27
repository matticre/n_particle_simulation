#pragma once

#include "Vector3D.h"

class Particle{
    public:
        // Default constructor: each attribute is null
        Particle() : 
            m_position(Vector3D()), 
            m_velocity(Vector3D()), 
            m_acceleration(Vector3D()),
            m_mass(0.0f), 
            m_radius(0.0f) {};
        
        // Constructor starting from two Vector3D (position and velocity) and one double (mass)
        Particle(Vector3D &position, Vector3D &velocity, double mass, double radius) : 
            m_position(position), 
            m_velocity(velocity), 
            m_acceleration(Vector3D()), 
            m_mass(mass), 
            m_radius(radius) {};
        
        // Constructor starting from three doubles for position, three doubles for velocity
        // one double for mass
        Particle(double x, double y, double z, double vx, double vy, double vz, double mass, double radius) : 
            m_position(Vector3D(x,y,z)), 
            m_velocity(Vector3D(vx,vy,vz)), 
            m_acceleration(Vector3D()),  
            m_mass(mass), 
            m_radius(radius) {};

        // Mass getter
        double GetMass(){ return m_mass;};
        
        // Mass setter
        void SetMass(double mass){m_mass = mass;};

        // Radius getter
        double GetRadius(){ return m_radius;};
        
        // Radius setter
        void SetRadius(double &radius){m_radius = radius;};

        // Position getter
        const Vector3D& GetPosition() const{ return m_position;};
        
        // Position setter
        void SetPosition(const Vector3D &position){m_position = position;};

        // Velocity getter
        const Vector3D& GetVelocity() const { return m_velocity;};
        
        // Velocity setter
        void SetVelocity(const Vector3D &velocity){m_velocity = velocity;};

        // Acceleration getter
        const Vector3D& GetAcceleration() const { return m_acceleration;};
        
        // Acceleration setter
        void SetAcceleration(const Vector3D &acceleration){m_acceleration = acceleration;};


        friend std::ostream& operator<<(std::ostream &os, const Particle &particle);

    private:
        Vector3D m_position;
        Vector3D m_velocity;
        Vector3D m_acceleration;
        double    m_mass;
        double    m_radius;
};