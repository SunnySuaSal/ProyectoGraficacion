#include "../include/Cannon.h"

Cannon::Cannon()
{
    cout << "Cargando..." << endl;
    this->cbody.load_model("models/cannon_body.obj");
    this->cwheel.load_model("models/cannon_wheel.ply");
    this->bullet.load_model("models/bullet.stl");
    cout << "Listo." << endl;
}
