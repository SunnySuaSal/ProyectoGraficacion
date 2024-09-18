#include "../include/Ply.h"

Ply::Ply(string file)
{
    this->name = "";
    this->vertices = {};
    this->faces = {};

    string line;
    ifstream PLYfile(file);

    bool encabezado_leido = false;
    int num_vertices = 0;
    int num_caras = 0;
    int vertice_actual = 0;
    int cara_actual = 0;

    while (getline(PLYfile, line)) {
        if (!encabezado_leido) {
            // Procesar el encabezado
            if (line.find("element vertex") != string::npos) {
                num_vertices = stoi(split(line, " ")[2]);
            } else if (line.find("element face") != string::npos) {
                num_caras = stoi(split(line, " ")[2]);
            } else if (line == "end_header") {
                encabezado_leido = true;
            }
        } else {
            // Procesar vértices
            if (vertice_actual < num_vertices) {
                vector<string> elements = split(line, " ");
                Vertex v(stof(elements[0]), stof(elements[1]), stof(elements[2]));
                this->vertices.push_back(v);
                vertice_actual++;
            }
            // Procesar caras
            else if (cara_actual < num_caras) {
                vector<string> elements = split(line, " ");
                int vertex_indices = stoi(elements[0]);
                vector<unsigned int> vert_temp;
                for (int i = 1; i <= vertex_indices; i++) {
                    int ind_v = stoi(elements[i]);
                    vert_temp.push_back(ind_v);
                }
                Face f(vert_temp);
                this->faces.push_back(f);
                cara_actual++;
            }
        }
    }
}

vector<string> Ply::split(const string& str, const string& delim) {
    vector<string> tokens;
    size_t prev = 0, pos = 0;
    do {
        pos = str.find(delim, prev);
        if (pos == string::npos) pos = str.length();
        string token = str.substr(prev, pos - prev);
        if (!token.empty()) tokens.push_back(token);
        prev = pos + delim.length();
    } while (pos < str.length() && prev < str.length());
    return tokens;
}

void Ply::print_faces() {
    for (Face f : this->faces) {
        f.print(this->vertices);
    }
}
