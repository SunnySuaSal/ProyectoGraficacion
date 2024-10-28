#ifndef OBJ_H
#define OBJ_H

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Vertex.h"
#include "Face.h"
#include "Model.h"

using namespace std;

class Obj: public Model{
public:
    Obj();
    Obj(string file);
    void load_model(string file);
private:
    void load(string file);
};

#endif