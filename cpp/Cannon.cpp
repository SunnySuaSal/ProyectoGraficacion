#include "../include/Cannon.h"
#include "../include/Animation.h"


Cannon::Cannon()
{

    Animation an;

    this->initial_position.set_x(-0.9);
    this->initial_position.set_y(0.0);
    this->initial_position.set_z(0.0);  

    this->bullet_position.set_x(this->initial_position.get_x()+0.1);
    this->bullet_position.set_y(this->initial_position.get_y()+0.2);
    this->bullet_position.set_z(this->initial_position.get_z());

    this->cbody.load_model("models/cannon_body.obj");


    this->lcwheel.load_model("models/cannon_wheel.ply");
    this->lcwheel.set_transform(an.traslation(this->initial_position.get_x(), this->initial_position.get_y(), this->initial_position.get_z()) 
                                * an.scaling(0.1, 0.1, 0.1));

    this->rcwheel.load_model("models/cannon_wheel.ply");

    this->bullet.load_model("models/bullet.stl");

    this->angle = 45.0;
    this->force = 0.5;

    this->bullet_trajectory = {};
}

void Cannon::draw(){
        Triangle body_data(this->cbody.get_vertex_buffer_data(),
            this->cbody.get_vertex_color_data());
        Triangle lwheel_data(this->lcwheel.get_vertex_buffer_data(),
            this->lcwheel.get_vertex_color_data());
        Triangle rwheel_data(this->rcwheel.get_vertex_buffer_data(),
            this->rcwheel.get_vertex_color_data());
        Triangle bullet_data(this->bullet.get_vertex_buffer_data(),
            this->bullet.get_vertex_color_data());

    //body_data.draw();
    lwheel_data.draw();
    //rwheel_data.draw();
    //bullet_data.draw();
}

void Cannon::shoot()
{
    Animation an;
    Vertex P1, P2, P3, P4;

    //Calcular la trayectoria curva
    P1.set_x(this->bullet_position.get_x());
    P1.set_y(this->bullet_position.get_y());
    P1.set_z(this->bullet_position.get_z());
    P1.print();

    float rangle = (this->angle * PI) / 180.0;

    P2.set_x(P1.get_x() + this->force);
    P2.set_y(P1.get_y() + (1-cos(rangle)));
    P2.set_z(P1.get_z());
    P2.print();

    P3.set_x(P2.get_x() + this->force);
    P3.set_y(P2.get_y());
    P3.set_z(P1.get_z());
    P3.print();

    P4.set_x(P3.get_x() + this->force);
    P4.set_y(0.0);
    P4.set_z(P1.get_z());
    P4.print();

    this->bullet_trajectory = an.bezier(P1, P2, P3, P4, 0.1);
}