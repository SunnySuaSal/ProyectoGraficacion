#ifndef MODEL_H
#define MODEL_H

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Vertex.h"
#include "Face.h"

using namespace std;

class Model
{
public:
    Model();
    Model(string file);
    void print_faces();
    vector<Face> get_faces();
    virtual void load_model(string file) = 0;
protected:
    string name;
    vector<Vertex> vertices;
    vector<Face> faces;
    vector<string> split(const string& str, const string& delim);
    virtual void load(string file) = 0;
};

#endif