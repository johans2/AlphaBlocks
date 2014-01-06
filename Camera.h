#ifndef _ALPHABLOCKS_CAMERA_H_
#define _ALPHABLOCKS_CAMERA_H_
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class CCamera
{
public:
    CCamera(float fow,
            float ratio,
            float clippingPlaneNear,
            float clippingPlaneFar,
            glm::vec3 cameraPosWorldSpace,
            glm::vec3 lookAtDirection,
            glm::vec3 headDirection
            );

    ~CCamera();
    float               GetFow() const{ return mFow; }
    void                SetFow(float value) {mFow = value; }
    float               GetRatio() const { return mRatio; }
    void                SetRatio(float value) { mRatio = value; }
    float               GetClippingPlaneNear() const { return mClippingPlaneNear; }
    void                SetClippingPlaneNear(float value) { mClippingPlaneNear = value; }
    float               GetClippingPlaneFar() const { return mClippingPlaneFar; }
    void                SetClippingPlaneFar(float value) { mClippingPlaneFar = value; }
    const glm::vec3&    GetCameraPosWorldSpace() const { return mCameraPosWorldSpace; }
    void                SetCameraPosWorldSpace(const glm::vec3 &value) { mCameraPosWorldSpace = value; }
    const glm::vec3&    GetLookAtDirection() const { return mLookAtDirection; }
    void                SetLookAtDirection(const glm::vec3 &value) { mLookAtDirection = value; }
    const glm::vec3&    GetHeadDirection() const { return mHeadDirection; }
    void                SetHeadDirection(const glm::vec3 &value) { mHeadDirection = value; }
    const glm::mat4&    GetPerspective() const { return mPerspective; }
    const glm::mat4&    GetView() const { return mView; }
    void                UpdateCamera();

private:
    float       mFow;
    float       mRatio;
    float       mClippingPlaneNear;
    float       mClippingPlaneFar;
    glm::vec3   mCameraPosWorldSpace;
    glm::vec3   mLookAtDirection;
    glm::vec3   mHeadDirection;

    glm::mat4       mPerspective;
    glm::mat4       mView;
};

#endif
