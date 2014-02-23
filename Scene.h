#ifndef _ALPHABLOCKS_SCENE_H_
#define _ALPHABLOCKS_SCENE_H_

#include "Camera.h"
#include "SceneObject.h"
#include <vector>
#include <string>

class CScene{
public:
    CScene(std::string sceneId, CCamera* camera);
    ~CScene();
    void                    Enter();
    void                    Exit();
    void                    Update();
    void                    AddSceneObject(ISceneObject* sceneObject);
    void                    RemoveSceneObject();
    const CCamera*          GetCamera() const{ return mCamera; }
    const std::string&      GetSceneId() const{ return mSceneId; }


private:
    void                            Render();
    void                            BindObjectBuffers();
    void                            UnbindObjectBuffers();
    std::string                     mSceneId;
    CCamera*                        mCamera;
    std::vector<ISceneObject*>      mSceneObjects;
};

#endif
