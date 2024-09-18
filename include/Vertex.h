#ifndef VERTEX_H
#define VERTEX_H

#pragma once

using namespace std;

class Vertex
{
public:
    Vertex(float x, float y, float z);
    void print();
    float get_x();
    float get_y();
    float get_z();
private:
    float x, y, z;
};

#endif