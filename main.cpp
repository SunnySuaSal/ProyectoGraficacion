#include <iostream>
#include "include/Ply.h"

using namespace std;

int main(){
    cout << "Cargando..." << endl;

        //ply
        Ply cube1("models/cube1.ply");
        cube1.print_faces();
        Ply cube2("models/cube2.ply");

    cout << "¡Listo!" << endl;
}