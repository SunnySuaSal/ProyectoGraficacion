#include <iostream>
#include <vector>
#include <armadillo>
#include "include/Object.h"
#include "include/Vertex.h"
#include "include/Animation.h"

using namespace std;

int main(){

    /*
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
    */

   /*
   Animation an;
   Vertex Pt(1, 0, 0);
   arma::Mat<float> Rz90 = an.rotation_z(90); //Matriz de rotacion de 90 grados en el eje z
   arma::Mat<float> Pt90 = Rz90 * Pt.homogeneous();
   arma::Mat<float> Rzn90 = an.rotation_z(-90); //Matriz de rotacion de -90 grados en el eje z
   arma::Mat<float> Ptn90 = Rzn90 * Pt.homogeneous();

   Pt.print();
   cout << endl;
   cout << Pt90 << endl;
   cout << Ptn90 << endl;
    */

   Animation an;
   Vertex P1(-23.0, 13.5, -4.4);
   Vertex P2(-12.65, -2.4, 12.67);
   Vertex P3(6.4, 7.1, 2.2);

   //Paso 1 - Trasladar P1 al origen
   arma::Mat<float> T1 = {{1, 0, 0, -P1.get_x()},
                          {0, 1, 0, -P1.get_y()},
                          {0, 0, 1, -P1.get_z()},
                          {0, 0, 0, 1}};

    //Paso 2
    float D1 = sqrt(pow(P2.get_z() - P1.get_z(), 2) + pow(P2.get_x() - P1.get_x(), 2));
    arma::Mat<float> Ry2 = {{(P2.get_z() - P1.get_z())/D1, 0, -(P2.get_x() - P1.get_x())/D1, 0},
                            {0, 1, 0, 0},
                            {(P2.get_x() - P1.get_x())/D1, 0, (P2.get_z() - P1.get_z())/D1, 0},
                            {0, 0, 0, 1}};

    //Paso 3
    float D2 = sqrt(pow(P2.get_x() - P1.get_x(), 2) + pow(P2.get_y() - P1.get_y(), 2) + pow(P2.get_z() - P1.get_z(), 2));
    arma::Mat<float> Rx3 = {{1, 0, 0, 0},
                            {0, D1/D2, -(P2.get_y() - P1.get_y())/D2, 0},
                            {0, (P2.get_y() - P1.get_y())/D2, D1/D2, 0},
                            {0, 0, 0, 1}};

    arma::Mat<float> P1p = T1.i() * Ry2.i() * Rx3.i() * Rx3 * Ry2 * T1 * P1.homogeneous();
    arma::Mat<float> P2p = T1.i() * Ry2.i() * Rx3.i() * Rx3 * Ry2 * T1 * P2.homogeneous();
    cout << P1p << endl;
    cout << P2p << endl;
    //Paso 4


    return 0;
}
