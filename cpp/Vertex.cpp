#include "../include/Vertex.h"
#include <iostream>


Vertex::Vertex(float x, float y, float z)
{
    this-> x = x;
    this-> y = y;
    this-> z = z;
}

void Vertex::print(){
    cout << "(" <<  this->x << ", " << this->y
    << ", " << this->z << ")";
}

float Vertex::get_x(){
    return(this->x);
}

float Vertex::get_y(){
    return(this->y);
}

float Vertex::get_z(){
    return(this->z);
}

Vertex Vertex::operator+(Vertex op2){
    Vertex p(this->x+op2.x, this->y+op2.y, this->z+op2.z);
    return(p);
}