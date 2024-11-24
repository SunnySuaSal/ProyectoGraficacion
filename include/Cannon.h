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
private:
    Object<Obj> cbody;
    Object<Ply> cwheel;
    Object<Stl> bullet;
    Vertex initial_position;
    Vertex bullet_position;
    float angle;
    float force;
    vector<Vertex> bullet_trajectory;
};

#endif