#ifndef ANIMATION_H
#define ANIMATION_H

#pragma once

using namespace std;

#include <iostream>
#include <vector>
#include <cmath>
#include <armadillo>
#include "Vertex.h"

class Animation
{
public:
    Animation();
    vector<Vertex> pline(Vertex P1, Vertex P2, float dt);
    vector<Vertex> bezier(Vertex P1, Vertex P2, Vertex P3, Vertex P4, float dt);
    vector<Vertex> hermite(Vertex P1, Vertex P4, Vertex R1, Vertex R4, float dt);
    arma::Mat<float> traslation(float dx, float dy, float dz);
    arma::Mat<float> scaling(float sx, float sy, float sz);
private:

};

#endif