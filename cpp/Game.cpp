#include "../include/Game.h"
#include "../include/Animation.h"
#include "../include/Vertex.h"


Game::Game()
{

    Animation an;

    this->initial_position.set_x(-0.9);
    this->initial_position.set_y(0.0);
    this->initial_position.set_z(0.0);  

    this->bullet_position.set_x(this->initial_position.get_x()+0.1);
    this->bullet_position.set_y(this->initial_position.get_y());
    this->bullet_position.set_z(this->initial_position.get_z());

    this->shooted = false;
    this->ind_trajectory = 0;

    this->angle = 0.0;
    this->force = 0.5;

    this->duck.load_model("models/duck.obj");
    this->duck.set_transform(an.traslation(-0.7, 0.0, 0.0) * an.scaling(0.5, 0.5, 0.5) * an.rotation_y(90));
    this->duck.set_color(0.0, 0.0, 1.0);

    this->piggy.load_model("models/piggy.ply");
    this->piggy.set_transform(an.traslation(this->initial_position.get_x(), this->initial_position.get_y(), this->initial_position.get_z()-0.1) 
                                * an.scaling(0.9, 0.9, 0.9));
    this->piggy.set_color(0.0, 1.0, 0.0);

    this->slingshot.load_model("models/resortera.stl");
    this->slingshot.set_transform(an.traslation(this->initial_position.get_x(), this->initial_position.get_y(), this->initial_position.get_z()) 
                                * an.scaling(0.1, 0.1, 0.1));
    this->slingshot.set_color(1.0, 0.0, 0.0);
    
    this->duck_trajectory = {};
}

void Game::draw(){

    Animation an;
    Triangle duck_data(this->duck.get_vertex_buffer_data(), this->duck.get_vertex_color_data());
    Triangle piggy_data(this->piggy.get_vertex_buffer_data(), this->piggy.get_vertex_color_data());
    Triangle slingshot_data(this->slingshot.get_vertex_buffer_data(), this->slingshot.get_vertex_color_data());

    duck_data.draw();
    //piggy_data.draw();
    //slingshot_data.draw();

    if(shooted){
        if(this->ind_trajectory < this->duck_trajectory.size()){
            Vertex duckVertex = this->duck_trajectory[ind_trajectory];
            this->ind_trajectory++;
            this->duck.set_transform(an.traslation(duckVertex.get_x(), duckVertex.get_y(), duckVertex.get_z()) 
                                * an.scaling(0.1, 0.1, 0.1));
        }
    }
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

    this->duck_trajectory = an.bezier(P1, P2, P3, P4, 0.05);

    this->shooted = true;
}

void Game::move(float angle){
    Animation an;
    if(this->angle >= 0.0 && this->angle <= 80.0)
        this->angle += angle;
    
    if(this->angle < 0.0)
        this->angle = 0.0;

    if(this->angle > 80.0)
        this->angle = 80.0;

    this->duck.set_transform(an.traslation(this->initial_position.get_x()+0.1, this->initial_position.get_y()+0.2, this->initial_position.get_z()) 
                           * an.rotation_z(this->angle) * an.scaling(0.09, 0.09, 0.09));

}

void Game::reset(){
    Animation an;
    this->shooted = false;
    this->ind_trajectory = 0;
    this->duck_trajectory.clear();
    this->duck.set_transform(an.traslation(this->bullet_position.get_x(), this->bullet_position.get_y(), this->bullet_position.get_z()) 
                                * an.scaling(0.1, 0.1, 0.1));
}