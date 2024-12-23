#ifndef CANNON_H
#define CANNON_H

#pragma once

#include "Object.h"
#include "Triangle.h"

class Cannon
{
public:
    Cannon();
    void shoot();
    void draw();
    void move(float angle);
    void reset();
private:
    Object<Obj> cbody;
    Object<Ply> lcwheel;
    Object<Ply> rcwheel;
    Object<Stl> bullet;
    Vertex initial_position;
    Vertex bullet_position;
    float angle;
    float force;
    vector<Vertex> bullet_trajectory;
    bool shooted;
    unsigned int ind_trajectory;
};

#endif