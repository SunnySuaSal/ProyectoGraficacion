#ifndef OBJ_H
#define OBJ_H

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Vertex.h"
#include "Face.h"

using namespace std;

class Obj{
public:
    Obj(string file);
    void print_faces();
private:
    string name;
    vector<Vertex> vertices;
    vector<Face> faces;
    vector<string> split(const string& str, const string& delim);
};

#endif