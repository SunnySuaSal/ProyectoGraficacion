#ifndef OBJECT_H
#define OBJECT_H

#pragma once

#include "Obj.h"
#include "Ply.h"

template <class T>
class Object: public T
{
public:
    Object(string file): T(file) {};
};

#endif