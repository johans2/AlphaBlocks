#ifndef _ALPHABLOCKS_SCENE_H_
#define _ALPHABLOCKS_SCENE_H_

#include "Camera.h"
#include "SceneObject.h"
#include <vector>

class CScene{
public:
    CScene();
    ~CScene();
    void        render();
    void        update();
    void        addSceneObject(ISceneObject* sceneObject){}
    void        removeSceneObject(){}
    CCamera*    getCamera(){return mCamera;}
    void        updateCamera(){}

private:
    CCamera*                        mCamera;
    std::vector<ISceneObject*>      mSceneObjects;
};

#endif
