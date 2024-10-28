#include "../include/Vertex.h"
#include <iostream>

Vertex::Vertex()
{

}

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

void Vertex::set_x(float x){
    this->x = x;
}

void Vertex::set_y(float x){
    this->y = y;
}

void Vertex::set_z(float x){
    this->z = z;
}

Vertex Vertex::operator+(Vertex op2){
    Vertex p(this->x+op2.x, this->y+op2.y, this->z+op2.z);
    return(p);
}

Vertex Vertex::operator-(Vertex op2){
    Vertex p(this->x-op2.x, this->y-op2.y, this->z-op2.z);
    return(p);
}

Vertex Vertex::operator*(float op2){
    Vertex p(this->x*op2, this->y*op2, this->z*op2);
    return(p);
}

arma::Col<float> Vertex::homogeneous(){
    arma::Col<float> v = {this->x, this->y, this->z, 1};
    return(v);
}
