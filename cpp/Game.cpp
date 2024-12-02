#include "../include/Game.h"
#include "../include/Animation.h"
#include "../include/Vertex.h"


Game::Game()
{

    Animation an;

    this->initial_position.set_x(-0.7);
    this->initial_position.set_y(0.0);
    this->initial_position.set_z(0.0);  

    this->bullet_position.set_x(this->initial_position.get_x() + 0.1);
    this->bullet_position.set_y(this->initial_position.get_y());
    this->bullet_position.set_z(this->initial_position.get_z());

    this->shooted = false;
    this->ind_trajectory = 0;

    this->angle = 0.0;
    this->force = 0.5;

    this->duck.load_model("models/duck.obj");
    this->duck.set_transform(an.traslation(this->initial_position.get_x(), this->initial_position.get_y(), this->initial_position.get_z()) 
                           * an.scaling(0.5, 0.5, 0.5) * an.rotation_y(90));
    this->duck.set_color(0.0, 0.0, 1.0);

    this->piggy.load_model("models/piggy.ply");
    //an.T(0.9, 0.0, 0.0) * an.Rx(90) * an.Rz(90) * an.S(0.00825, 0.00825, 0.00825)
    this->piggy.set_transform(an.traslation(0.8, -0.1, 0.0) * an.scaling(0.00825, 0.00825, 0.00825) * an.rotation_x(90) * an.rotation_z(90));
    this->piggy.set_color(0.0, 1.0, 0.0);

    this->slingshot.load_model("models/resortera.stl");
    this->slingshot.set_transform(an.traslation(-0.4, -0.1, 0.0) * an.scaling(0.01, 0.01, 0.01) * an.rotation_x(-90));
    this->slingshot.set_color(1.0, 0.0, 0.0);
    
    this->duck_trajectory = {};
}

void Game::draw(){

    Animation an;
    Triangle duck_data(this->duck.get_vertex_buffer_data(), this->duck.get_vertex_color_data());
    Triangle piggy_data(this->piggy.get_vertex_buffer_data(), this->piggy.get_vertex_color_data());
    Triangle slingshot_data(this->slingshot.get_vertex_buffer_data(), this->slingshot.get_vertex_color_data());

    if(shooted){
        if(this->ind_trajectory < this->duck_trajectory.size()){
            Vertex duckVertex = this->duck_trajectory[ind_trajectory];
            this->ind_trajectory++;
            this->duck.set_transform(an.traslation(duckVertex.get_x(), duckVertex.get_y(), duckVertex.get_z()));
        }
    }

    duck_data.draw();
    piggy_data.draw();
    slingshot_data.draw();
}

void Game::shoot()
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
    P2.set_y(P1.get_y() + (1 - cos(rangle)));
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

    this->duck_trajectory = an.bezier(P1, P2, P3, P4, 0.05);

    this->shooted = true;
}

void Game::moveDuck(float shift){
    Animation an;
    //tambien modifica la fuerza del disparo
    this->force += shift;
    //el pato no debe moverse mas de ese rango de -0.8 y -0.6
    if(this->force >= 0.6){
        this->force = 0.6;
        this->initial_position.set_x(-0.8);
    }
    else if(this->force <= 0.4){
        this->force = 0.4;
        this->initial_position.set_x(-0.6);
    }
    else {
        this->initial_position.set_x(-0.7);
    }
    this->duck.set_transform(an.traslation(this->initial_position.get_x(), this->initial_position.get_y(), this->initial_position.get_z()) 
                           * an.scaling(0.5, 0.5, 0.5) * an.rotation_y(90));
}

void Game::moveSlingshot(float shift){
    Animation an;
    //tambien modifica el ángulo del disparo
    this->angle += shift;
    //la resortera no debe moverse más de ese rango de -0.1 y 0.1 en el eje y
    float new_y = this->initial_position.get_y() + shift;
    if(new_y > 0.1){
        new_y = 0.1;
    }
    else if(new_y < -0.1){
        new_y = -0.1;
    }
    this->initial_position.set_y(new_y);
    this->slingshot.set_transform(an.traslation(-0.4, this->initial_position.get_y(), this->initial_position.get_z()) 
                                * an.scaling(0.01, 0.01, 0.01) * an.rotation_x(-90));
}

void Game::reset(){
    Animation an;
    this->shooted = false;
    this->ind_trajectory = 0;
    this->duck_trajectory.clear();
    this->force = 0.5;
    this->angle = 0.0;
    this->initial_position.set_x(-0.7);
    this->initial_position.set_y(0.0);
    this->duck.set_transform(an.traslation(this->initial_position.get_x(), this->initial_position.get_y(), this->initial_position.get_z()) 
                           * an.scaling(0.5, 0.5, 0.5) * an.rotation_y(90));
    this->slingshot.set_transform(an.traslation(-0.4, -0.1, 0.0) * an.scaling(0.01, 0.01, 0.01) * an.rotation_x(-90));
}