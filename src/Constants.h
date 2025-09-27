#pragma once

#include <cmath>


constexpr double dt  = 0.001; 
constexpr double G   = 1;
constexpr double REG = 0.1;

constexpr double SUN_RADIUS_AU     = 0.0;
constexpr double MERCURY_RADIUS_AU = 0.005;
constexpr double VENUS_RADIUS_AU   = 0.5;
constexpr double EARTH_RADIUS_AU   = 0.75;
constexpr double MARS_RADIUS_AU    = 1.;

constexpr int WINDOW_WIDTH  = 1920;
constexpr int WINDOW_HEIGHT = 1080;
constexpr int X_CENTER      = WINDOW_WIDTH / 2;
constexpr int Y_CENTER      = WINDOW_HEIGHT / 2;
constexpr int SCALE_FACTOR  = 400;

constexpr double SUNMASS     = 10;
constexpr double MERCURYMASS = 10e-4;
constexpr double VENUSMASS   = 10e-4;
constexpr double EARTHMASS   = 10e-4;
constexpr double MARSMASS    = 10e-4;

inline double GetSpeed(double r){
    return sqrt(G * SUNMASS / r);
}

const double MERCURY_SPEED = 0.9 * GetSpeed(MERCURY_RADIUS_AU) ;
const double VENUS_SPEED   = 0.9 * GetSpeed(VENUS_RADIUS_AU) ;
const double EARTH_SPEED   = 0.9 * GetSpeed(EARTH_RADIUS_AU) ;
const double MARS_SPEED    = 0.9 * GetSpeed(MARS_RADIUS_AU) ;