#ifndef GAME_H
#define GAME_H

#pragma once

#include "Object.h"
#include "Triangle.h"

class Game
{
public:
    Game();
    void shoot();
    void draw();
    void moveDuck(float shift);
    void moveSlingshot(float shift);
    void reset();
private:
    Object<Obj> duck;
    Object<Ply> piggy;
    Object<Stl> slingshot;
    Vertex initial_position;
    Vertex duck_position;
    float angle;
    float force;
    vector<Vertex> duck_trajectory;
    bool shooted;
    unsigned int ind_trajectory;
};

#endif