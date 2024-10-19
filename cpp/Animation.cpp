#include "../include/Animation.h"

Animation::Animation()
{

}

vector<Vertex> Animation::pline(Vertex P1, Vertex P2, float dt){
    vector<Vertex> linePoints = {};
    //Ecuacion parametrica de la recta
    //P = P1 + t(P2 - P1)
    for(float t=0.0; t<1.0+dt; t=t+dt){
    Vertex P = P1 + ((P2 - P1) * t);
    linePoints.push_back(P);
    }
    return (linePoints);
}

vector<Vertex> Animation::bezier(Vertex P1, Vertex P2, Vertex P3, Vertex P4, float dt){
    vector<Vertex> curvePoints = {};
    //Curvas de Bezier
    arma::Mat<float> Mb = {
                    {-1, 3, -3, 1},
                    {3, -6, 3, 0},
                    {-3, 3, 0, 0},
                    {1, 0, 0, 0}
                    };
    arma::Col<float> Gb = {P1.get_x(), P2.get_x(), P3.get_x(), P4.get_x()};


    //Q(t) = T * Mb * Gb
    for(float t=0.0; t<1.0+dt; t=t+dt){
        arma::Row<float> T = {powf(t, 3), powf(t, 2), t, 1};
        arma::Mat<float> Qt = T * Mb * Gb;
        cout << Qt;
    }
    return (curvePoints);
}

vector<Vertex> Animation::hermite(Vertex P1, Vertex P4, Vertex R1, Vertex R4, float dt){
    vector<Vertex> curvePoints = {};
    //Curvas de Hermite
    for(float t=0.0; t<1.0+dt; t=t+dt){
        Vertex P = (P1 * (2*pow(t,3) - 3*pow(t,2) + 1)) +
                    (P4 * (-2*pow(t,3) + 3*pow(t,2)) + 
                    (R1 * (pow(t,3) - 2*pow(t,2) + t)) + 
                    (R4 * (pow(t,3) - pow(t,2))));
        curvePoints.push_back(P);
    }  
    return (curvePoints); 
}