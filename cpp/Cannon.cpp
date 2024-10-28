#include "../include/Cannon.h"

Cannon::Cannon()
{
    cout << "Cargando..." << endl;
    this->cbody.load_model("models/cannon_body.obj");
    //Object<Ply> cwheel;
    //Object<Stl> bullet;
    cout << "Listo." << endl;
}
