#include "../include/Model.h"

Model::Model()
{
    this->name = "";
    this->vertices = {};
    this->faces = {};
}

Model::Model(string file)
{
    this->name = "";
    this->vertices = {};
    this->faces = {};
}

vector<string> Model::split(const string& str, const string& delim){
    vector<string> tokens;    size_t prev = 0, pos = 0;
    do    {        pos = str.find(delim, prev);
        if (pos == string::npos) pos = str.length();
        string token = str.substr(prev, pos-prev);
        if (!token.empty()) tokens.push_back(token);
        prev = pos + delim.length();
    }
    while (pos < str.length() && prev < str.length());
    return tokens;
}

void Model::print_faces(){
    for(Face f : this->faces){
        f.print(this->vertices);
    }
}

Vertex Model::get_vertex(int ind){
    return this->vertices[ind];
}

vector<Face> Model::get_faces(){
    return this->faces;
}

vector <GLfloat> Model::get_vertex_buffer_data(){
    vector <GLfloat> vertex_data = {};
    for(Face f : this->faces){
        //Por cada vertice de la cara
        for(unsigned int iv : f.get_vertices()){
            Vertex v = this->get_vertex(iv);
            vertex_data.push_back(v.get_x());
            vertex_data.push_back(v.get_y());
            vertex_data.push_back(v.get_z());
        }
    }
    return (vertex_data);
}

vector <GLfloat> Model::get_vertex_color_data(){
    vector <GLfloat> color_data = {};
    for(Face f : this->faces){
        //Por cada vertice de la cara
        for(unsigned int iv : f.get_vertices()){
            Vertex v = this->get_vertex(iv);
            color_data.push_back(1.0);
            color_data.push_back(1.0);
            color_data.push_back(1.0);
        }
    }
    return (color_data);
}
