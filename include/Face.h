#ifndef FACE_H
#define FACE_H

#pragma once

#include "Vertex.h"
#include "vector"

using namespace std;

class Face
{
public:
    Face(vector<Vertex> vertices);
    void print();
private:
    vector<Vertex> vertices;
};

#endif