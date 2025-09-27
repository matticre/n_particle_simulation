#include "Particle.h"

std::ostream& operator<<(std::ostream &os, const Particle &particle){
    os  << "Position: " << particle.m_position << "\n"
        << "Velocity: " << particle.m_velocity << "\n"
        << "Mass:     " << particle.m_mass << std::endl;
    
        return os;
}
