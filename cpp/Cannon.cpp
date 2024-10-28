#include "../include/Cannon.h"

Cannon::Cannon()
{
    cout << "Cargando..." << endl;
    Object<Obj> cbody("models/cannon_body.obj");
    Object<Ply> cwheel("models/cannon_wheel.ply");
    Object<Stl> bullet("models/bullet.stl");
    cout << "Listo." << endl;
}
