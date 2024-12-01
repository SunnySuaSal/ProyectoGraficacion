#include "../include/Stl.h"

Stl::Stl(): Model()
{
    
}

Stl::Stl(string file): Model(file)
{
    this->load(file);
}

void Stl::load_model(string file)
{
    this->load(file);
}

void Stl::load(string file) {
    string line;
    ifstream STLfile(file);

    bool in_facet = false;
    vector<unsigned int> vert_temp;

    while (getline(STLfile, line)) {
        vector<string> elements = split(line, " ");
        
        if (elements.empty()) continue;

        // Procesar el inicio de un facet
        if (elements[0] == "facet" && elements.size() >= 5 && elements[1] == "normal") {
            in_facet = true;
        }
        // Procesar los vértices dentro del loop de un facet
        else if (in_facet && elements[0] == "vertex" && elements.size() >= 4) {
            // Crear un vértice usando el constructor de Vertex
            float x = stof(elements[1]);
            float y = stof(elements[2]);
            float z = stof(elements[3]);
            Vertex v(x, y, z);
            this->vertices.push_back(v);
            vert_temp.push_back(this->vertices.size() - 1);
        }
        // Procesar el fin de un loop/facet
        else if (elements[0] == "endfacet") {
            if (vert_temp.size() == 3) {
                Face f(vert_temp);
                this->faces.push_back(f);
            }
            vert_temp.clear();
            in_facet = false;
        }
    }
    this->calculate_normals();
}
