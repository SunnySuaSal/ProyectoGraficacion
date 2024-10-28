#include "../include/Model.h"

Model::Model()
{
    this->name = "";
    this->vertices = {};
    this->faces = {};
}

Model::Model(string file)
{
    this->name = "";
    this->vertices = {};
    this->faces = {};
}

vector<string> Model::split(const string& str, const string& delim){
    vector<string> tokens;    size_t prev = 0, pos = 0;
    do    {        pos = str.find(delim, prev);
        if (pos == string::npos) pos = str.length();
        string token = str.substr(prev, pos-prev);
        if (!token.empty()) tokens.push_back(token);
        prev = pos + delim.length();
    }
    while (pos < str.length() && prev < str.length());
    return tokens;
}

void Model::print_faces(){
    for(Face f : this->faces){
        f.print(this->vertices);
    }
}

vector<Face> Model::get_faces(){
    return this->faces;
}