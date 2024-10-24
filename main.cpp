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
   Vertex v1(3.0, 4.5, 1.2);
   Vertex v2(6.4, 7.1, 2.2);

   //Paso 1 - Trasladar los puntos al origen
   arma::Mat<float> v1p = an.traslation(-v1.get_x(), -v1.get_y(), -v1.get_z()) * v1.homogeneous();
   arma::Mat<float> v2p = an.traslation(-v1.get_x(), -v1.get_y(), -v1.get_z()) * v2.homogeneous();

    //Paso 2 - Rotar el punto v2p al eje x
    arma::Mat<float> v1pp = an.rotation_y(16.39) * v1p;
    arma::Mat<float> v2pp = an.rotation_y(16.39) * v2p;

    //Paso 3 - Rotar el punto v2pp al eje z
    arma::Mat<float> v1ppp = an.rotation_z(-36.26) * v1pp;
    arma::Mat<float> v2ppp = an.rotation_z(-36.26) * v2pp;

    cout<<v1ppp<<endl;
    cout<<v2ppp<<endl;

    //Verificamos que se obtiene lo mismo que con la matriz de rotacion compuesta
    arma::Mat<float> TC = an.rotation_z(-36.26) * an.rotation_y(16.39) * an.traslation(-v1.get_x(), -v1.get_y(), -v1.get_z());
    arma::Mat<float> v1r = TC * v1.homogeneous();

    cout<<v1r<<endl;

    return 0;
}
