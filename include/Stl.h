#ifndef STL_H
#define STL_H

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Vertex.h"
#include "Face.h"
#include "Model.h"

using namespace std;

class Stl: public Model
{
public:
    Stl(string file);
private:
    void load(string file);
};

#endif