#ifndef _ALPHABLOCKS_ISCENEOBJECT_H_
#define _ALPHABLOCKS_ISCENEOBJECT_H_

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>
#include <array>
#include <string>

// Include GLEW
#include <GL/glew.h>

// Include GLFW
#include <GL/glfw.h>

class ISceneObject{
public:
    virtual GLuint*                   GetVertexBuffer() = 0;
    virtual GLuint*                   GetUVBuffer() = 0;
    virtual const float*                    GetVertexBufferData() const = 0;
    virtual const float*                    GetUVBufferData() const = 0;
    virtual const int*                      GetUVBufferDataSize() = 0;
    virtual const int*                      GetVertexBufferDataSize() = 0;
    virtual const glm::vec3&                GetScale() const = 0;
    virtual void                            SetScale(const glm::vec3 &scale) = 0;
    virtual float                           GetRotation() const = 0;
    virtual void                            SetRotation(float rotation, const glm::vec3 &rotationAxis) = 0;
    virtual const glm::vec3&                GetRotationAxis() const = 0;
    virtual const glm::vec3&                GetTranslation() const = 0;
    virtual void                            SetTranslation(const glm::vec3 &translation) = 0;
    virtual const glm::mat4&                GetModelMatrix() const = 0;
};


#endif
