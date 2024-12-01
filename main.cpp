#include <stdio.h>
#include <stdlib.h>
//#include "include/Cannon.h"
//#include "include/OpenGL.h"
#include "include/Vertex.h"
#include <armadillo>

using namespace std;

int main(){
    /*
    Cannon myCannon;

    OpenGL gl = OpenGL();

    GLFWwindow* window = gl.createWindow( 1024, 768, "Graficación");
    if( window == NULL )
        return -1;

    glfwSetInputMode(window, GLFW_STICKY_KEYS, GLFW_TRUE);
    
    glClearColor(0.0f, 0.0f, 0.0f ,0.0f);
	
    do {
        glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

        myCannon.draw();

        glfwSwapBuffers(window);
        glfwPollEvents();

        int state_up = glfwGetKey(window, GLFW_KEY_UP);
        if (state_up == GLFW_PRESS)
            myCannon.move(5);

        int state_down = glfwGetKey(window, GLFW_KEY_DOWN);
        if (state_down == GLFW_PRESS)
            myCannon.move(-5);

        int state_sp = glfwGetKey(window, GLFW_KEY_SPACE);
        if (state_sp == GLFW_PRESS)
            myCannon.shoot();
        
        int state_restart = glfwGetKey(window, GLFW_KEY_R);
        if (state_restart == GLFW_PRESS)
            myCannon.reset();

    } while ( glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
        glfwWindowShouldClose(window) == 0 );
    */

   Vertex v1(3.0, 4.0, 0.0);
   Vertex v2(-1.0, 1.0, 1.0);
   Vertex v3(6.0, 0.0, 2.0);

   arma::vec va = {v2.get_x() - v1.get_x(), v2.get_y() - v1.get_y(), v2.get_z() - v1.get_z()};
   arma::vec vb = {v3.get_x() - v1.get_x(), v3.get_y() - v1.get_y(), v3.get_z() - v1.get_z()};

    arma::vec vc = arma::cross(va, vb);
    arma::vec nvc = arma::normalise(vc);
    cout << nvc;

    return 0;
}
