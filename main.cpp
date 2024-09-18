#include <iostream>
#include "include/Object.h"

using namespace std;

int main(){
    cout << "Cargando..." << endl;

        //ply
        Object<Obj> cube1("models/cube1.obj");
        cube1.print_faces();
        cout << "Cambio" << endl;
        Object<Ply> cube2("models/cube2.ply");
        cube2.print_faces();
        cout << "Cambio" << endl;
        Object<Stl> cube3("models/cube1.stl");
        cube3.print_faces();

    cout << "¡Listo!" << endl;
}