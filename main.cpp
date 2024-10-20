#include <iostream>
#include <vector>
#include <armadillo>
#include "include/Vertex.h"
#include "include/Animation.h"

using namespace std;

int main(){
    // Animation an;
    // Vertex P1(2,-3, 0);
    // Vertex P2(-5, 6, 4);
    // vector<Vertex> line = an.pline(P1, P2, 0.1);
    // Vertex Pa(0,10, 0);
    // Vertex Pb(3, 7, 2);
    // Vertex Pc(9, 3, 4);
    // Vertex Pd(8, 0, 6);
    // vector<Vertex> curve = an.bezier(Pa, Pb, Pc, Pd, 0.1);

    Vertex P1(0, 0, 0); 

    float dx = 3;
    float dy = 3;
    float dz = 3;
    arma::Mat<float> T = {
                    {1, 0, 0, dx},
                    {0, 1, 0, dy},
                    {0, 0, 1, dz},
                    {0, 0, 0, 1}
                    };
    arma::Col<float> P2 = T * P1.homogeneous();
    //cout << P2;


    Vertex P3 = {1, 0, 0};
    //Linea P1 -> P3
    float sx = 2; //Duplica su tamano en x
    sx  = 0.5; //Reduce su tamano a la mitad en x
    float sy = 0;
    float sz = 0;
    arma::Mat<float> S = {
                    {sx, 0, 0, 0},
                    {0, sy, 0, 0},
                    {0, 0, sz, 0},
                    {0, 0, 0, 1}
                    };
    arma::Mat<float> P4 = S * P1.homogeneous();
    arma::Mat<float> P5 = S * P3.homogeneous();
    cout << P4 << P5;
    

    return 0;
}