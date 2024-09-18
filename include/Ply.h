#ifndef PLY_H
#define PLY_H

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Vertex.h"
#include "Face.h"
#include "Model.h"

using namespace std;

class Ply: public Model
{
public:
    Ply(string file);
private:
    void load(string file);
};

#endif