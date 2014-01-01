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
    float               getFow() const{ return mFow; }
    void                setFow(float value) {mFow = value; }
    float               getRatio() const { return mRatio; }
    void                setRatio(float value) { mRatio = value; }
    float               getClippingPlaneNear() const { return mClippingPlaneNear; }
    void                setClippingPlaneNear(float value) { mClippingPlaneNear = value; }
    float               getClippingPlaneFar() const { return mClippingPlaneFar; }
    void                setClippingPlaneFar(float value) { mClippingPlaneFar = value; }
    const glm::vec3&    getCameraPosWorldSpace() const { return mCameraPosWorldSpace; }
    void                setCameraPosWorldSpace(const glm::vec3 &value) { mCameraPosWorldSpace = value; }
    const glm::vec3&    getLookAtDirection() const { return mLookAtDirection; }
    void                setLookAtDirection(const glm::vec3 &value) { mLookAtDirection = value; }
    const glm::vec3&    getHeadDirection() const { return mHeadDirection; }
    void                setHeadDirection(const glm::vec3 &value) { mHeadDirection = value; }
    const glm::mat4&    getPerspective() const { return mPerspective; }
    const glm::mat4&    getView() const { return mView; }
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
