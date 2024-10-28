#ifndef ANIMATION_H
#define ANIMATION_H

#pragma once

using namespace std;

#include <iostream>
#include <vector>
#include <cmath>
#include <armadillo>
//#include <numbers>
#include "Vertex.h"

#define PI 3.141592

class Animation
{
public:
    Animation();
    vector<Vertex> pline(Vertex P1, Vertex P2, float dt);
    vector<Vertex> bezier(Vertex P1, Vertex P2, Vertex P3, Vertex P4, float dt);
    vector<Vertex> hermite(Vertex P1, Vertex P4, Vertex R1, Vertex R4, float dt);
    arma::Mat<float> traslation(float dx, float dy, float dz);
    arma::Mat<float> scaling(float sx, float sy, float sz);
    arma::Mat<float> rotation_x(float theta);
    arma::Mat<float> rotation_y(float theta);
    arma::Mat<float> rotation_z(float theta);
    arma::Mat<float> rotationP1P2(Vertex P1, Vertex P2, float theta);
private:

};

#endif