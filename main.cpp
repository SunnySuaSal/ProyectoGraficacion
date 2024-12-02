#include <stdio.h>
#include <stdlib.h>
#include "include/Game.h"
#include "include/OpenGL.h"
#include "include/Vertex.h"
#include <armadillo>

using namespace std;

int main(){
    
    Game game;

    OpenGL gl = OpenGL();

    GLFWwindow* window = gl.createWindow( 1024, 768, "Graficación");
    if( window == NULL )
        return -1;

    glfwSetInputMode(window, GLFW_STICKY_KEYS, GLFW_TRUE);
    
    glClearColor(0.0f, 0.0f, 0.0f ,0.0f);
	
    do {
        glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

        game.draw();

        glfwSwapBuffers(window);
        glfwPollEvents();

        /*
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

        */

    } while ( glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
        glfwWindowShouldClose(window) == 0 );

    return 0;
}
