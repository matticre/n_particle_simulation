#include "Vector3D.h"
#include "Particle.h"
#include "Constants.h"
#include "OdeSolver.h"

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <thread>
#include <numeric>
#include <random>

void InitializeParticles(std::vector<Particle> &particles){
    
    std::random_device rd;
    std::mt19937 gen(rd()); 

    std::uniform_real_distribution<> pos_dist(-5.0, 5.0);
    std::uniform_real_distribution<> vel_dist(-0.5, 0.5); 
    std::uniform_real_distribution<> mass_dist(0.1, 0.5); 
    
    const double PARTICLE_RADIUS = 5.0; 
    const int NUM_PARTICLES = 1000;

    for (size_t i = 0; i < NUM_PARTICLES; ++i){
        
        if (i == 0) {
            Particle part(0, 0, 0, 0, 0, 0, SUNMASS, 30.0);
            particles.push_back(part);
        } else {
            double x = pos_dist(gen);
            double y = pos_dist(gen);
            double z = pos_dist(gen);

            double vx = vel_dist(gen);
            double vy = vel_dist(gen);
            double vz = vel_dist(gen);
            
            double mass = mass_dist(gen);

            Particle part(x, y, z, vx, vy, vz, mass, PARTICLE_RADIUS);
            particles.push_back(part);
        }
    }
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

int main (){

    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "N-particle simulation");
    window.setFramerateLimit(30);

    std::vector<Particle> particles;
    InitializeParticles(particles);
    OdeSolver solveSystem;

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

        solveSystem.EvolveSystem(particles);


        window.clear(sf::Color::Black);
        DrawParticles(particles, window);
        window.display();
        
    }

    return 0;
}
