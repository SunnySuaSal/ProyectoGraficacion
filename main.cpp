#include <stdio.h>
#include <stdlib.h>
#include "include/Cannon.h"
#include "include/OpenGL.h"

using namespace std;

int main(){
    Cannon myCannon;

    OpenGL gl = OpenGL();

    //Commnt for testing

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

        int state_sp = glfwGetKey(window, GLFW_KEY_SPACE);
        if (state_sp == GLFW_PRESS) {
            myCannon.shoot();
        }

    } while ( glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
        glfwWindowShouldClose(window) == 0 );
    return 0;
}
