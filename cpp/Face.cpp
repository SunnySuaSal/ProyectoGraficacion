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