#ifndef FACE_H
#define FACE_H

#pragma once

#include "vector"
#include "Vertex.h"

using namespace std;

class Face
{
public:
    Face(vector<unsigned int> vertices);
    void print(vector<Vertex> vert);
    vector<unsigned int> get_vertices();
private:
    vector<unsigned int> vertices;
};

#endif