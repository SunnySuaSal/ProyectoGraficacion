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

Vertex Vertex::operator-(Vertex op2){
    Vertex p(this->x-op2.x, this->y-op2.y, this->z-op2.z);
    return(p);
}

Vertex Vertex::operator*(float op2){
    Vertex p(this->x*op2, this->y*op2, this->z*op2);
    return(p);
}

void Vertex::printOctante(){
    if(this->x == 0 || this->y == 0 || this->z == 0)
        cout << "En el borde de octantes" << endl;
    if(this->z > 0){
        if(this->y > 0){
            if(this->x > 0){
                cout << "Octante I" << endl;
            }else{
                cout << "Octante II" << endl;
            }
        }else{
            if(this->x < 0){
                cout << "Octante III" << endl;
            }else{
                cout << "Octante IV" << endl;
            }
        }
    } else {
        if(this->y > 0){
            if(this->x > 0){
                cout << "Octante V" << endl;
            }else{
                cout << "Octante VI" << endl;
            }
        }else{
            if(this->x < 0){
                cout << "Octante VII" << endl;
            }else{
                cout << "Octante VIII" << endl;
            }
        }
    }
}