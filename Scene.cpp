#include "Scene.h"

CScene::CScene(std::string sceneId, CCamera *camera) :
    mSceneId(sceneId),
    mCamera(camera)
{



}

CScene::~CScene()
{
    for(int i=0; i<mSceneObjects.size(); ++i){
        delete mSceneObjects[i];
    }
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
        //Crate and bind vertex buffer
        glGenBuffers(1, mSceneObjects[i]->GetVertexBuffer());
        glBindBuffer(GL_ARRAY_BUFFER, *mSceneObjects[i]->GetVertexBuffer());
        glBufferData(GL_ARRAY_BUFFER, *mSceneObjects[i]->GetVertexBufferDataSize(), &(mSceneObjects[i]->GetVertexBufferData())[0], GL_STATIC_DRAW);

        //Create and bind UV buffer
        glGenBuffers(1, mSceneObjects[i]->GetUVBuffer());
        glBindBuffer(GL_ARRAY_BUFFER, *mSceneObjects[i]->GetUVBuffer());
        glBufferData(GL_ARRAY_BUFFER, *mSceneObjects[i]->GetUVBufferDataSize(), &(mSceneObjects[i]->GetUVBufferData())[0], GL_STATIC_DRAW);

    }
}

void CScene::UnbindObjectBuffers()
{
    for(int i=0; i<mSceneObjects.size(); ++i){
        //Unbind the vertexdata and UVdata buffers
    }
}
