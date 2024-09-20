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
    void poligName(vector<Vertex> vert);
private:
    vector<unsigned int> vertices;
};

#endif