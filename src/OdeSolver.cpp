#include "OdeSolver.h"

void OdeSolver::UpdatePosition(std::vector<Particle> &particles){
    for (auto &particle : particles){
        auto pos_vec = particle.GetPosition();
        pos_vec += particle.GetVelocity() * dt + 0.5 * particle.GetAcceleration() * dt * dt;
        particle.SetPosition(pos_vec); 
    }
}

std::vector<Vector3D> OdeSolver::GetAccelerations(std::vector<Particle> &particles){
    std::vector<Vector3D> oldAccelerations;
    
    for (auto &particle : particles)
        oldAccelerations.push_back(particle.GetAcceleration());

    return oldAccelerations;
}

void OdeSolver::UpdateForce(std::vector<Particle> &particles){

    for (size_t i = 0; i < particles.size(); ++i) {
        particles[i].SetAcceleration(Vector3D(0,0,0));
    }

    for (size_t i = 0; i < particles.size(); ++i){
        for (size_t j = i + 1; j < particles.size(); ++j){

            double mass_i = particles[i].GetMass(); 
            double mass_j = particles[j].GetMass();
            
            auto pos_i    = particles[i].GetPosition();
            auto pos_j    = particles[j].GetPosition();
            auto dis      = (pos_j - pos_i);
            double r      = dis.GetMag();
         
            auto force   = mass_i * mass_j * dis * (1 / pow(r + REG, 3));

            auto acc_i = particles[i].GetAcceleration();
            auto acc_j = particles[j].GetAcceleration();

            acc_i += (1 / mass_i) * force;
            acc_j -= (1 / mass_j) * force;

            particles[i].SetAcceleration(acc_i);
            particles[j].SetAcceleration(acc_j);
        }
    }
}

void OdeSolver::UpdateVelocity(std::vector<Particle> &particles, std::vector<Vector3D> &accelerations){
    for (size_t i = 0; i < particles.size(); ++i){
        auto vel_vec = particles[i].GetVelocity();
        vel_vec +=  0.5 * (particles[i].GetAcceleration() + accelerations[i]) * dt;
        particles[i].SetVelocity(vel_vec); 
    }
}

// @brief Evolve the particle system by solving the equation of motion through Verlet Velocity
void OdeSolver::EvolveSystem(std::vector<Particle> &particles){
    // Update position
    UpdatePosition(particles);

    // Get acceleration
    auto oldAccelerations = GetAccelerations(particles);

    // Update forces
    UpdateForce(particles);
    
    // Update velocity
    UpdateVelocity(particles, oldAccelerations);
}
