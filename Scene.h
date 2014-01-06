#ifndef _ALPHABLOCKS_SCENE_H_
#define _ALPHABLOCKS_SCENE_H_

#include "Camera.h"
#include "SceneObject.h"
#include <vector>
#include <string>

class CScene{
public:
    CScene();
    ~CScene();
    void                    Render();
    void                    Update();
    void                    AddSceneObject(ISceneObject* sceneObject);
    void                    RemoveSceneObject();
    CCamera*                GetCamera(){return mCamera;}
    void                    UpdateCamera();
    const std::string&      GetSceneId() const{ return mSceneId; }

private:
    std::string                     mSceneId;
    CCamera*                        mCamera;
    std::vector<ISceneObject*>      mSceneObjects;
};

#endif
