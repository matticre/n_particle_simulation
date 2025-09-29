/**
 * In this header file I grouped all the simulation constants
 */

#pragma once

#include <cmath>

constexpr double dt       = 0.001; // Time step of the ode solver 
constexpr double G        = 1;     // For the sake of semplicity I put G=1, sorry to the physics community
constexpr double REG      = 0.1;   // This is a regularization parameter, 
                                   // it avoid divergences when calculating the force
constexpr double MAINMASS = 10;    // Mass of the main particle located at the center

// Graphical paramete
constexpr int WINDOW_WIDTH  = 1920;
constexpr int WINDOW_HEIGHT = 1080;
constexpr int X_CENTER      = WINDOW_WIDTH / 2;
constexpr int Y_CENTER      = WINDOW_HEIGHT / 2;
constexpr int SCALE_FACTOR  = 400;
