#ifndef VERTEX_H
#define VERTEX_H

#pragma once

using namespace std;

class Vertex
{
public:
    Vertex(float x, float y, float z);
    void print();
private:
    float x, y, z;
};

#endif