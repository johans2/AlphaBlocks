#ifndef _ALPHABLOCKS_BOX_H_
#define _ALPHABLOCKS_BOX_H_

#include "SceneObject.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>
#include <array>

class CBox : public ISceneObject
{
public:
    CBox(float posX, float posY, float posZ, float roation, glm::vec3 rotationAxis, float scale);
    ~CBox();
    void MandatoryFunc(){} //remove this shit
    const float*                    getVertexBufferData() const { return mVertexBufferData; }
    const float*                    getUVBufferData() const { return mUVBufferData; }
    const int*                      getUVBufferDataSize() { return &mUVBufferDataSize; }
    const int*                      getVertexBufferDataSize() { return &mVertexBufferDataSize; }

    const glm::vec3&                getScale() const{ return mScale; }
    void                            setScale(const glm::vec3 &scale);
    float                           getRotation() const { return mRotation; }
    void                            setRotation(float rotation, const glm::vec3 &rotationAxis);
    const glm::vec3&                getRotationAxis() const { return mRotationAxis; }
    const glm::vec3&                getTranslation() const { return mTranslation; }
    void                            setTranslation(const glm::vec3 &translation);
    const glm::mat4&                getModelMatrix() const { return mModelMatrix; }

    //reserach further the best returntype for getModelMatrix etc. Is
    //return by const reference really the best way to go?

private:
    glm::mat4                   mModelMatrix;
    glm::vec3                   mScale;
    float                       mRotation;
    glm::vec3                   mRotationAxis;
    glm::vec3                   mTranslation;
    float                       mVertexBufferData[108];
    int                         mVertexBufferDataSize;
    float                       mUVBufferData[72];
    int                         mUVBufferDataSize;
};

#endif
