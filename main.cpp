#include <iostream>
#include <vector>
#include <armadillo>
#include "include/Vertex.h"
#include "include/Animation.h"

using namespace std;

int main(){
    /*
    Animation an;
    Vertex P1(2, -3, 0);
    Vertex P2(-5, 6, 4);
    vector<Vertex> line = an.pline(P1, P2, 0.1);

    Vertex Pa(0, 10, 0);
    Vertex Pb(3, 7, 2);
    Vertex Pc(9, 3, 4) ;
    Vertex Pd(8, 0, 6);
    vector<Vertex> curve = an.bezier(Pa, Pb, Pc, Pd, 0.1);
    */
arma::Mat<float> T = {{1, 1, 1, 1}};
arma::Mat<float> Mb = {
                    {-1, 3, -3, 1},
                    {3, -6, 3, 0},
                    {-3, 3, 0, 0},
                    {1, 0, 0, 0}
                    };
arma::Mat<float> res = T * Mb;
cout << res << endl;
    return 0;
}