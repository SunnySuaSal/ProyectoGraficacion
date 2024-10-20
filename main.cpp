#include <iostream>
#include <vector>
#include <armadillo>
#include "include/Object.h"
#include "include/Vertex.h"
#include "include/Animation.h"

using namespace std;

int main(){
    Object<Obj> cube("models/cube1.obj");

    //Trayectoria lineal
    Animation an;
    Vertex P1(0, 0, 0);
    Vertex P2(5, 5, 5);
    vector<Vertex> line = an.pline(P1, P2, 0.1);

    //Recorrer todos los vertices del objeto y aplicarles la traslacion
    for(Vertex point:line){
        //Recorrer todas las caras del objeto y extraer los vertices de cada cara
        for(Face face:cube.get_faces()){
            //Recorrer todos los vertices de la cara y aplicarles la traslacion
            for(unsigned int indv:face.get_vertices()){
                Vertex vertex = cube.get_vertices()[indv];
                arma::Mat<float> newPoint = an.traslation(point.get_x(), point.get_y(), point.get_z()) * vertex.homogeneous();
                cout << newPoint << endl;
            }

        }
    }

    return 0;
}