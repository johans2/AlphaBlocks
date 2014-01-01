#ifndef _ALPHABLOCKS_GAME_H_
#define _ALPHABLOCKS_GAME_H_

#include <vector>
#include "Scene.h"

class ISceneObject;

class CGame{
public:
    CGame();
    ~CGame();
    void Update();
    void RenderScene(CScene* scene);
    void addScene(CScene*);
    void removeScene(CScene*);
    void setCurrentScene();
private:
    std::vector<CScene*>    mScenes;
    CScene*                 mCurrentScene;
};

#endif
