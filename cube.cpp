#include <iostream>
#include <vector>
#include <string>
#include "include/Vertex.h"
#include "include/Face.h"

using namespace std;

int main(){

    Vertex v1(0,0,0);
    Vertex v2(1,0,0);
    Vertex v3(1,1,0);
    Vertex v4(0,1,0);
    Vertex v5(0,0,1);
    Vertex v6(1,0,1);
    Vertex v7(1,1,1);
    Vertex v8(0,1,1);

    Face f1({v1, v2, v3, v4});
    Face f2({v1, v4, v8, v5});
    Face f3({v5, v6, v7, v8});
    Face f4({v2, v3, v7, v6});
    Face f5({v4, v8, v7, v3});
    Face f6({v1, v5, v6, v2});

    // cout << "Graficacion por computadora" << endl;
    // vector<string> msg {"Hola", "C++", "Mundo", "desde", "VS Code", "y la C++ extension!"};
    // int i=0;
    // for (const string& word : msg){
    //     cout << word << " ";
        
    //     ++i;

    // }

    // cout << endl;

}