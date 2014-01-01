#include "Camera.h"



CCamera::CCamera(float fow, float ratio, float clippingPlaneNear, float clippingPlaneFar, glm::vec3 cameraPosWorldSpace, glm::vec3 lookAtDirection, glm::vec3 headDirection)
     :mFow(fow),
      mRatio(ratio),
      mClippingPlaneNear(clippingPlaneNear),
      mClippingPlaneFar(clippingPlaneFar),
      mCameraPosWorldSpace(cameraPosWorldSpace),
      mLookAtDirection(lookAtDirection),
      mHeadDirection(headDirection)
{
    mPerspective = glm::perspective(mFow, mRatio, mClippingPlaneNear, mClippingPlaneFar); //rename projection?
    mView = glm::lookAt(mCameraPosWorldSpace, mLookAtDirection, mHeadDirection);
}

CCamera::~CCamera(){

}

void CCamera::UpdateCamera(){
    mPerspective = glm::perspective(mFow, mRatio, mClippingPlaneNear, mClippingPlaneFar);
    mView = glm::lookAt(mCameraPosWorldSpace, mLookAtDirection, mHeadDirection);
}


