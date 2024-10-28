#ifndef VERTEX_H
#define VERTEX_H

#pragma once

#include <armadillo>

using namespace std;

class Vertex
{
public:
    Vertex();
    Vertex(float x, float y, float z);
    void print();
    float get_x();
    float get_y();
    float get_z();
    void set_x(float x);
    void set_y(float x);
    void set_z(float x);
    Vertex operator+(Vertex op2);
    Vertex operator-(Vertex op2);
    Vertex operator*(float op2);
    arma::Col<float> homogeneous();
private:
    float x, y, z;
};

#endif