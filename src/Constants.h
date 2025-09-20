#pragma once

#include <cmath>


constexpr double dt  = 0.001; 
constexpr double G   = 1;
constexpr double REG = 0.1;

constexpr double SUN_RADIUS_AU     = 0.0;
constexpr double MERCURY_RADIUS_AU = 0.387;
constexpr double VENUS_RADIUS_AU   = 0.723;
constexpr double EARTH_RADIUS_AU   = 1.0;
constexpr double MARS_RADIUS_AU    = 1.524;

constexpr int WINDOW_WIDTH  = 2880;
constexpr int WINDOW_HEIGHT = 1800;
constexpr int X_CENTER      = WINDOW_WIDTH / 2;
constexpr int Y_CENTER      = WINDOW_HEIGHT / 2;
constexpr int SCALE_FACTOR  = 400;

constexpr double SUNMASS     = 1.0;
constexpr double MERCURYMASS = 1.65158e-7;
constexpr double VENUSMASS   = 2.44696e-6;
constexpr double EARTHMASS   = 3.00251e-6;
constexpr double MARSMASS    = 3.21267e-7;

double GetSpeed(double r){
    return sqrt(G * SUNMASS / r);
}

const double MERCURY_SPEED = GetSpeed(MERCURY_RADIUS_AU) ;
const double VENUS_SPEED   = GetSpeed(VENUS_RADIUS_AU) ;
const double EARTH_SPEED   = GetSpeed(EARTH_RADIUS_AU) ;
const double MARS_SPEED    = GetSpeed(MARS_RADIUS_AU) ;