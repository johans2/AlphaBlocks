#include "alphaBlocks.h"
#include "Game.h"
#include "Scene.h"
#include "SceneObject.h"
#include "Camera.h"

#include "Box.h"

int main(){
    // Initialise GLFW
    if( !glfwInit() )
    {
        fprintf( stderr, "Failed to initialize GLFW\n" );
        return -1;
    }

    glfwOpenWindowHint(GLFW_FSAA_SAMPLES, 4);
    glfwOpenWindowHint(GLFW_OPENGL_VERSION_MAJOR, 2);
    glfwOpenWindowHint(GLFW_OPENGL_VERSION_MINOR, 1);

    // Open a window and create its OpenGL context
    if( !glfwOpenWindow( 1024, 768, 0,0,0,0, 32,0, GLFW_WINDOW ) )
    {
        fprintf( stderr, "Failed to open GLFW window.\n" );
        glfwTerminate();
        return -1;
    }

    // Initialize GLEW
    if (glewInit() != GLEW_OK) {
        fprintf(stderr, "Failed to initialize GLEW\n");
        return -1;
    }

    glfwSetWindowTitle( "Tutorial 05" );

    // Ensure we can capture the escape key being pressed below
    glfwEnable( GLFW_STICKY_KEYS );

    // Dark blue background
    glClearColor(0.0f, 0.0f, 0.2f, 0.0f);

    // Enable depth test
    glEnable(GL_DEPTH_TEST);
    // Accept fragment if it closer to the camera than the former one
    glDepthFunc(GL_LESS);


    // Create and compile our GLSL program from the shaders
    GLuint programID = LoadShaders( "TransformVertexShader.vertexshader", "TextureFragmentShader.fragmentshader" );

    // Get a handle for our "MVP" uniform
    GLuint MatrixID = glGetUniformLocation(programID, "MVP");

    // Get a handle for our buffers
    GLuint vertexPosition_modelspaceID = glGetAttribLocation(programID, "vertexPosition_modelspace");
    GLuint vertexUVID = glGetAttribLocation(programID, "vertexUV");

    CCamera* camera = new CCamera(45.0f, 4.0f / 3.0f, 0.1f, 100.0f, glm::vec3(4,3,3), glm::vec3(0,0,0), glm::vec3(0,1,0));

    CBox* myBox = new CBox(0.f,0.f,0.f,0.f,glm::vec3(1,1,1),1.f);
    CBox* myBox2 = new CBox(10.f,0.f,0.f,45.f,glm::vec3(1,1,1), 0.2f);
    // Our ModelViewProjection : multiplication of our 3 matrices

    //glm::mat4 MVP        = camera->getPerspective() * camera->getView() * Model;// Remember, matrix multiplication is the other way around
    glm::mat4 MVP        = camera->getPerspective() * camera->getView() * myBox->getModelMatrix();
    glm::mat4 MVP2       = camera->getPerspective() * camera->getView() * myBox2->getModelMatrix();
    // Load the texture using any two methods
    GLuint Texture = loadBMP_custom("uvtemplate.bmp");
    //GLuint Texture = loadDDS("uvtemplate.DDS");

    // Get a handle for our "myTextureSampler" uniform
    GLuint TextureID  = glGetUniformLocation(programID, "myTextureSampler");


    //box 1
    GLuint vertexbuffer;
    glGenBuffers(1, &vertexbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    glBufferData(GL_ARRAY_BUFFER, *myBox->getVertexBufferDataSize(), &(myBox->getVertexBufferData())[0], GL_STATIC_DRAW);

    GLuint uvbuffer;
    glGenBuffers(1, &uvbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, uvbuffer);
    glBufferData(GL_ARRAY_BUFFER, *myBox->getUVBufferDataSize(), &(myBox->getUVBufferData())[0], GL_STATIC_DRAW);

    //box 2
    GLuint vertexbuffer2;
    glGenBuffers(1, &vertexbuffer2);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer2);
    glBufferData(GL_ARRAY_BUFFER, *myBox2->getVertexBufferDataSize(), &(myBox2->getVertexBufferData())[0], GL_STATIC_DRAW);

    GLuint uvbuffer2;
    glGenBuffers(1, &uvbuffer2);
    glBindBuffer(GL_ARRAY_BUFFER, uvbuffer2);
    glBufferData(GL_ARRAY_BUFFER, *myBox2->getUVBufferDataSize(), &(myBox2->getUVBufferData())[0], GL_STATIC_DRAW);




    //do stuff
    CGame* game = new CGame();
    //ISceneObject* testBox = new CBox();

    while(glfwGetKey( GLFW_KEY_ESC ) != GLFW_PRESS &&
          glfwGetWindowParam( GLFW_OPENED )){

        game->Update();


        // Clear the screen
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Use our shader
        glUseProgram(programID);

        // Send our transformation to the currently bound shader,
        // in the "MVP" uniform
        glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);

        // Bind our texture in Texture Unit 0
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, Texture);
        // Set our "myTextureSampler" sampler to user Texture Unit 0
        glUniform1i(TextureID, 0);

        //***********************************************************************************
        // 1rst attribute buffer : vertices
        glEnableVertexAttribArray(vertexPosition_modelspaceID);
        glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
        glVertexAttribPointer(
            vertexPosition_modelspaceID,  // The attribute we want to configure
            3,                            // size
            GL_FLOAT,                     // type
            GL_FALSE,                     // normalized?
            0,                            // stride
            (void*)0                      // array buffer offset
        );

        // 2nd attribute buffer : UVs
        glEnableVertexAttribArray(vertexUVID);
        glBindBuffer(GL_ARRAY_BUFFER, uvbuffer);
        glVertexAttribPointer(
            vertexUVID,                   // The attribute we want to configure
            2,                            // size : U+V => 2
            GL_FLOAT,                     // type
            GL_FALSE,                     // normalized?
            0,                            // stride
            (void*)0                      // array buffer offset
        );

        // Draw the triangles !
        glDrawArrays(GL_TRIANGLES, 0, 12*3); // 12*3 indices starting at 0 -> 12 triangles

        glDisableVertexAttribArray(vertexPosition_modelspaceID);
        glDisableVertexAttribArray(vertexUVID);
        //***********************************************************************************

        glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP2[0][0]);
        glEnableVertexAttribArray(vertexPosition_modelspaceID);
        glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer2);
        glVertexAttribPointer(
            vertexPosition_modelspaceID,  // The attribute we want to configure
            3,                            // size
            GL_FLOAT,                     // type
            GL_FALSE,                     // normalized?
            0,                            // stride
            (void*)0                      // array buffer offset
        );

        // 2nd attribute buffer : UVs
        glEnableVertexAttribArray(vertexUVID);
        glBindBuffer(GL_ARRAY_BUFFER, uvbuffer2);
        glVertexAttribPointer(
            vertexUVID,                   // The attribute we want to configure
            2,                            // size : U+V => 2
            GL_FLOAT,                     // type
            GL_FALSE,                     // normalized?
            0,                            // stride
            (void*)0                      // array buffer offset
        );

        // Draw the triangles !
        glDrawArrays(GL_TRIANGLES, 0, 12*3); // 12*3 indices starting at 0 -> 12 triangles

        glDisableVertexAttribArray(vertexPosition_modelspaceID);
        glDisableVertexAttribArray(vertexUVID);


        glfwSwapBuffers();
    }
    // Cleanup VBO and shader
    glDeleteBuffers(1, &vertexbuffer);
    glDeleteBuffers(1, &uvbuffer);
    glDeleteBuffers(1, &vertexbuffer2);
    glDeleteBuffers(1, &uvbuffer2);
    glDeleteProgram(programID);
    glDeleteTextures(1, &TextureID);


    glfwTerminate();


    delete game;
    return 0;


}
