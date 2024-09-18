#include "../include/Face.h"
#include <iostream>

Face::Face(vector<Vertex> vertices)
{
    this->vertices = vertices;
}

void Face::print(){
    int end = vertices.size();
    for(Vertex vert : this->vertices){
        vert.print();
        end--;
        if(end > 0)
            cout << " -> ";
    }
    cout << endl;
}