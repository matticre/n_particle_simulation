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

    size_t nParticles = particles.size();

    std::vector<Vector3D> finalAccelerations(nParticles, Vector3D());
    
    #pragma omp parallel default(none) shared(particles, finalAccelerations, nParticles)
    {
        std::vector<Vector3D> privateAccBuffer(nParticles, Vector3D());

        #pragma omp for
        for (size_t i = 0; i < nParticles; ++i){
            for (size_t j = i + 1; j < nParticles; ++j){

                double mass_i = particles[i].GetMass(); 
                double mass_j = particles[j].GetMass();
                
                auto pos_i    = particles[i].GetPosition();
                auto pos_j    = particles[j].GetPosition();
                auto dis      = (pos_j - pos_i);
                double r      = dis.GetMag();
            
                auto force   = mass_i * mass_j * dis * (1 / pow(r + REG, 3));

                privateAccBuffer[i] += (1.0 / mass_i) * force;
                privateAccBuffer[j] -= (1.0 / mass_j) * force;
            }
        }
    
        #pragma omp critical
        for (size_t i = 0; i < nParticles; ++i){
            finalAccelerations[i] += privateAccBuffer[i];
        }    
       
    } 

    for (size_t i = 0; i < nParticles; ++i) {
        particles[i].SetAcceleration(finalAccelerations[i]);
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
