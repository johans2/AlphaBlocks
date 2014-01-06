#ifndef _ALPHABLOCKS_BOX_H_
#define _ALPHABLOCKS_BOX_H_

#include "SceneObject.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>
#include <array>
#include <string>

class CBox : public ISceneObject
{
public:
    CBox(float posX, float posY, float posZ, float roation, glm::vec3 rotationAxis, float scale);
    ~CBox();
    void MandatoryFunc(){} //remove this shit
    const float*                    GetVertexBufferData() const { return mVertexBufferData; }
    const float*                    GetUVBufferData() const { return mUVBufferData; }
    const int*                      GetUVBufferDataSize() { return &mUVBufferDataSize; }
    const int*                      GetVertexBufferDataSize() { return &mVertexBufferDataSize; }

    const glm::vec3&                GetScale() const{ return mScale; }
    void                            SetScale(const glm::vec3 &scale);
    float                           GetRotation() const { return mRotation; }
    void                            SetRotation(float rotation, const glm::vec3 &rotationAxis);
    const glm::vec3&                GetRotationAxis() const { return mRotationAxis; }
    const glm::vec3&                GetTranslation() const { return mTranslation; }
    void                            SetTranslation(const glm::vec3 &translation);
    const glm::mat4&                GetModelMatrix() const { return mModelMatrix; }

    //reserach further the best returntype for getModelMatrix etc. Is
    //return by const reference really the best way to go?

private:

    glm::mat4                   mModelMatrix;
    glm::vec3                   mScale;
    float                       mRotation;
    glm::vec3                   mRotationAxis;
    glm::vec3                   mTranslation;
    float                       mVertexBufferData[108]; //this is kind of wierd, setting size like this
    int                         mVertexBufferDataSize;
    float                       mUVBufferData[72];
    int                         mUVBufferDataSize;
};

#endif
