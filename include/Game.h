#ifndef CANNON_H
#define CANNON_H

#pragma once

#include "Object.h"
#include "Triangle.h"

class Game
{
public:
    Game();
    void shoot();
    void draw();
    void move(float angle);
    void reset();
private:
    Object<Obj> duck;
    Object<Ply> piggy;
    Object<Stl> slingshot;
    Vertex initial_position;
    Vertex bullet_position;
    float angle;
    float force;
    vector<Vertex> duck_trajectory;
    bool shooted;
    unsigned int ind_trajectory;
};

#endif