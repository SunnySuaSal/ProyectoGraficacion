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

private:
    vector<Vertex> vertices;
};

#endif