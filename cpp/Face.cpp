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

void Face::poligName(vector<Vertex> vert){
    int tam = vert.size();
    if(tam >= 9)
        cout << "Ngon" << endl;
    switch (tam)
    {
    case 3:
        cout << "Triángulo" << endl;
        break;
    case 4:
        cout << "Cuadrilátero" << endl;
        break;
    case 5:
        cout << "Pentágono" << endl;
        break;
    case 6:
        cout << "Hexágono" << endl;
        break;
    case 7:
        cout << "Heptágono" << endl;
        break;
    case 8:
        cout << "Octógono" << endl;
        break;
    default:
        cout << "Error, no menos de 3 lados" << endl;
        break;
    }
}