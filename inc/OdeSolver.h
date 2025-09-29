/**
 * Core class of the simulation project. The goal of this class is to solve
 * the system dynamics using Verlet velocity algorithm
 */
#pragma once

#include "Vector3D.h"
#include "Particle.h"
#include "Constants.h"
#include <vector>
#include <omp.h>

class OdeSolver{
    
    public:
        // Updating particle position at timestep t+1
        void UpdatePosition(std::vector<Particle> &particles);

        // Accelerations getter. Needed to get the acceleration at time t. 
        std::vector<Vector3D> GetAccelerations(std::vector<Particle> &particles);

        // Calculating forces and acceleration. The acceleration comes from the calculation of gravitational force
        // In this method multithreaded programming is used. Each thread performs the calculation of the acceleration saving 
        // the obtained information in its own buffer. Then all the vectors of accelerations are merged in order to assign the 
        // correct value to simulated particles.
        void UpdateForce(std::vector<Particle> &particles);

        // Updating particle velocity at timestep t+1 using acceleration at timestep t and t+1
        void UpdateVelocity(std::vector<Particle> &particles, std::vector<Vector3D> &accelerations);

        // Evolve the particle system by solving the equation of motion through Verlet Velocity
        void EvolveSystem(std::vector<Particle> &particles);
};