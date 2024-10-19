#include <iostream>
#include <cmath>
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

       /*
       Vertex P1(2, -3, 0);
       Vertex P2(-5, 6, 4);
       float dt = 0.1;

       //P = P1 + t(P2 - P1)
       for(float t=0.0; t<1.0+dt; t=t+dt){
        Vertex P = P1 + ((P2 - P1) * t);
        */

       //Curvas de Hermite
       /*
       Vertex P1(0, 0, 0);
       Vertex P4(10, 0, 0);
       Vertex R1(5, 5, 0);
       Vertex R4(-5, 5, 0);
       float dt = 0.1;

       for(float t=0.0; t<1.0+dt; t=t+dt){
            Vertex P = (P1 * (2*pow(t,3) - 3*pow(t,2) + 1)) +
                        (P4 * (-2*pow(t,3) + 3*pow(t,2)) + 
                        (R1 * (pow(t,3) - 2*pow(t,2) + t)) + 
                        (R4 * (pow(t,3) - pow(t,2))));
            cout << endl << "t = " << t << endl;
            P.print();
       }
       */

      //Curvas de Bezier
    Vertex P1(0, 10, 0);
    Vertex P2(3, 7, 2);
    Vertex P3(9, 3, 4);
    Vertex P4(8, 0, 6);
    float dt = 0.1;

    for(float t=0.0; t<1.0+dt; t=t+dt){
        Vertex P = (P1 * pow((1 - t), 3)) +
                    (P2 * (3*t*pow((1-t), 2))) + 
                    (P3 * (3*pow(t, 2) * (1 - t))) + 
                    (P4 * (pow(t,3)));
        cout << endl << "t = " << t << endl;
        P.print();
    }

       
}