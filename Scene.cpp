#include "Scene.h"

CScene::CScene( ) {



}

CScene::~CScene()
{
}

void CScene::Render()
{
}

void CScene::Update()
{
}

void CScene::AddSceneObject(ISceneObject *sceneObject)
{
    mSceneObjects.push_back(sceneObject);
}

void CScene::RemoveSceneObject()
{
}

void CScene::UpdateCamera()
{
}


