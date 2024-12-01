#include "../include/Face.h"
#include <iostream>

Face::Face(vector<unsigned int> vertices)
{
    this->vertices = vertices;
}

void Face::print(vector<Vertex> vert){
    int end = this->vertices.size();
    for(unsigned int ind_vert : this->vertices){
        vert[ind_vert].print();
        end--;
        if(end > 0)
            cout << " -> ";
    }
    cout << endl;
}

vector<unsigned int> Face::get_vertices(){
    return this->vertices;
}

void Face::calculate_normal(Vertex v1, Vertex v2, Vertex v3){
    arma::vec va = {v2.get_x() - v1.get_x(), v2.get_y() - v1.get_y(), v2.get_z() - v1.get_z()};
    arma::vec vb = {v3.get_x() - v1.get_x(), v3.get_y() - v1.get_y(), v3.get_z() - v1.get_z()};

    arma::vec vc = arma::cross(va, vb);
    this->normal = arma::normalise(vc);
}