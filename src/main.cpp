#include "Vector3D.h"
#include "Particle.h"
#include "Constants.h"

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <thread>
#include <numeric>

void InitializeParticles(std::vector<Particle> &particles){
    Particle Sun(0, 0, 0, 0, 0, 0, SUNMASS, 30.0);
    Particle Mercury(MERCURY_RADIUS_AU, 0, 0, 0, MERCURY_SPEED, 0, MERCURYMASS, 10.0);
    Particle Venus(VENUS_RADIUS_AU, 0, 0, 0, VENUS_SPEED, 0, VENUSMASS, 10.0);
    Particle Earth(EARTH_RADIUS_AU, 0, 0, 0, EARTH_SPEED, 0, EARTHMASS, 10.0);
    Particle Mars(MARS_RADIUS_AU, 0, 0, 0, MARS_SPEED, 0,  MARSMASS, 10.0);

    particles.push_back(Sun);
    particles.push_back(Mercury);
    particles.push_back(Venus);
    particles.push_back(Earth);
    particles.push_back(Mars);
}

// @brief Draw particles on window
void DrawParticles(std::vector<Particle> &particles, sf::RenderWindow &window){
    for (auto& particle : particles){
        sf::CircleShape shape(static_cast<float>(particle.GetRadius()));
        shape.setFillColor(sf::Color::White);
        shape.setPosition(static_cast<float>(X_CENTER + SCALE_FACTOR * particle.GetPosition().Get_X() - particle.GetRadius()), 
                          static_cast<float>(Y_CENTER + SCALE_FACTOR * particle.GetPosition().Get_Y() - particle.GetRadius()));

        window.draw(shape);
    }
}

void UpdatePosition(std::vector<Particle> &particles){
    for (auto &particle : particles){
        auto pos_vec = particle.GetPosition();
        pos_vec += particle.GetVelocity() * dt + 0.5 * particle.GetAcceleration() * dt * dt;
        particle.SetPosition(pos_vec); 
    }
}

std::vector<Vector3D> GetAccelerations(std::vector<Particle> &particles){
    std::vector<Vector3D> oldAccelerations;
    
    for (auto &particle : particles)
        oldAccelerations.push_back(particle.GetAcceleration());

    return oldAccelerations;
}

void UpdateForce(std::vector<Particle> &particles){

    for (size_t i = 0; i < particles.size(); ++i) {
        particles[i].SetAcceleration(Vector3D(0,0,0));
    }

    for (size_t i = 0; i < particles.size(); ++i){
        for (size_t j = i + 1; j < particles.size(); ++j){

            double mass_i = particles[i].GetMass(); 
            double mass_j = particles[j].GetMass();
            
            auto pos_i   = particles[i].GetPosition();
            auto pos_j   = particles[j].GetPosition();
            auto dis     = (pos_j - pos_i);
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

void UpdateVelocity(std::vector<Particle> &particles, std::vector<Vector3D> &accelerations){
    for (size_t i = 0; i < particles.size(); ++i){
        auto vel_vec = particles[i].GetVelocity();
        vel_vec +=  0.5 * (particles[i].GetAcceleration() + accelerations[i]) * dt;
        particles[i].SetVelocity(vel_vec); 
    }
}

// @brief Evolve the particle system by solving the equation of motion through Verlet Velocity
void EvolveSystem(std::vector<Particle> &particles){
    // Update position
    UpdatePosition(particles);

    // Get acceleration
    auto oldAccelerations = GetAccelerations(particles);

    // Update forces
    UpdateForce(particles);
    
    // Update velocity
    UpdateVelocity(particles, oldAccelerations);
}


int main (){

    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "N-particle simulation");
    window.setFramerateLimit(30);

    std::vector<Particle> particles;
    InitializeParticles(particles);

    while(window.isOpen()){
        sf::Event event;

        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed){
                if (event.key.code == sf::Keyboard::Escape)
                    window.close();
            }
        }

        EvolveSystem(particles);


        window.clear(sf::Color::Black);
        DrawParticles(particles, window);
        window.display();
        
    }

    return 0;
}
