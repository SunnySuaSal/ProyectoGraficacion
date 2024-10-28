#ifndef CANNON_H
#define CANNON_H

#pragma once

#include "Object.h"

class Cannon
{
public:
    Cannon();
private:
    Object<Obj> cbody;
    Object<Ply> cwheel;
    Object<Stl> bullet;

};

#endif