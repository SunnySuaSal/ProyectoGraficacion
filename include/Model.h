#ifndef MODEL_H
#define MODEL_H

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Vertex.h"
#include "Face.h"
#include "OpenGL.h"
#include "Animation.h"

using namespace std;

class Model
{
public:
    Model();
    Model(string file);
    void print_faces();
    vector<Face> get_faces();
    Vertex get_vertex(int ind);
    virtual void load_model(string file) = 0;
    vector <GLfloat> get_vertex_buffer_data();
    vector <GLfloat> get_vertex_color_data();
    void set_transform(arma::Mat<float> new_transf);
    void set_color(float r, float g, float b);
protected:
    string name;
    vector<Vertex> vertices;
    vector<Face> faces;
    vector<string> split(const string& str, const string& delim);
    virtual void load(string file) = 0;
    arma::Mat<float> transform;
    float r, g, b;
};

#endif