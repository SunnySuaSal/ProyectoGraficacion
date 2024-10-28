#include "../include/Obj.h"

Obj::Obj(): Model()
{

}

Obj::Obj(string file): Model(file)
{
    this->load(file);
}

void Obj::load_model(string file)
{
    this->load(file);
}

void Obj::load(string file){
    string line;

    //Creando un objeto de la clase ifstream llamado ONJfile,
    //cuyo constructor pide la ruta a un archivo.
    ifstream OBJfile(file);

    while(getline(OBJfile, line)){

        vector<string> elements = split(line, " ");
        if(!elements.empty() > 0){
            if(elements[0] == "o"){
                this->name = elements[1];
            }
            if(elements[0] == "v"){
                //Crear un objeto de la clase Vertex
                Vertex v(stof(elements[1]), stof(elements[2]), stof(elements[3]));
                this->vertices.push_back(v);
            }
            if(elements[0] == "f"){
                //Crear un objeto de la clase Face
                vector<unsigned int> vert_temp = {};
                for(int i=1; i<elements.size(); i++){
                    vector<string> vrt = split(elements[i], "/");
                    int ind_v = stoi(vrt[0]) - 1;
                    vert_temp.push_back(ind_v);
                }
               
                Face f(vert_temp);
                this->faces.push_back(f);
            }
        }
    }

}