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
    for(float t=0.0; t<1.0+dt; t=t+dt){
        Vertex P = (P1 * pow((1 - t), 3)) +
                    (P2 * (3*t*pow((1-t), 2))) + 
                    (P3 * (3*pow(t, 2) * (1 - t))) + 
                    (P4 * (pow(t,3)));
        curvePoints.push_back(P);
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