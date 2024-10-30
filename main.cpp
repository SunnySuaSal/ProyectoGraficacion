#include <stdio.h>
#include <stdlib.h>
#include "include/Cannon.h"
#include "include/OpenGL.h"
#include "include/Triangle.h"

using namespace std;

int main(){
    Cannon myCannon;
    myCannon.shoot();
    cout << "Listo" << endl;
    OpenGL gl = OpenGL();

    GLFWwindow* window = gl.createWindow( 1024, 768, "Graficación");
    if( window == NULL )
        return -1;

    glfwSetInputMode(window, GLFW_STICKY_KEYS, GLFW_TRUE);
    
    Triangle tr1({-1.0f, -1.0f, 0.0f,
                    0.0f, -1.0f, 0.0f,
                    -0.5f, 0.0f, 0.0f,
                    0.0f, -1.0f, 0.0f,
                    1.0f, -1.0f, 0.0f,          
                    0.5f, 0.0f, 0.0f,
                    -0.5f, 0.0f, 0.0f,
                    0.5f, 0.0f, 0.0f,
                    0.0f, 1.0f, 0.0f},
                 {0.0f, 1.0f, 0.0f,
                    0.0f, 1.0f, 0.0f,
                    0.0f, 1.0f, 0.0f,
                    0.0f, 0.0f, 1.0f,
                    0.0f, 0.0f, 1.0f,
                    0.0f, 0.0f, 1.0f,
                    1.0f, 0.0f, 0.0f,
                    1.0f, 0.0f, 0.0f,
                    1.0f, 0.0f, 0.0f});

	glClearColor(0.0f, 0.0f, 0.4f ,0.0f);
	
    do {
        glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

        tr1.draw();

        glfwSwapBuffers(window);
        glfwPollEvents();

        int state_sp = glfwGetKey(window, GLFW_KEY_SPACE) ;
        if (state_sp == GLFW_PRESS) {
            cout << "Disparo" << endl;
        }

    } while ( glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
        glfwWindowShouldClose(window) == 0 );
    return 0;
}
