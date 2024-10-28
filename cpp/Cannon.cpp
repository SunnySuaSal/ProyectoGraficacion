#include "../include/Cannon.h"
#include "../include/Animation.h"

Cannon::Cannon()
{
    this->cbody.load_model("models/cannon_body.obj");
    this->cwheel.load_model("models/cannon_wheel.ply");
    this->bullet.load_model("models/bullet.stl");

    this->initial_position.set_x(0,0);
    this->initial_position.set_y(0,0);
    this->initial_position.set_z(0,0);

    this->bullet_position.set_x(this->initial_position.get_x()+0.1);
    this->bullet_position.set_y(this->initial_position.get_y()+0.2);
    this->bullet_position.set_z(this->initial_position.get_z());

    this->angle = 0.0;
    this->force = 1.0;
}

void Cannon::shoot()
{
    Vertex P1, P2, P3, P4;
}