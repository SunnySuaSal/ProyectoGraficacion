#include <iostream>
#include "include/Obj.h"

using namespace std;

int main(){
    cout << "Cargando..." << endl;

        Obj cube1("models/cube1.obj");
        cube1.print_faces();
        Obj cube2("models/cube2.obj");

    cout << "¡Listo!" << endl;
}