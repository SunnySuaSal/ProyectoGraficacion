#include "../include/Model.h"

Model::Model()
{
    this->name = "";
    this->vertices = {};
    this->faces = {};
    this->transform = { {1.0, 0.0, 0.0, 0.0}, 
                        {0.0, 1.0, 0.0, 0.0},
                        {0.0, 0.0, 1.0, 0.0},
                        {0.0, 0.0, 0.0, 1.0}};
    this->r = 1.0;
    this->g = 1.0;
    this->b = 1.0;
}

Model::Model(string file)
{
    this->name = "";
    this->vertices = {};
    this->faces = {};
    this->transform = { {1.0, 0.0, 0.0, 0.0}, 
                        {0.0, 1.0, 0.0, 0.0},
                        {0.0, 0.0, 1.0, 0.0},
                        {0.0, 0.0, 0.0, 1.0}};
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
            arma::Mat<float> v_transformed = this->transform * v.homogeneous();
            vertex_data.push_back(v_transformed.at(0,0));
            vertex_data.push_back(v_transformed.at(1,0));
            vertex_data.push_back(v_transformed.at(2,0));
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
            color_data.push_back(this->r);
            color_data.push_back(this->g);
            color_data.push_back(this->b);
        }
    }
    return (color_data);
}

void Model::set_transform(arma::Mat<float> new_transf){
    this->transform = new_transf;
}

void Model::set_color(float r, float g, float b){
    this->r = r;
    this->g = g;
    this->b = b;
}

void Model::calculate_normals(){
    for(Face f : this->faces){
        vector<unsigned int> vert = f.get_vertices();
        Vertex v1 = this->get_vertex(vert[0]);
        Vertex v2 = this->get_vertex(vert[1]);
        Vertex v3 = this->get_vertex(vert[2]);
        f.calculate_normal(v1, v2, v3);
    }
}