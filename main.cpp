#include <iostream>
#include <vector>
#include <string>
#include "include/Vertex.h"
#include "include/Face.h"

using namespace std;

int main(){

    Vertex v1(0,0,0);
    Vertex v2(1,0,0);
    Vertex v3(1,0,1);
    Vertex v4(0,0,1);
    Vertex v5(0.5,1,0.5);

    Face f1({v1, v2, v3, v4});
    f1.print();
    Face f2({v4, v3, v5});
    f2.print();
    Face f3({v3, v2, v5});
    f3.print();
    Face f4({v1, v2, v5});
    f4.print();
    Face f5({v1, v4, v5});
    f5.print();

}