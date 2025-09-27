#pragma once

#include "Vector3D.h"
#include "Particle.h"
#include "Constants.h"
#include <vector>
#include <omp.h>

class OdeSolver{
    
    public:
        void UpdatePosition(std::vector<Particle> &particles);

        std::vector<Vector3D> GetAccelerations(std::vector<Particle> &particles);

        void UpdateForce(std::vector<Particle> &particles);

        void UpdateVelocity(std::vector<Particle> &particles, std::vector<Vector3D> &accelerations);

        void EvolveSystem(std::vector<Particle> &particles);
};