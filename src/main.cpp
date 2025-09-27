#include "Vector3D.h"
#include "Particle.h"
#include "Constants.h"
#include "OdeSolver.h"

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
