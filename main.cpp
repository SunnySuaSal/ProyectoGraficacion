#include <iostream>
#include "include/Object.h"

using namespace std;

int main(){
    cout << "Cargando..." << endl;

        /*
        Object<Obj> cube1("models/cube1.obj");
        cube1.print_faces();
        cout << "Cambio" << endl;
        Object<Ply> cube2("models/cube2.ply");
        cube2.print_faces();
        cout << "Cambio" << endl;
        Object<Stl> cube3("models/cube1.stl");
        cube3.print_faces();
        cout << "¡Listo!" << endl;
        */
       Vertex P1(2, -3, 0);
       Vertex P2(-5, 6, 4);
       float dt = 0.2;

       //P = P1 + t(P2 - P1)
       for(float t=0.0; t<=1.0; t=t+dt){
        Vertex P = P1 + P2;
        /*
        float x = P1.get_x() + (t * (P2.get_x() - P1.get_x()));
        float y = P1.get_y() + (t * (P2.get_y() - P1.get_y()));
        float z = P1.get_z() + (t * (P2.get_z() - P1.get_z()));
        */
        cout << "t = " << t << endl;
        //cout << "(" << x << ", " << y << ", " << z << ")" << endl;
       }
}