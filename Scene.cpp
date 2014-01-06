#include "Scene.h"

CScene::CScene(std::string sceneId ) :
    mSceneId(sceneId)
{



}

CScene::~CScene()
{
}

void CScene::Enter()
{
    BindObjectBuffers();
    Render();
}

void CScene::Exit()
{
    UnbindObjectBuffers();
    //unbind all the buffers
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

void CScene::Render()
{
    //render the now bound sceneobjects
}

void CScene::BindObjectBuffers()
{
    for(int i=0; i<mSceneObjects.size(); ++i){
        //Crate and bind the vertexdata and UVdata buffers
    }
}

void CScene::UnbindObjectBuffers()
{
    for(int i=0; i<mSceneObjects.size(); ++i){
        //Unbind the vertexdata and UVdata buffers
    }
}
