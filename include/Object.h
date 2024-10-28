#ifndef OBJECT_H
#define OBJECT_H

#pragma once

#include "Obj.h"
#include "Ply.h"
#include "Stl.h"

template <class T>
class Object: public T
{
public:
    Object(): T() {};
    Object(string file): T(file) {};
    vector<Vertex> get_vertices(){
        return this->vertices;
    }

};

#endif