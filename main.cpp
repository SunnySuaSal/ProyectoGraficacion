#include <iostream>
#include <vector>
#include <armadillo>
#include "include/Vertex.h"
#include "include/Animation.h"

using namespace std;

int main(){
    Animation an;
    // Vertex P1(2,-3, 0);
    // Vertex P2(-5, 6, 4);
    // vector<Vertex> line = an.pline(P1, P2, 0.1);
    // Vertex Pa(0,10, 0);
    // Vertex Pb(3, 7, 2);
    // Vertex Pc(9, 3, 4);
    // Vertex Pd(8, 0, 6);
    // vector<Vertex> curve = an.bezier(Pa, Pb, Pc, Pd, 0.1);

    Vertex P1(0, 0, 0); 
    arma::Mat<float> P2 = an.traslation(3, 3, 3) * P1.homogeneous();
    cout << P2;


    Vertex P3 = {1, 0, 0};
    //Linea P1 -> P3
    
    arma::Mat<float> P4 = an.scaling(0.5, 0, 0)* P1.homogeneous();
    arma::Mat<float> P5 = an.scaling(0.5, 0, 0)* P3.homogeneous();
    cout << P4 << P5;
    

    return 0;
}