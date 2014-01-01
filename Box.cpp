#include "Box.h"

CBox::CBox(float posX, float posY, float posZ, float rotation, glm::vec3 rotationAxis, float scale) : //remove glm from constructor
    mModelMatrix(glm::mat4(1.0f)),
    mScale(glm::vec3( scale , scale , scale ) ),
    mRotation(rotation),
    mRotationAxis(rotationAxis),    //problem when rotationaxis is a poaint (glm::vec3(0,0,0))
    mTranslation(glm::vec3(posX,posY,posZ)),
    mVertexBufferData{-1.0f,-1.0f,-1.0f,-1.0f,-1.0f, 1.0f,-1.0f, 1.0f, 1.0f,
                       1.0f, 1.0f,-1.0f,-1.0f,-1.0f,-1.0f,-1.0f, 1.0f,-1.0f,
                       1.0f,-1.0f, 1.0f,-1.0f,-1.0f,-1.0f,1.0f,-1.0f,-1.0f,
                       1.0f, 1.0f,-1.0f,1.0f,-1.0f,-1.0f,-1.0f,-1.0f,-1.0f,
                      -1.0f,-1.0f,-1.0f,-1.0f, 1.0f, 1.0f,-1.0f, 1.0f,-1.0f,
                       1.0f,-1.0f, 1.0f,-1.0f,-1.0f, 1.0f,-1.0f,-1.0f,-1.0f,
                      -1.0f, 1.0f, 1.0f,-1.0f,-1.0f, 1.0f,1.0f,-1.0f, 1.0f,
                       1.0f, 1.0f, 1.0f,1.0f,-1.0f,-1.0f,1.0f, 1.0f,-1.0f,
                       1.0f,-1.0f,-1.0f,1.0f, 1.0f, 1.0f,1.0f,-1.0f,  1.0f,
                       1.0f, 1.0f, 1.0f,1.0f, 1.0f,-1.0f,-1.0f, 1.0f,-1.0f,
                       1.0f, 1.0f, 1.0f,-1.0f, 1.0f,-1.0f,-1.0f, 1.0f, 1.0f,
                       1.0f, 1.0f, 1.0f,-1.0f, 1.0f, 1.0f,1.0f,-1.0f, 1.0f},
    mVertexBufferDataSize(sizeof(mVertexBufferData)),
    mUVBufferData{0.000059f, 1.0f-0.000004f, 0.000103f, 1.0f-0.336048f,
                  0.335973f, 1.0f-0.335903f, 1.000023f, 1.0f-0.000013f,
                  0.667979f, 1.0f-0.335851f, 0.999958f, 1.0f-0.336064f,
                  0.667979f, 1.0f-0.335851f, 0.336024f, 1.0f-0.671877f,
                  0.667969f, 1.0f-0.671889f, 1.000023f, 1.0f-0.000013f,
                  0.668104f, 1.0f-0.000013f, 0.667979f, 1.0f-0.335851f,
                  0.000059f, 1.0f-0.000004f, 0.335973f, 1.0f-0.335903f,
                  0.336098f, 1.0f-0.000071f, 0.667979f, 1.0f-0.335851f,
                  0.335973f, 1.0f-0.335903f, 0.336024f, 1.0f-0.671877f,
                  1.000004f, 1.0f-0.671847f, 0.999958f, 1.0f-0.336064f,
                  0.667979f, 1.0f-0.335851f, 0.668104f, 1.0f-0.000013f,
                  0.335973f, 1.0f-0.335903f, 0.667979f, 1.0f-0.335851f,
                  0.335973f, 1.0f-0.335903f, 0.668104f, 1.0f-0.000013f,
                  0.336098f, 1.0f-0.000071f, 0.000103f, 1.0f-0.336048f,
                  0.000004f, 1.0f-0.671870f, 0.336024f, 1.0f-0.671877f,
                  0.000103f, 1.0f-0.336048f, 0.336024f, 1.0f-0.671877f,
                  0.335973f, 1.0f-0.335903f, 0.667969f, 1.0f-0.671889f,
                  1.000004f, 1.0f-0.671847f, 0.667979f, 1.0f-0.335851f
    },
    mUVBufferDataSize(sizeof(mUVBufferData))

{
    mModelMatrix = glm::scale(mModelMatrix, mScale);
    mModelMatrix = glm::rotate(mModelMatrix, mRotation, mRotationAxis);
    mModelMatrix = glm::translate(mModelMatrix, mTranslation);
}

CBox::~CBox(){
}

void CBox::setScale(const glm::vec3 &value){
    mScale = value;
    mModelMatrix = glm::scale(mModelMatrix, mScale);
}

void CBox::setRotation(float rotation, const glm::vec3 &rotationAxis){
    mRotation = rotation;
    mRotationAxis = rotationAxis;
    mModelMatrix = glm::rotate(mModelMatrix, mRotation, mRotationAxis);
}

void CBox::setTranslation(const glm::vec3 &value){
    mTranslation = value;
    mModelMatrix = glm::translate(mModelMatrix, mTranslation);
}


/*---------   !!!!!!    ------------
 Update the camera class to follow same pattern as Box.
 it should not be nessesay ro use a updatecamera function.
 instead do the calculations in the setterfunctions
------------------------------------*/
