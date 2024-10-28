#ifndef CANNON_H
#define CANNON_H

#pragma once

#include "Object.h"

class Cannon
{
public:
    Cannon();
    void shoot();
private:
    Object<Obj> cbody;
    Object<Ply> cwheel;
    Object<Stl> bullet;
    Vertex initial_position;
    Vertex bullet_position;
    float angle;
    float force;
};

#endif